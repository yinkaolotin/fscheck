#ifndef EXCEPTION_EXCEPTION_H
#define EXCEPTION_EXCEPTION_H

#define USAGE_EXCEPTION "Usage: %s <starting-directory>\n"
#define PARSE_EXCEPTION "failed to parse commmand arguments"
#define FS_EXCEPTION "Cannot check whole file system " \
    "please specify an inner directory instead e.g " \
    "/home, /home/Documents \n"

#define EXCEPTION_AND_EXIT(fmt, ...) \
    fprintf(stderr, fmt, __VA_ARGS__); \
    exit(EXIT_FAILURE);

#define EXCEPTION_AND_RETURN(value, fmt, ...) \
    fprintf(stderr, fmt, __VA_ARGS__); \
    return value;


#endif