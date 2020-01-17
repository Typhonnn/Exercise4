#pragma once

enum eSigns { Star, TwoDots, Dot, Space };

char* createSigns(char* seq1, char* seq2, int n);

int compareLetters(char ch1, char ch2);

int checkProperties(char* properties[], int numOfProp, char ch1, char ch2);

int getCount(char* signList);