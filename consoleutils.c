#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

void set_color(int color)
{
    printf("\033[0%um", color);
}

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
void clear_screen()
{
    system("cls");
}
#else
void clear_screen()
{
    system("clear");
}
#endif

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
// Windows-specific implementation
char getch(void)
{
    return _getch();
}
#else
// Unix-like implementation
char getch(void)
{
    struct termios oldt, newt;
    char ch;

    tcgetattr(STDIN_FILENO, &oldt); // Get current terminal settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);        // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply new settings

    ch = getchar(); // Read a single character

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore old terminal settings

    return ch;
}
#endif
