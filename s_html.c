#include "s_html.h"
#include "html.h"

void source_to_html(FILE *dest, Event *ev) {
    // Map FSM token types to CSS classes
    switch(ev->type) {
        case P_SINGLE_COMMENT:
        case P_MULTI_COMMENT:
            fprintf(dest, "<span class=\"comment\">");
            break;
        case P_PREPROCESSOR:
            fprintf(dest, "<span class=\"preprocessor\">");
            break;
        case P_STRING:
        case P_CHAR:
            fprintf(dest, "<span class=\"string\">");
            break;
        case P_KEYWORD:
            fprintf(dest, "<span class=\"keyword\">");
            break;
        case P_NUMBER:
            fprintf(dest, "<span class=\"numeric\">");
            break;
        case P_NORMAL:
        default:
            fprintf(dest, "<span class=\"normal\">");
            break;
    }
    
    print_escaped(dest, ev->data);
    fprintf(dest, "</span>");
}