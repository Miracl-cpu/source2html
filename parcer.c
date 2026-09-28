#include "header.h"
#include "keyword.h"

Event get_parser_event(FILE *src) {
    Event ev;
    ev.length = 0;
    ev.data[0] = '\0';
    ev.type = P_EOF;
    
    int c = fgetc(src);
    if (c == EOF) {
        return ev;
    }
    
    // Store character safely in buffer
    #define STORE(ch) if (ev.length < MAX_BUF - 1) ev.data[ev.length++] = (ch)

    if (c == '/') {
        int next = fgetc(src);
        if (next == '/') {
            ev.type = P_SINGLE_COMMENT;
            STORE(c); STORE(next);
            while ((c = fgetc(src)) != EOF && c != '\n') {
                STORE(c);
            }
            if (c == '\n') STORE(c);
        } else if (next == '*') {
            ev.type = P_MULTI_COMMENT;
            STORE(c); STORE(next);
            int prev = 0;
            while ((c = fgetc(src)) != EOF) {
                STORE(c);
                if (prev == '*' && c == '/') break;
                prev = c;
            }
        } else {
            if (next != EOF) ungetc(next, src);
            ev.type = P_NORMAL;
            STORE(c);
        }
    } else if (c == '#') {
        ev.type = P_PREPROCESSOR;
        STORE(c);
        while ((c = fgetc(src)) != EOF && c != '\n') {
            STORE(c);
        }
        if (c == '\n') STORE(c);
    } else if (c == '"' || c == '\'') {
        char quote = c;
        ev.type = (quote == '"') ? P_STRING : P_CHAR;
        STORE(c);
        int escaped = 0;
        while ((c = fgetc(src)) != EOF) {
            STORE(c);
            if (c == quote && !escaped) break;
            escaped = (c == '\\' && !escaped);
        }
    } else if (isalpha(c) || c == '_') {
        STORE(c);
        while ((c = fgetc(src)) != EOF && (isalnum(c) || c == '_')) {
            STORE(c);
        }
        if (c != EOF) ungetc(c, src);
        ev.data[ev.length] = '\0';
        ev.type = is_keyword(ev.data) ? P_KEYWORD : P_NORMAL;
    } else if (isdigit(c)) {
        ev.type = P_NUMBER;
        STORE(c);
        while ((c = fgetc(src)) != EOF && (isalnum(c) || c == '.')) {
            STORE(c);
        }
        if (c != EOF) ungetc(c, src);
    } else {
        ev.type = P_NORMAL;
        STORE(c);
    }
    
    ev.data[ev.length] = '\0';
    return ev;
}