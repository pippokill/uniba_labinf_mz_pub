#include "unity.h"
#include "unity.c"
#include "unity_internals.h"
#include "math.h"
#include <stdlib.h>

static int *buffer;

void setUp(void)
{
    buffer = malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++)
        buffer[i] = i;
}

void tearDown(void)
{
    free(buffer);
}

void test_valore_centrale(void) {
    TEST_ASSERT_EQUAL(5, buffer[5]);
}

void test_somma_buffer(void) {
    int somma = 0;
    for (int i = 0; i < 10; i++) somma += buffer[i];
    TEST_ASSERT_EQUAL(45, somma);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_valore_centrale);
    RUN_TEST(test_somma_buffer);
    return UNITY_END();
}