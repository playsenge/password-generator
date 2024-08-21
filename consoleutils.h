#ifndef CONSOLEUTILS_H
#define CONSOLEUTILS_H

#define BLACK 30
#define BRIGHT_BLACK 90
#define RED 31
#define BRIGHT_RED 91
#define GREEN 32
#define BRIGHT_GREEN 92
#define YELLOW 33
#define BRIGHT_YELLOW 93
#define BLUE 34
#define BRIGHT_BLUE 94
#define MAGENTA 35
#define BRIGHT_MAGENTA 95
#define CYAN 36
#define BRIGHT_CYAN 96
#define WHITE 37
#define BRIGHT_WHITE 97

void set_color(int color); // Prints the corresponding ANSI escape sequence to set a color in the terminal
void clear_screen(void);   // Clears the screen
char getch(void);          // Read character from user
#endif
