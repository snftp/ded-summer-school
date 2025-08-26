#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int main() {
    //struct termios old, raw;
    //tcgetattr(STDIN_FILENO, &old);
    //raw = old;
    //cfmakeraw(&raw);
    //tcsetattr(STDIN_FILENO, TCSANOW, &raw);

    while (true) {
        int value = getchar();
        if (value == EOF)
            break;

        printf("'%c' (%d)\n", value, value);
    }
}
