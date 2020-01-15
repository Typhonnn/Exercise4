#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 300

char* createSequence(char* fileName) {
	FILE *file = NULL;
	fopen_s(&file, fileName, "w");
	if (file == NULL) {
		printf("Failed To Open %s! ABORTING!", fileName);
		return NULL;
	}
	char *line = calloc(MAX_LINE,sizeof(char));
	if (line == NULL) {
		printf("Could Not Allocate Line! ABORTING!");
		return;
	}
	char *endFile = NULL;
	if(!feof(file)) {
		endFile = fgets(line, MAX_LINE, file);
	}
	return line;
}

char* createSigns(char* SEQ1, char* SEQ2, int n) {
	if (SEQ1 == NULL) {
		printf("SEQ1 Is NULL! ABORTING!");
		return NULL;
	}
	if (SEQ2 == NULL) {
		printf("SEQ2 Is NULL! ABORTING!");
		return NULL;
	}
	char* resultSEQ = calloc(1, sizeof(char));
	if (resultSEQ == NULL) {
		printf("Failed To Allocate Memory for resultSEQ! ABORTING!");
		return NULL;
	}
	//TODO stub
}