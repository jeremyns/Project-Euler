#include <iostream>
using namespace::std;
int root(int b, int x);
int bSearch(int arr[], int l, int h, int n);
int main()
{
    int root[1000];                         //create an array or square roots so new roots will not need to be calculated every time
    for(int i=0;i<500;i++) root[i]=i*i;     //initialize the array
    for(int i=1;i<300;i++)                  //there is no triplet where the smallest side is greater than 300
        for(int j=i;j+i<600; j++)           //there is no triplet where the sum of a and b is larger that 600
        {
            int a=bSearch(root,0,500,i*i+j*j);      //binary search to return root of perfect square, or -1 for non perfect squares
            if(a!=-1&&a+i+j==1000) return a*i*j;    //check if numbers add to 1000
        }
    return 0;
}
int bSearch(int arr[], int l, int h, int n)
{
	if(l-h>=-1) return -1;
	int mid;
	mid=arr[(l+h)/2];
	if(mid==n) return (l+h)/2;
	else if(mid>n) return bSearch(arr,l,(l+h)/2,n);
	else if(mid<n) return bSearch(arr,(l+h)/2,h,n);
	return -1;
}
