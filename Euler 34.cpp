#include <iostream>
#include <vector>
using namespace::std;
int fSum(int x, int f[]){int s=0;for(x;x>0;x/=10)s+=f[x%10];return s;}
int main()
{
    int factorial[10];
    factorial[0]=1;
    for(int i=1;i<10;i++)factorial[i]=factorial[i-1]*i;
    int c=0;
    for(int i=3;i<9*factorial[9];i++)
        if(i==fSum(i,factorial)) c+=i;
    return c;
}
