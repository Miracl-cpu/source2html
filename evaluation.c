#include "header.h"
#include "s_html.h"

void do_evaluation(FILE *src, FILE *dest) {
    Event ev;
    
    // Core engine loop: Fetch tokens until EOF, then map to HTML
    while (1) {
        ev = get_parser_event(src);
        if (ev.type == P_EOF) {
            break;
        }
        source_to_html(dest, &ev);
    }
}