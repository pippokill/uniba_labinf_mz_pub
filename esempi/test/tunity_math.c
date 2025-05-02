#include "unity.h"
#include "unity.c"
#include "unity_internals.h"
#include "math.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_basic_math_operations(void) {
    //test stuff
    TEST_ASSERT_EQUAL_INT(13, somma(7,6));
    TEST_ASSERT_EQUAL_INT(-13, prodotto(-1, 13));
    TEST_ASSERT_EQUAL_INT(-3, sottrazione(-1, 2));
    TEST_ASSERT_EQUAL_INT(5, divisione(10, 2));
}

void test_adv_math_operations(void) {
    //test stuff
    TEST_ASSERT_EQUAL_INT(81, quadrato(9));
    TEST_ASSERT_EQUAL_INT(8, cubo(2));
    TEST_ASSERT_EQUAL_INT(1, pari(2));
    TEST_ASSERT_EQUAL_INT(0, dispari(2));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_basic_math_operations);
    RUN_TEST(test_adv_math_operations);
    return UNITY_END();
}