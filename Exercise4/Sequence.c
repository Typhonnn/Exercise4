#include "Sequence.h"
#include "Signs.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 300

//Takes a file name and returns the first row in the file.
char* createSequence(char* fileName) {
	FILE* file = NULL;
	fopen_s(&file, fileName, "r");
	if (file == NULL) {
		printf("Failed To Open %s! ABORTING!", fileName);
		return NULL;
	}
	char* line = calloc(MAX_LINE, sizeof(char));
	if (line == NULL) {
		printf("Could Not Allocate Line! ABORTING!");
		return NULL;
	}
	if (!feof(file)) {
		fgets(line, MAX_LINE, file);
	}
	fclose(file);
	return line;
}

//Calculates the difference between the amount of Star signs and the amount of TwoDots signs.
int evaluateDifference(char* seq1, char* seq2, int n) {
	if (seq1 == NULL) {
		printf("SEQ1 Is NULL! ABORTING!");
		return -1;
	}
	if (seq2 == NULL) {
		printf("SEQ2 Is NULL! ABORTING!");
		return -1;
	}
	char* signs = createSigns(seq1, seq2, n);
	if (signs == NULL)
	{
		printf("signList Is NULL! ABORTING!");
		return -1;
	}
	int count = getCount(signs);
	return count;
}