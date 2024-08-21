#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "lib/csprng.h"

#define LETTERS "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm"
#define DIGITS "0123456789"
#define CHARACTERS "!@#$%^&*()"

char *generate_password(uint32_t length, bool letters, bool digits, bool characters)
{
    CSPRNG csprng = csprng_create();

    size_t allocated = 1;
    if (letters)
        allocated += strlen(LETTERS);
    if (digits)
        allocated += strlen(DIGITS);
    if (characters)
        allocated += strlen(CHARACTERS);

    char symbols[allocated];
    strcpy(symbols, "");

    if (letters)
        strcat(symbols, LETTERS);
    if (digits)
        strcat(symbols, DIGITS);
    if (characters)
        strcat(symbols, CHARACTERS);

    symbols[allocated - 1] = '\0';

    char *password = malloc(length + 1 * sizeof(char));

    for (size_t i = 0; i < length; i++)
    {
        password[i] = symbols[csprng_get_int(csprng) % (allocated - 1)];
    }

    password[length] = '\0';

    return password;
}