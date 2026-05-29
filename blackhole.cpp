#include <iostream>
#include <vector>
#include <cmath>
#include <thread>
#include <chrono>
#include <random>

using namespace std;

const int WIDTH = 100;
const int HEIGHT = 40;
const double DT = 0.05;
const double GM = 1500.0;
const double RS = 6.0;

struct Particle {
    double x, y;
    double vx, vy;
    bool active;
    char symbol;
    string color;
};

void setCursorPosition(int x, int y) {
    cout << "\033[" << y << ";" << x << "H";
}

int main() {
    vector<Particle> particles;
    mt19937 rng(42);
    uniform_real_distribution<double> dist_r(RS * 1.5, 50.0);
    uniform_real_distribution<double> dist_angle(0.0, 2 * M_PI);
    uniform_real_distribution<double> dist_v_noise(-0.2, 0.2);

    string colors[] = {
        "\033[31m", // Red
        "\033[33m", // Yellow
        "\033[36m", // Cyan
        "\033[35m", // Magenta
        "\033[93m", // Bright Yellow
        "\033[91m"  // Bright Red
    };

    // Initialize particles representing matter swirling around
    for (int i = 0; i < 600; ++i) {
        double r = dist_r(rng);
        double angle = dist_angle(rng);
        
        // Circular orbit velocity approximating Paczynski-Wiita potential
        double v = std::sqrt(GM * r) / (r - RS);
        v *= (1.0 + dist_v_noise(rng)); // Add noise to make orbits elliptical

        Particle p;
        p.x = r * cos(angle);
        p.y = r * sin(angle);
        // Tangential velocity
        p.vx = -v * sin(angle);
        p.vy = v * cos(angle);
        p.active = true;
        
        char symbols[] = {'.', '*', '+', 'x', ',', '~'};
        p.symbol = symbols[rng() % 6];
        p.color = colors[rng() % 6];
        
        particles.push_back(p);
    }

    cout << "\033[2J"; // Clear entire screen
    
    // Double buffer logic array
    vector<vector<string>> screen(HEIGHT, vector<string>(WIDTH, " "));
    int frames = 0;
    
    // Disable cursor so it doesn't flicker during drawing
    cout << "\033[?25l";

    while (true) {
        // 1. Clear logic screen for this frame
        for (int i = 0; i < HEIGHT; ++i) {
            for (int j = 0; j < WIDTH; ++j) {
                screen[i][j] = " ";
            }
        }

        // 2. Draw Black Hole Event Horizon
        for (int y = -RS; y <= RS; ++y) {
            for (int x = -RS*2; x <= RS*2; ++x) {
                double r = sqrt(x*x/4.0 + y*y); // x/2 scaling for terminal aspect ratio
                if (r <= RS) {
                    int sx = WIDTH / 2 + x;
                    int sy = HEIGHT / 2 + y;
                    if (sx >= 0 && sx < WIDTH && sy >= 0 && sy < HEIGHT) {
                        screen[sy][sx] = "\033[40m \033[0m"; // Pure black space
                    }
                }
            }
        }
        
        // 3. Draw photon sphere boundary
        for (int i = 0; i < 360; i += 2) {
            double rad = i * M_PI / 180.0;
            double r_photon = RS * 1.5;
            int sx = WIDTH / 2 + (int)(r_photon * 2.0 * cos(rad));
            int sy = HEIGHT / 2 + (int)(r_photon * sin(rad));
            if (sx >= 0 && sx < WIDTH && sy >= 0 && sy < HEIGHT && screen[sy][sx] == " ") {
                screen[sy][sx] = "\033[90m:\033[0m";
            }
        }

        // 4. Update and draw particles (matter)
        int active_count = 0;
        for (auto& p : particles) {
            if (!p.active) continue;

            double r = sqrt(p.x * p.x + p.y * p.y);
            
            // Check if swallowed by the event horizon
            if (r <= RS) {
                p.active = false; 
                continue;
            }
            active_count++;

            // Physics calculation (Paczynski-Wiita pseudo-Newtonian potential)
            double a = GM / ((r - RS) * (r - RS));
            double ax = -a * (p.x / r);
            double ay = -a * (p.y / r);

            // Euler integration
            p.vx += ax * DT;
            p.vy += ay * DT;
            p.x += p.vx * DT;
            p.y += p.vy * DT;

            // Map continuous space to discrete terminal cells
            int sx = WIDTH / 2 + (int)(p.x * 2.0); 
            int sy = HEIGHT / 2 + (int)(p.y);

            if (sx >= 0 && sx < WIDTH && sy >= 0 && sy < HEIGHT) {
                if (screen[sy][sx] == " " || screen[sy][sx] == "\033[90m:\033[0m") {
                    string s = "";
                    s += p.symbol;
                    // Add color code and the particle symbol
                    screen[sy][sx] = p.color + s + "\033[0m";
                }
            }
        }

        // 5. Output the completed frame to stdout
        setCursorPosition(1, 1);
        string frame_output;
        for (int i = 0; i < HEIGHT; ++i) {
            for (int j = 0; j < WIDTH; ++j) {
                frame_output += screen[i][j];
            }
            frame_output += "\n";
        }
        cout << frame_output;
        
        // Draw HUD overlay
        cout << "\033[36m--- TERMINAL BLACK HOLE SIMULATOR ---\033[0m\n";
        cout << "Matter in orbit: " << active_count << " / " << particles.size() 
             << " | Simulation Time: " << (frames * DT) << " \n";
        cout << "Press Ctrl+C to exit...\n";

        if (active_count == 0) {
            cout << "\n\033[31mAll matter has been consumed by the singularity.\033[0m\n";
            break;
        }

        // 6. Wait to cap the frame rate
        this_thread::sleep_for(chrono::milliseconds(40));
        frames++;
    }

    // Re-enable cursor before exiting
    cout << "\033[?25h";
    return 0;
}
