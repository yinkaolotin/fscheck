#define _XOPEN_SOURCE 500
#include <ftw.h>
#include <sys/stat.h>
#include <stdio.h>
#include "info/info.h"

const char *get_file_type(int file_type)
{
    switch(file_type) {
        case FTW_D: return "d";
        case FTW_DNR: return "dnr";
        case FTW_DP: return "dp";
        case FTW_F: return "f";
        case FTW_NS: return "ns";
        case FTW_SL: return "sl";
        case FTW_SLN: return "sln";
    }
    return "???";
}

int fs_checker(const char *full_path,
                    const struct stat *stat_buf,
                    int file_type,
                    struct FTW *file_tree_walk_buf)
{
    printf(INFO_FMT, get_file_type(file_type),
        file_tree_walk_buf->level,
        (long long)stat_buf->st_size,
        full_path, 
        full_path + file_tree_walk_buf->base);
    return 0;
}