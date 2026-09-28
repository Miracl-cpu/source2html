#include "html.h"

void html_begin(FILE *dest) {
    fprintf(dest, "<!DOCTYPE html>\n<html>\n<head>\n<style>\n");
    
    // Global editor window style
    fprintf(dest, "body { background-color: #282a36; color: #f8f8f2; font-family: 'Consolas', monospace; padding: 30px; }\n");
    fprintf(dest, "pre { background-color: #1e1f29; padding: 20px; border-radius: 8px; border: 1px solid #44475a; box-shadow: 0 4px 6px rgba(0,0,0,0.3); font-size: 15px; line-height: 1.5; }\n");
    
    // Granular Syntax Colors (Dracula Theme inspired)
    fprintf(dest, ".comment { color: #6272a4; font-style: italic; }\n");
    fprintf(dest, ".preprocessor { color: #ff79c6; }\n");
    fprintf(dest, ".string { color: #f1fa8c; }\n");
    fprintf(dest, ".numeric { color: #bd93f9; }\n");
    
    // Split keywords into multiple styles
    fprintf(dest, ".kw-control { color: #ff79c6; font-weight: bold; }\n"); /* if, return, while */
    fprintf(dest, ".kw-type { color: #8be9fd; font-style: italic; }\n");   /* int, float, uint32_t */
    
    // Functions and Macros
    fprintf(dest, ".function { color: #50fa7b; }\n"); 
    
    fprintf(dest, "</style>\n</head>\n<body>\n<pre>\n");
}

void html_end(FILE *dest) {
    fprintf(dest, "</pre>\n</body>\n</html>\n");
}

// Converts C reserved characters to HTML entities
void print_escaped(FILE *dest, const char *str) {
    while (*str) {
        if (*str == '<') fprintf(dest, "&lt;");
        else if (*str == '>') fprintf(dest, "&gt;");
        else if (*str == '&') fprintf(dest, "&amp;");
        else fputc(*str, dest);
        str++;
    }
}