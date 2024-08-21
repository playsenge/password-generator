#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include "consoleutils.h"
#include "passwordgenerator.h"

#define enabled_marker(var) \
    if (var)                \
    {                       \
        set_color(GREEN);   \
        printf("[+] ");     \
    }                       \
    else                    \
    {                       \
        set_color(RED);     \
        printf("[-] ");     \
    }

int main(void);

uint32_t length = 8;

bool letters = true;
bool digits = true;
bool characters = false;

bool refresh = true;

void print_menu(void)
{
    clear_screen();

    set_color(BRIGHT_YELLOW);
    (void)printf("Welcome to Password Generator!\n");

    set_color(BRIGHT_BLUE);
    (void)printf("Current length: ");

    set_color(WHITE);
    (void)printf("%u\n", length);

    set_color(CYAN);
    (void)printf("Increment the length with + and - keys...\n");

    (void)printf("\n");

    enabled_marker(letters);
    (void)printf("Letters (toggle with L)\n");

    enabled_marker(digits);
    (void)printf("Digits (toggle with D)\n");

    enabled_marker(characters);
    (void)printf("Characters (toggle with C)\n");

    (void)printf("\n");

    bool can_build = letters || characters || digits;
    if (can_build)
    {
        set_color(BRIGHT_GREEN);
        (void)printf("Press G to generate!\n");
    }
    else
    {
        set_color(BRIGHT_RED);
        (void)printf("Select at least one category of characters.");
    }

    char in = getch();

    switch (in)
    {
    case '+':
        if (length < 64)
            length++;
        break;
    case '-':
        if (length > 4)
            length--;
        break;
    case 'l':
        letters = !letters;
        break;
    case 'd':
        digits = !digits;
        break;
    case 'c':
        characters = !characters;
        break;
    case 'g':
        if (!can_build)
            break;

        refresh = false;
        break;
    }
}

void view_password(char *password)
{
    clear_screen();

    set_color(WHITE);
    printf("Your password is ");

    set_color(BRIGHT_GREEN);
    printf("%s\n", password);

    free(password);

    set_color(RED);
    printf("Press any key to return to the home screen...");

    getch();

    clear_screen();

    refresh = true;
    (void)main();
}

int main(void)
{
    while (refresh)
        print_menu();

    view_password(generate_password(length, letters, digits, characters));

    return 0;
}