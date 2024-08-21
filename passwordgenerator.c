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

    size_t allocated = 1; // Room for '\0'
    if (letters)
        allocated += strlen(LETTERS);
    if (digits)
        allocated += strlen(DIGITS);
    if (characters)
        allocated += strlen(CHARACTERS);

    char symbols[allocated];
    strncpy(symbols, "", 1);

    if (letters)
        strcat(symbols, LETTERS);
    if (digits)
        strcat(symbols, DIGITS);
    if (characters)
        strcat(symbols, CHARACTERS);

    symbols[allocated - 1] = '\0';

    char *password = malloc(length + 1 * sizeof(char));

    if (password == NULL)
    {
        char *error = malloc(100);
        sprintf(error, "Error. Are you sure your computer has %u bytes of RAM?", length);
        return error;
    }

    for (size_t i = 0; i < length; i++)
    {
        password[i] = symbols[csprng_get_int(csprng) % (allocated - 1)];
    }

    password[length] = '\0';

    return password;
}
