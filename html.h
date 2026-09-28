#ifndef HTML_H
#define HTML_H
#include "header.h"

void html_begin(FILE *dest);
void html_end(FILE *dest);
void print_escaped(FILE *dest, const char *str);

#endif