#include <iostream>
#include <vector>
using namespace::std;
int log(int x, int b){int i=0;for(i;x>=1;i++)x/=b;return i;}
int pow(int x, int e){int p=1;for(int i=0;i<x;i++)p*=e;return p;}
int getDigit(int x,int a, int b){return x/pow(a,b)%b;}
bool pCheck(int x,int b)
{int s=log(x,b)-1;for(int j=0;j<=s;j++)if(getDigit(x,j,b)!=getDigit(x,s-j,b)) return false;}
int main()
{
    int c=0,j=2;
    for (int i=1;i<1000000;i+=j)
    {
        while(i%10!=i/pow(log(i,10)-1,10)) i+=j;
        if(pCheck(i,10)&&pCheck(i,2)) c+=i;
    }
    return c;
}
