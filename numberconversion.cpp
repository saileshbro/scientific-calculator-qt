#include"numberconversion.h"

string binToDec(string bin){
   if(bin=="")
       return "";
   else{
      int i = bin.length();
      int dec = 0;
      for (auto& bit : bin){
        i--;
        dec = dec + ((int)bit - (int)'0') * pow(2,i);
      }
      return to_string(dec);
   }
}
string decToBin(string dec){
  string bin = "";
  int decimal;
  if(dec=="")
    decimal = 0;
  else
      decimal= stoi(dec);

  while(decimal != 0){
    bin = to_string(decimal%2)+bin;
    decimal = decimal / 2;
  }

  return bin;
}
string decToHex(string dec){
  int decimal;

  string hex = "";
  if(dec=="")
    decimal = 0;
  else
      decimal= stoi(dec);

  while(decimal != 0){
    hex = getHex(decimal%16)+hex;
    decimal = decimal / 16;
  }
  return hex;
}
string getHex(int val){
  if (val == 10) {
    return "A";
  } else if (val == 11) {
    return "B";
  } else if (val == 12){
    return "C";
  } else if (val == 13){
    return "D";
  } else if (val == 14){
    return "E";
  } else if (val == 15){
    return "F";
  } else {
    return to_string(val);
  }
}
int getDec(char ch){
  string val = "";
  val = val + ch;
  if (val == "A" ||val == "a"){
    return 10;
  } else if (val == "B"||val == "b"){
    return 11;
  } else if (val == "C"||val == "c"){
    return 12;
  } else if (val == "D"||val == "d"){
    return 13;
  } else if (val == "E"||val == "e"){
    return 14;
  } else if (val == "F"||val == "f"){
    return 15;
  } else {
    return stoi(val);
  }
}
string hexToDec(string hex){
  if(hex=="")
       return "";
   else{
      int i = hex.length();
      int dec = 0;
      for (auto& bit : hex){
        i--;
        dec = dec + getDec(bit) * pow(16,i);
      }
      return to_string(dec);
   }
}
string decToOct(string dec){
  string bin = "";
  int decimal;
  if(dec=="")
    decimal = 0;
  else
      decimal= stoi(dec);

  while(decimal != 0){
    bin = to_string(decimal%8)+bin;
    decimal = decimal / 8;
  }

  return bin;
}
string binToHex(string bin){
    return decToHex(binToDec(bin));
}
string binToOct(string bin){
    return decToOct(binToDec(bin));
}
string octToDec(string oct){
    if(oct=="")
        return "";
    else{
       int i = oct.length();
       int dec = 0;
       for (auto& bit : oct){
         i--;
         dec = dec + ((int)bit - (int)'0') * pow(8,i);
       }
       return to_string(dec);
    }
 }
