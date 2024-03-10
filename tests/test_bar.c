#include "unity.h"

#include "bar.h"

void setUp(void)
{
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
}

void test_branch1(void)
{
    TEST_ASSERT_EQUAL(fn_branch(true, false), 0);
    TEST_ASSERT_EQUAL(fn_branch(true, true), 0);
    TEST_ASSERT_EQUAL(fn_branch(false, true), 0);
    TEST_ASSERT_EQUAL(fn_branch(false, false), 1);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_branch1);
    return UNITY_END();
}
