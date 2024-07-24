#ifndef INFO_H
#define INFO_H

#define _XOPEN_SOURCE 500

#define DEFAULT_WALK 0
#define MAX_PARALLEL_FD 20

#define DEFAULT_INFO_FMT "%-4s %-3d %-7lld   %-70s %s\n"
#define AGGREGATE_INFO_FMT "%o %s (%d) %s (%d) %s %s %s\n"
#define INFO_FMT_STR "%-4s %-3s %-7s   %-70s %s\n"
#define HEADER_COLOR "\x1b[1m\x1b[36m"
#define DEFAULT_COLOR "\x1b[0m"

#define MAX_PATH_LENGTH 100
#define MAX_FILES_READABLE 10000

#include <ftw.h>
#include <time.h>
#include <sys/stat.h>

typedef struct {
    char path[MAX_PATH_LENGTH];
    const char *type;
    off_t size;

    // default only
    int tree_lvl;
    int file_name_idx;

    mode_t permissions;
    uid_t owner_id;
    gid_t group_id;
    char owner[256];
    char group[256];
    time_t accessed_time;
    time_t modified_time;
    time_t changed_time;
} FileMeta;

const char *get_file_type(int file_type);

int scrape_file_meta(const char *full_path,
                    const struct stat *stat_buf,
                    int file_type,
                    struct FTW *file_tree_buf);

void print_default_mode();

void print_aggregate_mode();

void print_file_meta();

#endif