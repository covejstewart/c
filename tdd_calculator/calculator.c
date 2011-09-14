//calculator.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "calculator.h"

#define MAX_LENGTH 32 

static bool check_for_positive(char* number) {
	int tmp = atoi(number);
	if(tmp < 0) {
		printf("Exception: Negative number found %i\n", tmp);
	}
	return (tmp > 0);	
}

int  calculator_add(const char number_string[]) {
	int sum = 0;
	char nums[MAX_LENGTH]; //create a local copy so strtok can modify
	char * number;

	if(number_string != NULL) {
		strcpy( nums, number_string);
		char * delim;	

		if(nums[0] == '/') {
			delim = strtok(nums, "/\n");
			number = strtok(NULL,delim);
		}
		else {
			char tmp[] = ",\n";
			delim = tmp;
			number = strtok(nums,delim);
		}

		while(number != NULL) {
			if(check_for_positive(number)){		
				sum += atoi(number);
			}	
			else {
				sum = -1;
			}
			number = strtok(NULL, delim);		
		}
	}
	return sum;
}

