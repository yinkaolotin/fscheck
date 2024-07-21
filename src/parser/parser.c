#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "parser/parser.h"


const struct cmd *parse_cmd(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <starting-dir>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (strcmp(argv[1], "/") == 0) {
        fprintf(stderr,
        "Cannot check whole file system %s, "
        "please specify an inner directory instead e.g "
        "/home, /home/Documents \n", argv[1]);
        exit(EXIT_FAILURE);
    }
    struct cmd *c = (struct cmd *)calloc(1, sizeof(struct cmd));
    if (c == NULL) {
        fprintf(stderr, "failed to parse commmand %s\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    c->directory = strdup(argv[1]);
    return c;
}