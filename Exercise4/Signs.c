#include "Signs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Tal Balelty, 312270291

//This array of strings holds the groups of close properties sequences.
char* closeProperties[] = { "STA","NEQK","NDEQ","NHQK","QHRK","MILV","MILF","HY","FYW" };
//This array of strings holds the groups of similar properties sequences.
char* similarProperties[] = { "CSA","ATV","SAG","STNK","STPA","SGND","SNDEQK","NDEQHK","NEQHRK","FVLIM","HFY" };
//numOfSigns will be sized correctly while createSigns works.
int* numOfSigns, numOfCloseProp = 9, numOfSimilarProp = 11;
char* signList;

//Takes two sequences and compare the two from n'th character of seq1,
//and write the result to a list of signs compressed into two bits each (tempSign).
//resultSign - Each Sign takes two bits in the resultSigns array, and the array is built from
//8-bit chars. Meaning each 8-bit segment can hold 4 Signs.
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
	int size = seq2Len / 4 + 1;	//Making enough space for signs.
	signList = calloc(size, sizeof(char));
	if (signList == NULL)
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
		signList[i / 4] &= ~mask;	//Readying the correct position.
		signList[i / 4] |= (tempSign & 3) << (2 * (i % 4)); //Placing the two bits in the array.
		(*numOfSigns)++;	//Size of array + 1.
	}
	return signList;
}

//Takes one letter from each sequence and compares them. The returning value comes
//from enum eSigns.
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

//Takes a properties array of strings from global definition, and the two chars
//from compareLetters, and checks if both of the chars are in the same group.
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

//Takes the resulted sign list after comparison, and calculates the difference
//between the number of Stars (match) and the number of TwoDots (close properties).
int getCount(char* signs) {
	int sign = 0;
	if (signs == NULL)
	{
		printf("Sign Is NULL! ABORTING!");
		return -1;
	}
	int starCounter = 0, twoDotsCounter = 0;
	for (int i = 0; i < *numOfSigns; i++)
	{
		//Extracting the two bits of the sign.
		sign = (signs[i / 4] >> (2 * (i % 4))) & 3; 
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

//Takes the two bit represented signs and returns a string of all signs as actual characters.
char* signsToString(char* signs) {
	int i, sign = -1;
	if (signs == NULL){
		return NULL;
	}
	if (numOfSigns == NULL) {
		return NULL;
	}
	int size = *numOfSigns + 1;
	char* string = calloc(size, sizeof(char));
	if (string == NULL)
	{
		printf("Failed To Allocate Memory For string! ABORTING!");
		return NULL;
	}
	string[0] = '\0';
	for ( i = 0; i < size - 1; i++)
	{
		sign = (signs[i / 4] >> (2 * (i % 4))) & 3;
		strcat_s(string, size, intToChar(sign));
	}
	return string;
}

//Takes a sign and converts it into an actual character.
char* intToChar(int sign) {
	char* appSign = calloc(1, sizeof(char));
	if (appSign == NULL)
	{
		printf("Failed To Allocate Memory For appSign! ABORTING!");
		return NULL;
	}
	if (sign == Star)
	{
		appSign = "*";
		return appSign;
	}
	else if (sign == TwoDots)
	{
		appSign = ":";
		return appSign;
	}
	else if (sign == Dot)
	{
		appSign = ".";
		return appSign;
	}
	else
	{
		appSign = " ";
		return appSign;
	}
}
