#include <fstream>
#include <iostream>
void parse(int b[400]);
long long int getLargestGridProduct(int arr[1000],int length);
long long int check(int arr[400], int start, int span, int length, int finish );
long long int setProduct(int arr[400], int start, int span, int length);
using namespace::std;int main()
{
    int arr[400];
    parse(arr);
    int length=4;
    cout<<getLargestGridProduct(arr,4);
    return 0;
}
long long int getLargestGridProduct(int arr[1000],int length)
{

    long long int ans=0,temp=0;
    for(int i=0;i<400;i+=20)                    //horizontal
    {
        temp = check(arr,i,1,length,i+20-length);
        if(ans<temp)ans=temp;
    }
    for(int i=0;i<20;i++)                       //vertical
    {
        temp = check(arr,i,20,length,400-20*length);
        if(ans<temp)ans=temp;
    }
    for(int i=0;i<400-20*length;i+=20)
    {                                           //forward diagonal 1st half
        temp = check(arr,i,21,length,400-21*length);
        if(ans<temp)ans=temp;
    }
    for(int i=0;i<20-length;i++)
    {                                           //forward diagonal 2nd half
        temp = check(arr,i,21,length,400-21*length);
        if(ans<temp)ans=temp;
    }
    for(int i=19;i<400-20*length;i+=20)
    {                                           //backward diagonal 1st half
        temp = check(arr,i,19,length,380-19*length);
        if(ans<temp)ans=temp;
    }
    for(int i=length;i<20;i++)
    {                                           //backward diagonal 2nd half
        temp = check(arr,i,19,length,380-19*length);
        if(ans<temp)ans=temp;
    }
}
long long int check(int arr[400], int start, int span, int length, int finish )
{
    long long int ans=0,current = setProduct(arr,start,span,length);
    int flag=0;
    for(int j=start;j<finish;j+=span)
    {
        flag--;
        if(arr[j+length*span]==-1) flag=length;             //if there is a zero in the product then a flag is raised, that will go away when zero is no longer inside of the product
        current*=arr[j+length*span];                        //instead of creating a new product for every location there is only one product
        current/=arr[j];                                    //that is modified to fit each location, thereby eliminating a lot of uneccessary multiplication
        if(ans<current&&flag<=0) ans=current;
     /*   if(current>10000000)
        {
            cout<<current<<"\t";
            for(int i=0;i<4;i++) cout<<arr[j+i*span]<<" ";
            cout<<endl;
        }*/
    }
    return ans;
}

long long int setProduct(int arr[400], int start, int span, int length)
{
    long long int s=1;
    for(int i=start;i<span*length+start;i+=span) s*=arr[i];
    return s;
}

void parse(int b[400])
{
    ifstream lst;
    lst.open("list.txt");
    for(int i=0;i<400;i++)
    {
        //if(i%20==0&&i>0) lst.get();
        b[i]=(lst.get()-48)*10+lst.get()-48;
        lst.get();
        if(b[i]==0) b[i]--;                 //change zeros to -1 so it will not ruin our product
    }
    lst.close();
}

