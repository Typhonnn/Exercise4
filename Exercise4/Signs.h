#pragma once

typedef struct {
	unsigned int sign : 2;
} Sign;

enum eSigns { Star, TwoDots, Dot, Space };

Sign* createSigns(char* seq1, char* seq2, int n);

Sign* compareLetters(char ch1, char ch2);

int checkProperties(char* properties[], char ch1, char ch2);

int getCount(Sign* signList);