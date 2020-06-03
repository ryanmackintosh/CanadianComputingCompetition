// Canadian Computing Competition
// Year: 2020
// Problem Junior #2 (J2)
// Author: Ryan Mackintosh

// Allow use of 'insecure' functions, such as strerror
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int read_file();

int main() {

	// Array filenames
	const char* input_files[] = { ".\\.\\j2.01.in", ".\\.\\j2.02.in", ".\\.\\j2.03.in", ".\\.\\j2.04.in", ".\\.\\j2.05.in" };
	//const char* output_files[] = { ".\\.\\j2.01.01.out", ".\\.\\j2.01.02.out", ".\\.\\j2.01.03.out" };
	
	// Sample input files
	//const char* input_files[] = { ".\\.\\j2.sample.01.in", ".\\.\\j2.sample.02.in" };

	// Calculate the number of input files
	const int files_count = sizeof(input_files) / sizeof(const char*);

	// Iterate through the list of input files
	for (int x = 0; x < files_count; ++x) {

		// Print the number of days when the number of people infected is greater than P
		printf("%d days\n",read_file(input_files[x]));
	}

	return 0;
}

// Function read_file()
// Arguments: filename to open
// Returns the number of days until the number of people infected is > P
int read_file(const char* filename) {

	// Variables
	// N number of people with the disease on day 0
	// P total people with the disease on a specified day
	// R number of people infected by 1 person
	int N = 0, P = 0, R = 0;

	// Create pointer & open file read-only
	FILE* file_pointer;
	errno_t err = fopen_s(&file_pointer, filename, "r");

	printf("Trying to open %s\n", filename);

	if (err != 0) {
		printf("Error: %s\n", strerror(err));
		return -1;
	}

	// Assuming 3 integer values to read
	fscanf_s(file_pointer, "%d", &P);
	fscanf_s(file_pointer, "%d", &N);
	fscanf_s(file_pointer, "%d", &R);

	//printf("%d %d %d\n", P, N, R);

	// Calculate how many days until the number of people infected is greater than P
	// day 0 = N people infected
	//

	int new_infections = (N * R), total_infections = N + new_infections;

	for (int day = 1; 1; ++day) {
		if (total_infections > P) {
			//printf("People infected %d\n", total_infections);
			return day;
		}
		new_infections = (new_infections * R);
		total_infections += new_infections;
		
		//printf("New infecctions %d total infections %d\n", new_infections, total_infections);
	}
}