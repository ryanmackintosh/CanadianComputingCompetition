// Canadian Computing Competition
// Year: 2020
// Problem Junior #1 (J1)
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
	const char* input_files[] = { ".\\.\\j1.01.01.in", ".\\.\\j1.01.02.in", ".\\.\\j1.01.03.in" };
	const char *output_files[] = { ".\\.\\j1.01.01.out", ".\\.\\j1.01.02.out", ".\\.\\j1.01.03.out" };

	//char file1[] = "j1.01.01.in";
	
	// Calculate the number of input files
	const int files_count = sizeof(input_files) / sizeof(const char*);

	// Iterate through the list of input files
	for (int x = 0; x < files_count; ++x) {
		//printf("%s\n", input_files[x]);

		// If read_file returns 1, Barley is Happy
		if (read_file(input_files[x])) {
			printf("happy\n");
		}
		else {
			printf("sad\n");
		}
	}

	//printf("%u\n", files_count);
	//printf("Reading file: %s\n", file1);

	return 0;
}

// Function read_file()
// Arguments: filename to open
// Returns 1 if Barley is happy, 0 if Barley is sad
int read_file(const char* filename) {

	// Variables to store the small, medium and large treat counts
	int small = 0, medium = 0, large = 0;

	// Create pointer & open file read-only
	FILE* file_pointer;
	errno_t err = fopen_s(&file_pointer, filename, "r");

	printf("Trying to open %s\n", filename);

	if (err != 0) {
		printf("Error: %s\n", strerror(err));
		return -1;
	}

	// Assuming 3 integer values to read
	fscanf_s(file_pointer, "%d", &small);
	fscanf_s(file_pointer, "%d", &medium);
	fscanf_s(file_pointer, "%d", &large);

	printf("%d %d %d\n", small, medium, large);

	// Happiness score
	// Formula: 1*S + 2*M + 3*L
	if ((small + 2 * medium + 3 * large) >= 10) return 1;
	else return 0;
}