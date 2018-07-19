#ifndef NUMBERCONVERSION_H
#define NUMBERCONVERSION_H
#include <iostream>
#include <cmath>
using namespace std;
string decToBin(string dec);
string decToHex(string dec);
string decToOct(string dec);

string binToDec(string bin);
string binToHex(string bin);
string binToOct(string bin);

string hexToDec(string hex);

string octToDec(string oct);
string getHex(int val);
int getDec(char ch);
#endif // NUMBERCONVERSION_H
