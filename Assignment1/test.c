#include "inc/mystring.h"
#include "inc/myutils.h"
#include "inc/bitmask.h"
#include <stdio.h>
#include <string.h>
#include "unity/unity.h"

void setUp(void) {
    // set stuff up here
    int i = 0;
    char a[] = "aman";
    char b[] = "kalaskar";
    }

void tearDown(void) {
    // clean stuff up here
}

void MyUtilTest(void) {
    //test stuff
    // TEST_ASSERT_EQUAL_INT(1, 10);
    TEST_ASSERT_EQUAL_INT(0, isPrime(2));
    TEST_ASSERT_EQUAL_INT(1, isPrime(10));
    TEST_ASSERT_EQUAL_INT(1, isPalindrome(12345));
    TEST_ASSERT_EQUAL_INT(0, isPalindrome(12321));
    TEST_ASSERT_EQUAL_INT(120, factorial(5));
    TEST_ASSERT_EQUAL_INT(1, factorial(0));
    // TEST_ASSERT_EQUAL_INT(15, vsum(0,1,2,3,4,5));
    
}

void MyStringTest(void) {
    //more test stuff
    // TEST_ASSERT_EQUAL_STRING ("amankalaskar", mystrcat("aman","kalaskar"));
    TEST_ASSERT_EQUAL_INT(2, mystrlen("hi"));
    // char *a = "aman";
    // char *b = "kalaskar";
    // char *c = "amankalaskar";
    // TEST_ASSERT_EQUAL(c, mystrcat(a,b));
}

void MyBitMaskTest(void) {
    //more test stuff

}


// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(MyUtilTest);
    RUN_TEST(MyStringTest);
    RUN_TEST(MyBitMaskTest);
    
    return UNITY_END();
}