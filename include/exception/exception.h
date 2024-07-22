#ifndef EXCEPTION_EXCEPTION_H
#define EXCEPTION_EXCEPTION_H

#include <stdlib.h>


#define USAGE_EXCEPTION "Usage: %s <starting-directory>\n"
#define PARSE_EXCEPTION "failed to parse commmand arguments\n"
#define FS_EXCEPTION "Cannot check whole file system " \
    "please specify an inner directory instead e.g " \
    "/home, /home/Documents \n"

#define EXCEPTION_AND_EXIT(fmt, ...) \
    do { \
        fprintf(stderr, fmt, ##__VA_ARGS__); \
        exit(EXIT_FAILURE); \
    } while (0)

#define EXCEPTION_AND_RETURN(value, fmt, ...) \
    do { \
        fprintf(stderr, fmt, ##__VA_ARGS__); \
        return value; \
    } while (0)


#endif