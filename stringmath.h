#ifndef STRINGMATH_H
#define STRINGMATH_H
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#define PI 3.14159265358979323846
using namespace std;

string strtolower(string s);
string strip_spaces(string s);
vector <string> split(string s, string delimiter);
int countOccurances(string haystack, string needle);
int findLeftPos(string expression, int e);
string processExponential(string expression);
int findRightPos(string expression, int e);
string processArithmetic(string expression);
string processFunctions(string s);
string processSum(string s);


#endif // STRINGMATH_H
