// Canadian Computing Competition
// Year: 2020
// Problem Junior #3 (J3)
// Author: Ryan Mackintosh
// Allow use of 'insecure' functions, such as strerror
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int read_file();

int main() {

	// Input filename array
	//const char* input_files[] = { ".\\.\\j2.01.in", ".\\.\\j2.02.in", ".\\.\\j2.03.in", ".\\.\\j2.04.in", ".\\.\\j2.05.in" };

	// Sample input files
	const char* input_files[] = { ".\\.\\j3.sample.01.in" };

	// Calculate the number of input files
	const int files_count = sizeof(input_files) / sizeof(const char*);

	// Iterate through the list of input files
	for (int x = 0; x < files_count; ++x) {

		// read_file will print the coordinates of the lower left and upper right corner of the smallest bounding box
		if (read_file(input_files[x]) != 0) {
			printf("Error reading input file\n");
		}
	}

	return 0;
}

// Function read_file()
// Arguments: filename to open
// Prints the coordinates of the lower left and upper right corner of the smallest bounding box
int read_file(const char* filename) {

	// Variables
	// N number of points to read
	// Xmin smallest X coordinate
	// Xmax largest X coordinate
	// Ymin smallest Y coordinate
	// Ymax largest Y coordinate
	long int N = 0, Xmin = 0, Xmax = 0, Ymin = 0, Ymax = 0, temp = 0;

	// Create pointer & open file read-only
	FILE* file_pointer;
	errno_t err = fopen_s(&file_pointer, filename, "r");

	printf("Trying to open %s\n", filename);

	if (err != 0) {
		printf("Error: %s\n", strerror(err));
		return 1;
	}

	/* // Assuming 3 integer values to read
	fscanf_s(file_pointer, "%d", &P);
	fscanf_s(file_pointer, "%d", &N);
	fscanf_s(file_pointer, "%d", &R); */

	char buffer[8]; // Max input length is XX,YY\n

	errno = 0;

	char* endptr;
	temp = strtol(buffer, &endptr, 10);

	if (errno == ERANGE) {
		printf("ERANGE error\n");
		return 1;
	}
	else if (endptr == buffer) {
		printf("Nothing read error\n");
		return 1;
	}
	else if (*endptr && *endptr != '\n') {
		printf("Whole input wasn't converted...this is expected I think for the first coordinate\n");
	}
	else {
		printf("Successful read\n");
	}

	printf("Read N: %d\n", temp);

	do {
		// Read 8 characters, or up to \n
		if (!fgets(buffer, 8, file_pointer)) return 1; // Replace 8 with calculated size of buffer

		char* coords = strtok(buffer, ",");

		errno = 0;

		temp = strtol(buffer, &endptr, 10);

		if (errno == ERANGE) {
			printf("ERANGE error\n");
			return 1;
		}
		else if (endptr == buffer) {
			printf("Nothing read error\n");
			return 1;
		}
		else if (*endptr && *endptr != '\n') {
			printf("Whole input wasn't converted...this is expected I think for the first coordinate\n");
		}
		else {
			printf("Successful read\n");
		}

		//char* find = strchr(buf, ",");
		//strncpy(dest)
	} while (0);

	return 0;
}