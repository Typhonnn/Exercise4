#include "Package.h"
#include <stdio.h>
#include <stdlib.h>

//Takes offset the user picked and returns a string of spaces to display the offset.
char* getSkip(int n) {
	char* skip = calloc(n + 1, sizeof(char));
	if (skip == NULL)
	{
		printf("Failed To Allocate Memory For skip! ABORTING!");
		return NULL;
	}
	for (int i = 0; i < n; i++)
	{
		skip[i] = ' ';
	}
	skip[n] = '\0';
	return skip;
}