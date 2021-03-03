#include "inc/mystring.h"
#include "inc/myutils.h"
#include "inc/bitmask.h"
#include <stdio.h>
#include <string.h>
<<<<<<< HEAD
#include "Unity-master/src/unity.h"
=======
#include "unity/unity.h"
>>>>>>> 882f68a5a9c4a8c3657172fbcea410fb1bc7f845

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

<<<<<<< HEAD
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
=======
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
    // TEST_ASSERT_EACH_
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
>>>>>>> 882f68a5a9c4a8c3657172fbcea410fb1bc7f845
}