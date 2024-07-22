#ifndef INFO_H
#define INFO_H

#define _XOPEN_SOURCE 500

#define DEFAULT_WALK 0
#define MAX_PARALLEL_FD 20
#define INFO_FMT "%-4s %-3d %-7lld   %-70s %s\n"
#define INFO_FMT_STR "%-4s %-3s %-7s   %-70s %s\n"
#define HEADER_COLOR "\x1b[1m\x1b[36m"
#define DEFAULT_COLOR "\x1b[0m"

#include <ftw.h>
#include <sys/stat.h>

const char *get_file_type(int file_type);

int fs_checker(const char *full_path,
                    const struct stat *stat_buf,
                    int file_type,
                    struct FTW *file_tree_walk_buf);

#endif