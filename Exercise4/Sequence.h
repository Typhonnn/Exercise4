#pragma once

//Takes a file name and returns the first row in the file.
char* createSequence(char* fileName);

//Calculates the difference between the amount of Star signs and the amount of TwoDots signs.
int evaluateDifference(char* seq1, char* seq2, int n);