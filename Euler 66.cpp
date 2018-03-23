#include <iostream>
bool check(int target, int d, int add, int current);

int isSquare(long long int arr[], int l, int h, long long int n);
using namespace::std;
int main()
{
    long long int c=1,i=0,n=0,d=0;
    long long int sqr[900000];
    for(i = 0; i<900000;i++) sqr[i]= i*i;
    for(i=2;i<=  900000;i++)
    {
        n = i*i-1;
        for(d=1;d<=1000;d++)
        if(isSquare(sqr,0,i,n/d)!=-1&&n%d==0)
            {
                cout<< i << "\t"<<d<<"\t"<<isSquare(sqr,0,i,n/d)<<endl;
             d=1001;}
    }

   // if(check(i*i,d,d,1)) cout<< i << "\t"<<d<<endl;
    return c;
}
bool check(int target, int d, int add, int current)
{
    current+=add;
    add+=2*d;
    if(current < target) return check(target,d,add,current);
    else if(current==target) return true;
    else if (current > target) return false;
}
int isSquare(long long int arr[], int l, int h, long long int n)
{
	if(l-h>=-1) return -1;
	int mid;
	mid=arr[(l+h)/2];
	if(mid==n) return (l+h)/2;
	else if(mid>n) return isSquare(arr,l,(l+h)/2,n);
	else if(mid<n) return isSquare(arr,(l+h)/2,h,n);
	return -1;
}
