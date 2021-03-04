#include "sum.h"
#include "minmax.h"
#include "../../Assignment/unity/unity.h"

void setUp(void) {
    // set stuff up here
    int i = 0;
    char a[] = "aman";
    char b[] = "kalaskar";
    }

void tearDown(void) {
    // clean stuff up here
}


void SUM_TEST(void) {
    //more test stuff
    TEST_ASSERT_EQUAL_INT(499500, sumof1000());
     
    
}



// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(SUM_TEST);
    int minval=getmin();
    int maxval=getmax();
    printf("\nmin= %d\nmax= %d\n",);
    return UNITY_END();
}