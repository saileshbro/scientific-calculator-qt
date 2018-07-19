#include "reversestring.h"
std::string reversestr (std::string str){
  std::string temp;
  for(int i=str.length();i>=0;i--){
    temp=temp+str[i];
  }
  return temp.substr(1);
}
