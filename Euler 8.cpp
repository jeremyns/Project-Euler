#include <iostream>
#include <fstream>
//#include "BigInteger.cpp"
void parse(int b[1000]);
//BigInteger getLargestGridProduct(int arr[1000],int length);
//BigInteger check(int arr[1000], int start, int span, int length, int finish );
//BigInteger setProduct(int arr[1000], int start, int span, int length);
long long int check(int arr[1000], int start, int span, int length, int finish );
long long int setProduct(int arr[1000], int start, int span, int length);
using namespace::std;
/*
this is currently set up to find the largest product in a series on numbers, however it can also be converted to find the largest
product horizontally, vertically, or diagonally by swapping in the commented out code.
*/
int main()
{
    int arr[1000];
    parse(arr);
    int length=13;
//    cout<<string(check(arr,0,1,length,1000-length));
    cout<<check(arr,0,1,length,1000-length);
    return 0;
}

void parse(int b[1000])
{
    ifstream lst;
    lst.open("list.txt");
    for(int i=0;i<1000;i++)
    {
        if(i%50==0&&i>0) lst.get();
        b[i]=lst.get()-48;
        if(b[i]==0) b[i]--;                 //change zeros to -1 so it will not ruin our product
    }
}

/*BigInteger getLargestGridProduct(int arr[1000],int length)
{
    BigInteger ans(0);
    BigInteger temp(0);
    for(int i=0;i<1000;i+=50)
    {
        temp = check(arr,i,1,length,i+50-length);
        if(ans<temp)ans=temp;
    }
    for(int i=0;i<50;i++)
    {
        temp = check(arr,i,50,length,1000-50*length);
        if(ans<temp)ans=temp;
    }
    for(int i=0;i<1000-50*length;i+=50)
    {
        temp = check(arr,i,51,length,1000-51*length);
        if(ans<temp)ans=temp;
    }
    for(int i=0;i<50-length;i++)
    {
        temp = check(arr,i,51,length,1000-51*length);
        if(ans<temp)ans=temp;
    }
    for(int i=49;i<1000-50*length;i+=50)
    {
        temp = check(arr,i,49,length,950-49*length);
        if(ans<temp)ans=temp;
    }
    for(int i=length;i<50;i++)
    {
        temp = check(arr,i,49,length,950-49*length);
        if(ans<temp)ans=temp;
    }
}*/

//BigInteger check(int arr[1000], int start, int span, int length, int finish )
long long int check(int arr[1000], int start, int span, int length, int finish )
{
   // BigInteger ans=0,current = setProduct(arr,start,span,length);
    long long int ans=0,current = setProduct(arr,start,span,length);
    int flag=0;
    for(int j=start;j<finish;j+=span)
    {
        flag--;
        if(arr[j+length*span]==-1) flag=length;             //if there is a zero in the product then a flag is raised, that will go away when zero is no longer inside of the product
        current*=arr[j+length*span];                        //instead of creating a new product for every location there is only one product
        current/=arr[j];                                    //that is modified to fit each location, thereby eliminating a lot of uneccessary multiplication
        if(ans<current&&flag<0) ans=current;
    }
    return ans;
}

//BigInteger setProduct(int arr[1000], int start, int span, int length)
long long int setProduct(int arr[1000], int start, int span, int length)
{
   // BigInteger s=1;
    long long int s=1;
    for(int i=start;i<span*length+start;i+=span) s*=arr[i];
    return s;
}
