#define _XOPEN_SOURCE 500
#include <stdio.h>
#include "parser/parser.h"
#include "exception/exception.h"
#include "info/info.h"

int main(int argc, char *argv[])
{
    const struct cmd *c = parse_cmd(argc, argv);
    printf(INFO_FMT_STR, "TYPE", "LVL", "SIZE", "FULL PATH", "BASE");
    if (nftw(argv[1], fs_checker, MAX_PARALLEL_FD, DEFAULT_WALK) == -1) {
        EXCEPTION_AND_EXIT("nftw");
    }
    free(c->directory);
    free((void *)c);
    exit(EXIT_SUCCESS);
}