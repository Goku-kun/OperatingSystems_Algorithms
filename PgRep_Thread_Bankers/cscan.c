#include <stdio.h>
#include <stdlib.h>

#define REQUESTS 1000

int start = 0;

int ran_array[REQUESTS];
int test_array[REQUESTS];
/* Circular Scan (C-SCAN) - start at start index, increase to upper boundary
(even if no value at boundary), save boundary value, go to start boundary
(zero value) increase till last value before start value */
int cscan(int* ranArray) {

	int i = 0, curr_val = 0, sav_val = ran_array[start], difference = 0;
	int head_movement = 0, curr_i = 0, upper_bound = 4999;

	for(i = start+1; i < REQUESTS; i++) {

		curr_val = ran_array[i];
		difference = abs(sav_val - curr_val);
		head_movement += difference;
		sav_val = curr_val;

	}

	/* add last val - upper bound, go to and add zero boundary (4999)*/
	head_movement += upper_bound - sav_val;
	sav_val = 0;
	head_movement += 4999;

	for(i = 0; i < start; i++) {

		curr_val = ran_array[i];
		difference = abs(curr_val - sav_val);
		head_movement += difference;
		sav_val = curr_val;

	}

	return head_movement;
}
int main (int argc, char *argv[]) {


	int i = 0;
	start = atoi(argv[1]);

	if(argc != 2) {

		printf("Please compile program with starting index from 0-4999. Ex. ./diskAlgorithms 423 or if you're running it on windows, then a.exe 423\n");
		exit(-1);
	}

	for(i = 0; i < REQUESTS; i++) {
		ran_array[i] = rand() % 5000;
	}

	printf("\nStart index: %d, start value: %d\n\n", start, ran_array[start]);

	printf("CSCAN head movements: %d\n", cscan(ran_array));

	return 0;
}
