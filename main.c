#include "header.h"
#include "html.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./source2html.out <file.c>\n");
        return 1;
    }
    
    FILE *src = fopen(argv[1], "r");
    if (!src) {
        printf("Error: Could not open %s\n", argv[1]);
        return 1;
    }
    
    FILE *dest = fopen("output.html", "w");
    if (!dest) {
        printf("Error: Could not create output.html\n");
        fclose(src);
        return 1;
    }
    
    html_begin(dest);
    do_evaluation(src, dest);
    html_end(dest);
    
    fclose(src);
    fclose(dest);
    
    printf("Successfully converted %s to output.html\n", argv[1]);
    return 0;
}