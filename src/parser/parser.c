#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "parser/parser.h"
#include "exception/exception.h"


const struct cmd *parse_cmd(int argc, char *argv[])
{
    if (argc < 2) {
        EXCEPTION_AND_EXIT(USAGE_EXCEPTION, argv[0]);
    }
    if (strcmp(argv[1], "/") == 0) {
        EXCEPTION_AND_EXIT(FS_EXCEPTION);
    }
    struct cmd *c = (struct cmd *)calloc(1, sizeof(struct cmd));
    if (c == NULL) {
        EXCEPTION_AND_EXIT(PARSE_EXCEPTION);
    }
    c->directory = strdup(argv[1]);
    return c;
}