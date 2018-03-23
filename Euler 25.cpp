#include <iostream>
void addArray(int a[], int b[]);
void alternate(int a[], int b[], int &c){addArray(a,b);c++;if(a[999]!=0) std::cout<<c;}
int main()
{
    int a[1000],b[1000];
    int c=2;
    a[0]=1,b[0]=1;
    for(int i=1;i<1000;i++){a[i]=0;b[i]=0;}
    while(a[999]==0&&b[999]==0){alternate(a,b,c);alternate(b,a,c);}
    return 0;
}

void addArray(int a[], int b[])
{
    int c=1000;
    while (a[c-1]==0&&b[c-1]==0) c--;
    for(int i=0;i<c;i++)
    {
        a[i]+=b[i];
        if (a[i]>=10){a[i]-=10;a[i+1]++;}
    }
}
