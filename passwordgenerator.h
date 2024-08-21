#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H
#include <stdint.h>

char *generate_password(uint32_t length, bool letters, bool digits, bool characters); // Generates password with specified options
#endif