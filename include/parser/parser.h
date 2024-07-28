#ifndef PARSER_H
#define PARSER_H

#define EXPECTED_OPTS_FMT "as"
#define OPT_AGGREGATE 'a'
#define OPT_STATISTICS 's'
#define OPTS_UNKNOWN '?'

#define FLAG_DEFAULT_INFO 0x01
#define FLAG_AGGREGATE_INFO 0x02
#define FLAG_SHOW_STATISTICS 0x03

struct cmd {
    char *directory;
    unsigned int flags;
};

const struct cmd *parse_cmd(int argc, char *argv[]);

#endif