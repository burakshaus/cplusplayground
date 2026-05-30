#include <SFML/Graphics.hpp>
#include <iostream>


const int WIDTH = 800;
const int HEIGHT = 600;


struct Paddle {
    sf::RectangleShape shape;
    float speed = 6.0f;
};

struct Ball {
    sf::CircleShape shape;
    sf::Vector2f velocity;
    float speed = 5.0f;
};

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "C++ Pong Game");
    window.setFramerateLimit(60);

    
    Paddle leftPaddle;
    leftPaddle.shape.setSize(sf::Vector2f(20, 100));
    leftPaddle.shape.setFillColor(sf::Color::White);
    leftPaddle.shape.setPosition(30, HEIGHT / 2 - 50);

    
    Paddle rightPaddle;
    rightPaddle.shape.setSize(sf::Vector2f(20, 100));
    rightPaddle.shape.setFillColor(sf::Color::White);
    rightPaddle.shape.setPosition(WIDTH - 50, HEIGHT / 2 - 50);

    
    Ball ball;
    ball.shape.setRadius(12);
    ball.shape.setFillColor(sf::Color::White);
    ball.shape.setOrigin(12, 12); 
    ball.shape.setPosition(WIDTH / 2, HEIGHT / 2);
    ball.velocity = sf::Vector2f(ball.speed, ball.speed);

    
    int leftScore = 0;
    int rightScore = 0;


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && leftPaddle.shape.getPosition().y > 0) {
            leftPaddle.shape.move(0, -leftPaddle.speed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && leftPaddle.shape.getPosition().y < HEIGHT - 100) {
            leftPaddle.shape.move(0, leftPaddle.speed);
        }

        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && rightPaddle.shape.getPosition().y > 0) {
            rightPaddle.shape.move(0, -rightPaddle.speed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && rightPaddle.shape.getPosition().y < HEIGHT - 100) {
            rightPaddle.shape.move(0, rightPaddle.speed);
        }

        
        ball.shape.move(ball.velocity);

        
        if (ball.shape.getPosition().y - 12 < 0 || ball.shape.getPosition().y + 12 > HEIGHT) {
            ball.velocity.y = -ball.velocity.y; 
        }

        
        
        if (ball.shape.getGlobalBounds().intersects(leftPaddle.shape.getGlobalBounds())) {
            ball.velocity.x = -ball.velocity.x;
            ball.shape.setPosition(leftPaddle.shape.getPosition().x + 20 + 12, ball.shape.getPosition().y); 
        }

        
        if (ball.shape.getGlobalBounds().intersects(rightPaddle.shape.getGlobalBounds())) {
            ball.velocity.x = -ball.velocity.x;
            ball.shape.setPosition(rightPaddle.shape.getPosition().x - 12, ball.shape.getPosition().y); 
        }

        
        if (ball.shape.getPosition().x < 0) {
            rightScore++;
            std::cout << "Score -> P1: " << leftScore << " | P2: " << rightScore << "\n";
            ball.shape.setPosition(WIDTH / 2, HEIGHT / 2);
            ball.velocity.x = ball.speed; 
        }
        if (ball.shape.getPosition().x > WIDTH) {
            leftScore++;
            std::cout << "Score -> P1: " << leftScore << " | P2: " << rightScore << "\n";
            ball.shape.setPosition(WIDTH / 2, HEIGHT / 2);
            ball.velocity.x = -ball.speed; 
        }

        window.clear(sf::Color::Black);

        window.draw(leftPaddle.shape);
        window.draw(rightPaddle.shape);
        window.draw(ball.shape);

        window.display();
    }

    return 0;
}
