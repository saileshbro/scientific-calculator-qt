#include "stringmath.h"

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define PI 3.14159265

using namespace std;

string strtolower(string s)
{
    string str = "";
    for(char& c : s) {
        c = tolower(c);
        str = str + c;
    }
    return str;
}

string strip_spaces(string s){
    while(s.find(" ") != -1){
        s.erase(s.find(" "),1);
    }
    return s;
}

vector <string> split(string s, string delimiter){
    vector <string> parts;
    string part;
    while(s.find(delimiter) != -1){
        part = s.substr(0,s.find(delimiter));
        s.erase(0,part.size() + delimiter.size());
        parts.push_back(part);
    }
    parts.push_back(s);
    return parts;
}

int countOccurances(string haystack, string needle){
    int count = 0;

    while(haystack.find(needle) != -1){
        haystack.erase(haystack.find(needle),needle.size());
        count++;
    }

    return count;
}

int findLeftPos(string expression, int e){
    e--;
    while(e){
        if (expression.substr(e,1) == "*" || expression.substr(e,1) == "/" || expression.substr(e,1) == "+" || expression.substr(e,1) == "-"){
            break;
        }
        e--;
    }
    return e;
}

int findRightPos(string expression, int e){
    e++;
    while(e < expression.size()){
        if (expression.substr(e,1) == "*" || expression.substr(e,1) == "/" || expression.substr(e,1) == "+" || expression.substr(e,1) == "-"){
            break;
        }
        e++;
    }
    return e;
}

string processExponential(string expression){

while(expression.find("^") != -1){
        int expPos = expression.find("^");

        int leftPos = -1, rightPos = -1;
        int e = expPos;

        string leftPart, rightPart;


        leftPos = findLeftPos(expression,e);
        rightPos = findRightPos(expression,e);

        if (leftPos == 0){
                    leftPos--;
        }

        leftPart = processArithmetic(processFunctions(expression.substr(leftPos + 1, expPos - leftPos - 1)));
        rightPart = processArithmetic(processFunctions(expression.substr(expPos + 1, rightPos - expPos - 1)));

        expression.replace(expression.find(leftPart + "^"), leftPart.size() + rightPart.size(), to_string(pow(stod(leftPart), stod(rightPart))));
    }

    return expression;

}

string processArithmetic(string expression){
    if (expression.find("^") != -1){
        expression = processExponential(expression);
    }

    vector<string> operations = {"/","*"};

    for (int i = 0; i < operations.size();i++){
        while(expression.find(operations.at(i)) != -1){
            int expPos = expression.find(operations.at(i));

            int leftPos = -1, rightPos = -1;
            int e = expPos;

            string leftPart, rightPart;
            leftPos = findLeftPos(expression,e);
            rightPos = findRightPos(expression,e);
            if (leftPos == 0){
                leftPos = leftPos - 1;
            }
            leftPart = processArithmetic(processFunctions(expression.substr(leftPos + 1, expPos - leftPos - 1)));
            rightPart = processArithmetic(processFunctions(expression.substr(expPos + 1, rightPos - expPos - 1)));

            if (operations.at(i) == "/"){
                expression.replace(expression.find(leftPart + operations.at(i)), leftPart.size() + rightPart.size(), to_string(stod(leftPart)/stod(rightPart)));
            } else if (operations.at(i) == "*"){
                expression.replace(expression.find(leftPart + operations.at(i)), leftPart.size() + rightPart.size(), to_string(stod(leftPart)*stod(rightPart)));
            }

        }
    }

    return expression;
}

void removeEmptyStrings(vector <string> &vStr){
    vector <string> vStrNew;
    for (auto &str : vStr)
    {
        if (str.size() != 0){
            vStrNew.push_back(str);
        }
    }

    vStr = vStrNew;
}

void reSplit(vector <string> &vStr, string delimiter){
    vector<string> vStrNew;
    for(auto &str : vStr){
        if (str.find(delimiter) != -1){
            vector <string> splitted = split(str, delimiter);
            vStrNew.push_back(splitted.at(0));
        } else {
            vStrNew.push_back(str);
        }
    }

    vStr = vStrNew;
}

string processSum(string s){
    if (!(s.substr(0, 1) == "+" || s.substr(0, 1) == "-")){
        s = "+" + s;
    }

    double positivePart = 0, negativePart = 0;

    vector <string> positiveSplit = split(s,"+");
    removeEmptyStrings(positiveSplit);
    reSplit(positiveSplit,"-");

    vector<string> negativeSplit = split(s, "-");
    removeEmptyStrings(negativeSplit);
    reSplit(negativeSplit, "+");

    for (auto& str : positiveSplit){
        if (str.length() > 0)
        {
            positivePart += stod(str);
        }
    }

    for (auto &str : negativeSplit)
    {
        if (str.length() > 0){
            negativePart += stod(str);
        }
    }

    return  to_string(positivePart - negativePart);

}

string processFunctions(string s){
    vector<string> functions = {"arcsin(","arctan(","arccos(","sin(","tan(","cos(","log(","ln(","sinh(","cosh(","tanh(","asinh(","acosh(","atanh("};
    vector <string> strSplit, splitExp;

    string function;

    int i, j;
    string exp, exp2;

    double val;
    double expVal;

    for (i = 0;i < functions.size();i++){
        function = functions.at(i);
        function = function.substr(0,function.size() - 1);
        if (s.find(functions.at(i)) != -1){
            strSplit = split(s,functions.at(i));

            for (j = 1; j < strSplit.size();j++){
               exp = strSplit.at(j);

               splitExp = split(exp,")");
               exp = splitExp.at(0);

               exp2 = exp;

               expVal = stod(exp);

               if(function == "sin"){
                   val = sin (expVal * PI / 180.0);
               } else if(function == "tan"){
                   val = tan (expVal * PI / 180.0);
               } else if(function == "cos"){
                   val = cos (expVal * PI / 180.0);
               } else if(function == "arctan"){
                   val = atan (expVal) * 180 / PI;
               } else if(function == "arcsin"){
                   val = asin (expVal) * 180 / PI;
               } else if(function == "arccos"){
                   val = acos (expVal) * 180 / PI;
               } else if(function == "log"){
                   val = log10 (expVal);
               } else if(function == "ln"){
                   val = log (expVal);
               } else if(function == "sinh"){
                   val = sinh (expVal * PI / 180.0);
               }else if(function == "cosh"){
                   val = cosh (expVal * PI / 180.0);
               }else if(function == "tanh"){
                   val = tanh (expVal * PI / 180.0);
               }else if(function == "asinh"){
                   val = asinh (expVal * PI / 180.0);
               }else if(function == "acosh"){
                   val = acosh (expVal * PI / 180.0);
               }else if(function == "atanh"){
                   val = atanh (expVal * PI / 180.0);
               }

               s.replace(s.find(functions.at(i)), functions.at(i).size() + exp2.size() + 1, to_string(val));
            }
        }
    }

    return s;
}

//int main(){
//    string exp = strip_spaces("9 * 5 + 27 * LOG(30) / sin(60) * 5^3 + 778 - 88 + 8843 - 727 - 829");

//    if (countOccurances(exp,"(") != countOccurances(exp,")")){
//        cout << "Syntax error" << endl;
//        return 1;
//    }

//    string a = processSum(processArithmetic(processFunctions(strtolower(exp))));
//    cout << a << endl;

//    return 0;
//}
