#include"getdeterminant.h"
long double getDeterminant(double a[][3]){
    long double ans;
    ans=a[0][0]*(a[1][1]*a[2][2]-a[2][1]*a[1][2])-a[0][1]*(a[1][0]*a[2][2]-a[2][0]*a[1][2])+a[0][2]*(a[1][0]*a[2][1]-a[1][1]*a[2][0]);
    return ans;
}
