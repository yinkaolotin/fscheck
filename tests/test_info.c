#define _XOPEN_SOURCE 500
#include <ftw.h>
#include "unity.h"
#include "parser/parser.h"
#include "info/info.h"


void setUp(void) {}
void tearDown(void) {}

void test_fs_checker(void) {
    char *argv[] = {"./fscheck", "/home/yinkaolotin/foss/fscheck/tests"};
    const cmd *c = parse_cmd(2, argv)

    TEST_ASSERT_EQUAL_INT(nftw(c->directory, fs_checker, MAX_PARALLEL_FD, DEFAULT_WALK), 0);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_fs_checker);
    return UNITY_END();
}