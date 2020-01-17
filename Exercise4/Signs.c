#include "Signs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//This array of strings holds the groups of close properties sequences.
char* closeProperties[] = { "STA","NEQK","NDEQ","NHQK","QHRK","MILV","MILF","HY","FYW" };
//This array of strings holds the groups of similar properties sequences.
char* similarProperties[] = { "CSA","ATV","SAG","STNK","STPA","SGND","SNDEQK","NDEQHK","NEQHRK","FVLIM","HFY" };
//numOfSigns will be sized correctly while createSigns works.
int* numOfSigns, numOfCloseProp = 9, numOfSimilarProp = 11;

//Takes two sequences and compare the two from n'th character of seq1, and write the result to a list of signs compressed into two bits each.
char* createSigns(char* seq1, char* seq2, int n) {
	int i, mask = 0, tempSign = 0;
	char ch1, ch2;
	if (seq1 == NULL) {
		printf("SEQ1 Is NULL! ABORTING!");
		return NULL;
	}
	if (seq2 == NULL) {
		printf("SEQ2 Is NULL! ABORTING!");
		return NULL;
	}
	size_t seq1Len = strlen(seq1);
	size_t seq2Len = strlen(seq2);
	int size = seq2Len / 4 + 1;
	char* resultSigns = calloc(size, sizeof(char));
	if (resultSigns == NULL)
	{
		printf("Failed To Allocate Memory For resultSigns! ABORTING!");
		return NULL;
	}
	numOfSigns = calloc(1, sizeof(int)); //
	if (numOfSigns == NULL)
	{
		printf("Failed To Allocate Memory For resultSigns! ABORTING!");
		return NULL;
	}
	for (i = 0; i < (seq1Len - n) && i < seq2Len; i++)
	{
		ch1 = seq1[n + i];
		ch2 = seq2[i];
		tempSign = compareLetters(ch1, ch2); //tempSign will be compressed into two bits.
		mask = 3 << (2 * (i % 4));	//Preparing the mask.
		resultSigns[i / 4] &= ~mask;	//Readying the correct position.
		resultSigns[i / 4] |= (tempSign & 3) << (2 * (i % 4)); //Placing the two bits in the array.
		(*numOfSigns)++;
	}
	return resultSigns;
}

int compareLetters(char ch1, char ch2) {
	if (ch1 == ch2) {
		return Star;
	}
	else if (checkProperties(closeProperties, numOfCloseProp, ch1, ch2)) {
		return TwoDots;
	}
	else if (checkProperties(similarProperties, numOfSimilarProp, ch1, ch2)) {
		return Dot;
	}
	else {
		return Space;
	}
}

int checkProperties(char* properties[], int numOfProp, char ch1, char ch2) {
	int i, j, match;
	size_t propLen = 0;
	for (i = 0; i < numOfProp; i++)
	{
		match = 0;
		propLen = strlen(properties[i]);
		for (j = 0; j < propLen; j++)
		{
			if (properties[i][j] == ch1)
			{
				match++;
			}
			if (properties[i][j] == ch2)
			{
				match++;
			}
		}
		if (match == 2)
		{
			return 1;
		}
	}
	return 0;
}

int getCount(char* signList) {
	int sign = 0;
	if (signList == NULL)
	{
		printf("Sign Is NULL! ABORTING!");
		return -1;
	}
	int starCounter = 0, twoDotsCounter = 0;
	for (int i = 0; i < *numOfSigns; i++)
	{
		sign = (signList[i / 4] >> (2 * (i % 4))) & 3;
		if (sign == Star) {
			starCounter++;
		}
		else if (sign == TwoDots)
		{
			twoDotsCounter++;
		}
	}
	return abs(starCounter - twoDotsCounter);
}
