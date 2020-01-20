#include "Package.h"
#include <stdio.h>
#include <stdlib.h>

//If defined this marco prints all the required data.
#define PRINT_SEQUENCES

#ifdef PRINT_SEQUENCES
#define PRINT(seq1,seq2,signs,count,skip) printf("%s\n%s%s\n%s%s\nThe Difference is: %d\n",seq1,skip,seq2,skip,signs,count);
#else
#define PRINT(seq1,seq2,signs,count,skip);
#endif

void main(int argc, char* argv[]) {
	//Checks to see if two file names were provided.
	if (argc != 3) {
		printf("Must provide atleast 2 parameters! ABORTING!");
		return;
	}
	int n = 7;
	char* seq1 = createSequence(argv[1]);
	if (seq1 == NULL)
	{
		printf("seq1 Is NULL! ABORTING!");
		return;
	}
	char* seq2 = createSequence(argv[2]);
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
	//give the macro the paramaters.
	PRINT(seq1, seq2, signsToString(signList), count, getSkip(n));
}