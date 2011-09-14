//calculator.c

#include <stdlib.h>
#include <string.h>
#include "calculator.h"

#define MAX_LENGTH 32 

int  calculator_add(char number_string[]) {
	int sum = 0;
	char nums[MAX_LENGTH];
	char * number;
	char delims[] = " ,\n";
	strcpy( nums, number_string);
	if(nums != NULL) {
		number = strtok(nums, delims);
		while(number != NULL) {		
			sum += atoi(number);
			number = strtok(NULL, delims);		
		}
	}
	return sum;
}

