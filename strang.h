#include <stdio.h>
#include <stdlib.h>
#define CONST_FOUR_BYTE 4
#define CONST_ASCII_a 97
#define CONST_ASCII_z 122
#define CONST_ASCII_Z 90
#define CONST_ASCII_A 65
#define CONST_ASCII_DIF 32
#define CONST_MENU_CHOICE_7  7


int stringLenght(char* string);

void stringCopy(char* stringOrg, char* stringNew);

char* stringAdd(char* stringOrg, char* stringNew);

char charLowerToUpper(char lower);

char *stringLowerToUpper(char* string);

int stringCompare(char* firstString, char* secoundString);

char * stringShift(char* string, int userChoice);

char* stringReverse(char* string);