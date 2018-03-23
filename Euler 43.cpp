#include <iostream>
#include <vector>
using namespace::std;
int getNum(int a[], int x){return a[x]*100+a[x+1]*10+a[x+2];}
void swap(int *a,int *b) {int temp=*a;*a=*b;*b=temp;}
void permutate(int a[],int b[],int c[], int i, int n);

int main()
{
    int a[10]= {1,2,3,4,5,6,7,8,9,0};
    int b[7]=  {2,3,5,7,11,13,17};
    int c[12]= {0,0,0,0,0,0,0,0,0,0,0};
    permutate(a,b,c,0,9);
    for(int i=10;i>=0;i--){c[i-1]+=c[i]/10;c[i]%=10;}
    for(int i=0;i<11;i++) cout << c[i];
    return 0;
}
void permutate(int a[],int b[],int c[], int i, int n){
    int j;
    if(i==n&&a[3]%2==0&&a[5]%5==0){
        bool cont=true;
            for(j=0;j<7;j++)
                if(getNum(a,j+1)%b[j]!=0)cont=false;
            if(cont)for(j=0;j<10;j++) c[j+1]+=a[j];}
    else for(j=i;j<=n;j++){
            swap(a[i],a[j]);
            permutate(a,b,c,i+1,n);
            swap(a[i],a[j]);}}
