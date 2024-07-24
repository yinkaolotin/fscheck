#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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

    int opt;
    while((opt = getopt(argc, argv, EXPECTED_OPTS_FMT)) != -1) {
        switch(opt) {
        case OPT_AGGREGATE:
            c->flags |= FLAG_AGGREGATE_INFO;
            printf("displaying aggregate information....\n");
            return c;
        case OPTS_UNKNOWN: EXCEPTION_AND_EXIT("Usage: %s <directory> [-a]\n", argv[0]);
        }
    }
    return c;
}
