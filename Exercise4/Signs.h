#pragma once

//Specifies the only solutions available.
enum eSigns { Star, TwoDots, Dot, Space };

//Takes two sequences and compare the two from n'th character of seq1,
//and write the result to a list of signs compressed into two bits each (tempSign).
//resultSign - Each Sign takes two bits in the resultSigns array, and the array is built from
//8-bit chars. Meaning each 8-bit segment can hold 4 Signs.
char* createSigns(char* seq1, char* seq2, int n);

//Takes one letter from each sequence and compares them. The returning value comes
//from enum eSigns.
int compareLetters(char ch1, char ch2);

//Takes a properties array of strings from global definition, and the two chars
//from compareLetters, and checks if both of the chars are in the same group.
int checkProperties(char* properties[], int numOfProp, char ch1, char ch2);

//Takes the resulted sign list after comparison, and calculates the difference
//between the number of Stars (match) and the number of TwoDots (close properties).
int getCount(char* signList);