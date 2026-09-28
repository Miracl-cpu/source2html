#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUF 1024

// FSM Event Types
typedef enum {
    P_IDLE,
    P_SINGLE_COMMENT,
    P_MULTI_COMMENT,
    P_PREPROCESSOR,
    P_STRING,
    P_CHAR,
    P_NUMBER,
    P_KEYWORD,
    P_NORMAL,
    P_EOF
} EventType;

// Event Structure passed between Parser and HTML mapper
typedef struct {
    EventType type;
    char data[MAX_BUF];
    int length;
} Event;

// Function Prototypes
Event get_parser_event(FILE *src);
void do_evaluation(FILE *src, FILE *dest);

#endif