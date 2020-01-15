#include "Signs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* closeProperties[] = { "STA","NEQK","NDEQ","NHQK","QHRK","MILV","MILF","HY","FYW" };
char* similarProperties[] = { "CSA","ATV","SAG","STNK","STPA","SGND","SNDEQK","NDEQHK","NEQHRK","FVLIM","HFY" };

Sign* createSigns(char* seq1, char* seq2, int n) {
	int i;
	char ch1, ch2;
	if (seq1 == NULL) {
		printf("SEQ1 Is NULL! ABORTING!");
		return NULL;
	}
	if (seq2 == NULL) {
		printf("SEQ2 Is NULL! ABORTING!");
		return NULL;
	}
	Sign* resultSigns = calloc(1, sizeof(Sign));
	if (resultSigns == NULL)
	{
		printf("Failed To Allocate Memory For resultSigns! ABORTING!");
		return NULL;
	}
	size_t seq1Len = strlen(seq1), seq2Len = strlen(seq2);
	Sign* reallocSigns = resultSigns;
	Sign* tempSign = NULL;
	for (i = 0; i < (seq1Len - n) && i < seq2Len; i++)
	{
		ch1 = seq1[n + i];
		ch2 = seq2[i];
		tempSign = compareLetters(ch1, ch2);
		if (tempSign != NULL)
		{
			reallocSigns = resultSigns;
			resultSigns = realloc(reallocSigns, (i + 1) * sizeof(Sign));
			if (resultSigns == NULL)
			{
				printf("Failed To Reallocate Memory For resultSigns! ABORTING!");
				return NULL;
			}
			resultSigns[i] = *tempSign;
		}
	}
	return resultSigns;
}

Sign* compareLetters(char ch1, char ch2) {
	Sign* signPtr = calloc(1, sizeof(Sign));
	if (signPtr == NULL) {
		printf("Failed To Allocate Memory For Sign! ABORTING!");
		return NULL;
	}
	if (ch1 == ch2) {
		signPtr->sign = Star;
	}
	else if (checkProperties(closeProperties, ch1, ch2)) {
		signPtr->sign = Dot;
	}
	else if (checkProperties(similarProperties, ch1, ch2)) {
		signPtr->sign = TwoDots;
	}
	else {
		signPtr->sign = Space;
	}
	return signPtr;
}

int checkProperties(char* properties[], char ch1, char ch2) {
	int i, numOfProp = sizeof(properties) / sizeof(properties[0]);
	for (i = 0; i < numOfProp; i++)
	{
		if (strstr(properties[i], &ch1) != NULL && strstr(properties[i], &ch2) != NULL)
		{
			return 1;
		}
	}
	return 0;
}

int getCount(Sign* signList) {
	if (signList == NULL)
	{
		printf("Sign Is NULL! ABORTING!");
		return -1;
	}
	int numOfSigns = sizeof(signList) / sizeof(signList[0]);
	int starCounter = 0, twoDotsCounter = 0;
	for (int i = 0; i < numOfSigns; i++)
	{
		if (signList[i].sign == Star) {
			starCounter++;
		}
		else if (signList[i].sign == TwoDots)
		{
			twoDotsCounter++;
		}
	}
	return abs(starCounter - twoDotsCounter);
}
