#include "inc/mystring.h"
#include "inc/myutils.h"
#include "inc/bitmask.h"
#include <stdio.h>
#include <string.h>
#include "Unity-master/src/unity.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_function_should_doBlahAndBlah(void) {
    //test stuff
}

void test_function_should_doAlsoDoBlah(void) {
    //more test stuff
}

// not needed when using generate_test_runner.rb
int main(void) {
    // UNITY_BEGIN();
    // RUN_TEST(test_function_should_doBlahAndBlah);
    // RUN_TEST(test_function_should_doAlsoDoBlah);
    TEST_ASSERT_EQUAL_INT(0, isPrime(2));
    TEST_ASSERT_EQUAL_INT(0, isPrime(2));
    TEST_ASSERT_EQUAL_INT(0, isPrime(2));
    TEST_ASSERT_EQUAL_INT(0, isPrime(2));
    // return UNITY_END();
}