#include "keyword.h"
#include <string.h>

const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while",
    "uint8_t", "uint16_t", "uint32_t", "int8_t", "int16_t", "int32_t"
};

int is_keyword(const char *str) {
    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);
    for(int i = 0; i < num_keywords; i++) {
        if(strcmp(str, keywords[i]) == 0) return 1;
    }
    return 0;
}