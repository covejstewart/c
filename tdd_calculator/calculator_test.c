//calculator_test.c

#include "calculator.h"

#include <assert.h>
#include <stdlib.h>


static void test_empty_string() {
	assert(calculator_add("") == 0 && "test_empty_string()");
}

static void test_single_digit_number() {
	assert(calculator_add("8") == 8 && "test_single_number()");
}

static void test_multi_digit_number() {
	assert(calculator_add("164") == 164 && "test_multi_digit_number()");
}

static void test_two_small_numbers() {
	assert(calculator_add("3,5") == 8 && "test_two_small_numbers()");
}

static void test_two_big_numbers() {
	assert(calculator_add("1000,573") == 1573 && "test_two_big_numbers()");
}

static void test_five_numbers() {
	assert(calculator_add("100,200,10,1,50") == 361 && "test_five_numbers()");
}

static void test_leading_delims() {
	assert(calculator_add(",17,,10") == 27 && "test_leading_delims()");
}

static void test_newline_delims() {
	assert(calculator_add("100\n100,100") == 300 && "test_newline_delims()");
}

static void test_change_delimiter() {
	assert(calculator_add("//*\n1*2*3") == 6 && "test_change_delimiter()");
}

static void test_exception_on_negative() {
	assert(calculator_add("-10") == -1 && "test_exception_on_negative()");
}

static void test_exception_on_multiple_negatives() {
	assert(calculator_add("-10,-30,4,-70") == -1 && "test_exception_on_multiple_negatives()");
}

int main() {
	test_empty_string();
	test_single_digit_number();
	test_multi_digit_number();
	test_two_small_numbers();
	test_two_big_numbers();
	test_five_numbers();
	test_leading_delims();
	test_newline_delims();
	test_change_delimiter();
	test_exception_on_negative();
	test_exception_on_multiple_negatives();
}
