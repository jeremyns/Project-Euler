#include <vector>
using namespace::std;
long long int pow(int x){long long int p=1;for(int i=0;i<x;i++)p*=10;return p;}
void swap(int *a,int *b) {int temp=*a;*a=*b;*b=temp;}
void permutate(long long int a[],int i, int n);
long long int convert(long long int a[],int n){long long int x=0;for (int i=0;i<=n;i++){x+=a[i]*pow(n-i);}return x;}
bool isPrime(long long int x){if(x%2==0) return false;else for(int i=3;i*i<=x;i++)if(x%i==0) return false;return true;}
int main()
{
    long long int a[11]= {1,2,3,4,5,6,7,8,9,0,0};
    for(int i=0;i<9;i++)
    permutate(a,0,i);
    return a[10];
}
void permutate(long long int a[], int i, int n){
    int j;
    if(i==n){
        int x=convert(a,n);
        if(isPrime(x)&&x>a[10]) a[10]=x;}
    else for(j=i;j<=n;j++){
            swap(a[i],a[j]);
            permutate(a,i+1,n);
            swap(a[i],a[j]);}}
