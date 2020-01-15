#include "Package.h"
#include <stdio.h>

void main() {
	char* seq1 = createSequence("DNN1.txt");
	if (seq1 == NULL)
	{
		printf("seq1 Is NULL! ABORTING!");
		return;
	}
	char* seq2 = createSequence("DNN2.txt");
	if (seq2 == NULL)
	{
		printf("seq2 Is NULL! ABORTING!");
		return;
	}
	int result = evaluateDifference(seq1, seq2, 0);
	if (result == -1)
	{
		printf("result Is -1! ABORTING!");
		return;
	}
	printf("The difference between the two sequences is %d\n", result);
}