#include "Package.h"
#include <stdio.h>

#define PRINT_SEQUENCES

#ifdef PRINT_SEQUENCES
#define PRINT(seq1,seq2,signs,count,skip) printf("%s\n%s\n%s\nThe Difference is: %d\n",seq1,seq2,signs,count);
#endif
	
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

void main() {
	int n = 7;
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
	int count = evaluateDifference(seq1, seq2, n);
	if (count == -1)
	{
		printf("evaluateDifference Failed! ABORTING!");
		return;
	}
	PRINT(seq1, seq2, signsToString(signList), count, n);
}