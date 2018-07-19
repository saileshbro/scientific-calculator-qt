#include "getfactorial.h"

unsigned long long getFactorial(unsigned long long s){
    if(s>1)
        return(s*getFactorial(s-1));
    else return 1;
}
