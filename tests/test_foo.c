#include "unity.h"

#include "foo.h"

void setUp(void)
{
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
}

void test_print_hello_world(void)
{
    TEST_ASSERT_EQUAL(1, print_hello_world());
}

void test_factorial(void)
{
    TEST_ASSERT_EQUAL(1, factorial(0));
    TEST_ASSERT_EQUAL(1, factorial(1));
    TEST_ASSERT_EQUAL(2, factorial(2));
    TEST_ASSERT_EQUAL(6, factorial(3));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_print_hello_world);
    RUN_TEST(test_factorial);
    return UNITY_END();
}
