#define _XOPEN_SOURCE 500
#include <ftw.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include "parser/parser.h"
#include "info/info.h"
#include "exception/exception.h"

static int file_count = 0;

static FileMeta file_meta_storage[MAX_FILES_READABLE];
static DirectoryStats directory_stats_storage[MAX_FILES_READABLE];
static FileTypeStats file_type_stats_storage[MAX_FILE_TYPES] = {
    {"d", 0, 0},
    {"dnr", 0, 0},
    {"dp", 0, 0},
    {"f", 0, 0},
    {"ns", 0, 0},
    {"sl", 0, 0},
    {"sln", 0, 0},
    {"???", 0, 0},
};

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

int scrape_file_meta(const char *full_path,
                    const struct stat *stat_buf,
                    int file_type,
                    struct FTW *file_tree_buf)
{
    if (file_count >= MAX_FILES_READABLE) {
        EXCEPTION_AND_RETURN(1, "Maximum file limit reached\n");
    }

    FileMeta *fm = &file_meta_storage[file_count];
    file_count++;

    strncpy(fm->path, full_path, MAX_PATH_LENGTH - 1);
    fm->path[MAX_PATH_LENGTH - 1] = '\0';

    fm->type = get_file_type(file_type);
    fm->size = stat_buf->st_size;

    fm->tree_lvl = file_tree_buf->level;
    fm->file_name_idx = file_tree_buf->base;

    fm->permissions = stat_buf->st_mode & 0777;
    fm->owner_id = stat_buf->st_uid;
    fm->group_id = stat_buf->st_gid;
    fm->accessed_time = stat_buf->st_atime;
    fm->modified_time = stat_buf->st_mtime;
    fm->changed_time = stat_buf->st_ctime;

    size_t i = 0;
    while(i < MAX_FILE_TYPES) {
        if (strcmp(file_type_stats_storage[i].type, fm->type) == 0) {
            file_type_stats_storage[i].count += 1;
            file_type_stats_storage[i].total_size += fm->size;
        }
        i++;
    }

    return 0;
}

void print_default_mode()
{
    for (int i = 0; i < file_count; i++) {
        FileMeta *fm = &file_meta_storage[i];
        printf(DEFAULT_INFO_FMT,
            fm->type,
            fm->tree_lvl,
            (long long)fm->size,
            fm->path, 
            fm->path + fm->file_name_idx);
    }
}

void print_aggregate_mode()
{
    for (int i = 0; i < file_count; i++) {
        FileMeta *fm = &file_meta_storage[i];
        printf(AGGREGATE_INFO_FMT,
            fm->permissions,
            fm->owner,
            fm->owner_id,
            fm->group,
            fm->group_id,
            ctime(&fm->accessed_time),
            ctime(&fm->modified_time),
            ctime(&fm->changed_time));
    }
}

void print_file_meta(struct cmd *c)
{
    if (c->flags & FLAG_AGGREGATE_INFO) {
        print_aggregate_mode();
        return;
    }
    print_default_mode();
}
