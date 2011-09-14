//calculator.c

#include <stdlib.h>
#include <string.h>
#include "calculator.h"

#define MAX_LENGTH 32 

int  calculator_add(const char number_string[]) {
	int sum = 0;
	char nums[MAX_LENGTH]; //create a local copy so strtok can modify
	const char delims[] = ",\n";
	char * number;

	if(number_string != NULL) {
		strcpy( nums, number_string);
		number = strtok(nums, delims);
		while(number != NULL) {		
			sum += atoi(number);
			number = strtok(NULL, delims);		
		}
	}
	return sum;
}

