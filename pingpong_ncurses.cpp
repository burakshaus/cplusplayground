#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>

int main() {
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    int max_y = 0, max_x = 0;
    getmaxyx(stdscr, max_y, max_x);

    int ball_y = max_y / 2, ball_x = max_x / 2;
    int ball_dy = 1, ball_dx = 1;
    
    int paddle1_y = max_y / 2 - 2, paddle1_x = 2;
    int paddle2_y = max_y / 2 - 2, paddle2_x = max_x - 3;
    int paddle_len = 5;

    int score1 = 0, score2 = 0;

    while(true) {
        clear();
        
        // Draw dividing line
        for(int i = 0; i < max_y; i++) {
            if (i % 2 == 0) {
                mvprintw(i, max_x / 2, "|");
            }
        }
        
        // draw paddles
        for(int i = 0; i < paddle_len; i++) {
            mvprintw(paddle1_y + i, paddle1_x, "]");
            mvprintw(paddle2_y + i, paddle2_x, "[");
        }
        
        // draw ball
        mvprintw(ball_y, ball_x, "O");

        // draw score
        mvprintw(0, max_x / 2 - 7, " P1: %d ", score1);
        mvprintw(0, max_x / 2 + 1, " P2: %d ", score2);
        
        mvprintw(max_y - 1, 0, "Press 'q' to quit. P1: W/S, P2: UP/DOWN");

        refresh();
        usleep(50000); // 50ms delay

        int ch = getch();
        if (ch == 'q') {
            break;
        }
        switch(ch) {
            case 'w':
                if (paddle1_y > 0) paddle1_y--;
                break;
            case 's':
                if (paddle1_y + paddle_len < max_y) paddle1_y++;
                break;
            case KEY_UP:
                if (paddle2_y > 0) paddle2_y--;
                break;
            case KEY_DOWN:
                if (paddle2_y + paddle_len < max_y) paddle2_y++;
                break;
        }

        ball_y += ball_dy;
        ball_x += ball_dx;

        // Wall collision
        if (ball_y <= 0 || ball_y >= max_y - 1) {
            ball_dy = -ball_dy;
            if (ball_y < 0) ball_y = 0;
            if (ball_y >= max_y) ball_y = max_y - 1;
        }

        // Paddle collision
        if (ball_x == paddle1_x + 1 && ball_y >= paddle1_y && ball_y < paddle1_y + paddle_len) {
            ball_dx = -ball_dx;
        }
        if (ball_x == paddle2_x - 1 && ball_y >= paddle2_y && ball_y < paddle2_y + paddle_len) {
            ball_dx = -ball_dx;
        }

        // Scoring
        if (ball_x < 0) {
            score2++;
            ball_y = max_y / 2;
            ball_x = max_x / 2;
            ball_dx = 1;
        }
        if (ball_x > max_x) {
            score1++;
            ball_y = max_y / 2;
            ball_x = max_x / 2;
            ball_dx = -1;
        }
    }

    endwin();
    return 0;
}
