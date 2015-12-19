// AidenLabsAlgorithmChallenge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>	//for INT_MAX


int main(int argc, char **argv)
{
	char *ptr;
	int i,j;
	//number of bucket sizes = argc - 2. ignore file name and last argument (target val)
	int num_buckets = argc - 2;
	//target_value is last argument: target_value = argv[argc-1]
	long targetTemp = strtol(argv[argc - 1], &ptr, 10);
	int target_value = 0;
	if (targetTemp < INT_MAX) {
		target_value = targetTemp;	//truncate long to int
	}
	else {	//error handling
		printf("Target Value is too large. Exiting program gracefully\n");
		return -1;
	}
	//exit if target value is 0
	if (target_value == 0) {
		printf("Invalid target value. Exiting...\n");
		return 0;
	}
	//create array of ints of size argc - 2
	int *bucket_sizes = (int *)malloc(sizeof(int)*(argc - 2));
	if (!bucket_sizes){//insufficient memory available
		printf("insufficient memory available.Exiting...\n");
		free(bucket_sizes);
		return -1;
	}
	int *bucket_mods = (int *)malloc(sizeof(int)*(argc - 2));
	if (!bucket_mods) {//insufficient memory available
		printf("insufficient memory available.Exiting...\n");
		free(bucket_mods);
		return -1;
	}
	//convert argument strings to ints
	long BuckTemp;
	for (j = 1; j < (argc - 1); j++) {
		BuckTemp = strtol(argv[j], &ptr, 10);
		if (BuckTemp < INT_MAX && BuckTemp != 0) {	//do not allow values too large for ints, or zeros
			//store bucket_sizes into array
			bucket_sizes[j] = BuckTemp;
		}
		else {	//error handling
			printf("Bad Argument. Exiting program..\n");
			return -1;
		}
	}
	//set initial value of current_target
	int current_target = target_value;
	//initialize values of valid_buckets, next_step, and min_mod
	int valid_buckets = 0;
	int next_step = 0;
	int min_mod = INT_MAX;
	//start while loop
	while (current_target > 0) {
		//reset validity counter
		valid_buckets = 0;
		//start loop through buccket_size array
		for (i = 1; i <= num_buckets; i++) {
			//check for valid bucket sizes
			if (bucket_sizes[i] <= current_target) {
				//increment validity counter
				valid_buckets++;
				//calculate bucket_mod
				bucket_mods[i] = current_target % bucket_sizes[i];
				//check if we're at the last bucket_size before the end
				if (bucket_mods[i] == 0) {
					printf("true\n");
					return 1;//successful if bucket_mod is 0
				}
				//determine next step size
				if (bucket_mods[i] < min_mod) {
					min_mod = bucket_mods[i];
					next_step = bucket_sizes[i];
				}
			}
		}
		//check if we ran out of valid bucket sizes
		if (valid_buckets == 0) {
			printf("false\n");
			return 0;//unsuccessful if no more valid buckets
		}
		//take next step
		current_target -= next_step;
	}

    return 0;
}

