#ifndef INFO_H
#define INFO_H

static int fs_checker(const char *full_path,
                    const struct stat *stat_buf,
                    int file_type,
                    struct FTW *walk_buf);



#endif