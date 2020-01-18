#include "Sequence.h"
#include "Signs.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 300

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