#ifndef PARSER_H
#define PARSER_H

struct cmd {
    char *directory;
};

const struct cmd *parse_cmd(int argc, char *argv[]);

#endif