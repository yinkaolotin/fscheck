#include "unity.h"
#include "parser/parser.h"


void setUp(void) {}
void tearDown(void) {}

void test_parse_cmd(void) {
    char *argv[] = {"./fscheck", "/home"};
    TEST_ASSERT_EQUAL_STRING("/home", parse_cmd(2, argv)->directory);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_parse_cmd);
    return UNITY_END();
}