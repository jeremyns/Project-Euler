#include <iostream>
#include <vector>
using namespace::std;
int log(int x){int i=0;for(i;x>0;i++)x/=10;return i;}
int e(int x){int p=1;for(int i=0;i<x;i++)p*=10;return p;}
long long int convert(vector<int> v)
{
    long long int x=v.back();
    for(int i=v.size()-2;i>=0;i--)
        x+=v[i]*e(log(x));
    return x;
}
bool check(vector<int>v)
{
    int a[9]={0,0,0,0,0,0,0,0,0};
    for(int i=0;i<v.size();i++)
        while(v[i]>0)
    {
        a[v[i]%10]=v[i]%10;
        v[i]/=10;
    }
    for(int i=0;i<9;i++)
        if(a[i]!=i) return false;
    return true;
}
int main()
{
    int c=0;
    for(int i=1;i<10000;i++)
    {
        int d=0;
        int s=i;
        vector<int> v;
        while(d<=9)
        {
            d+= log(s);
            v.push_back(s);
            s+=i;
            if(d==9&&check(v)&&convert(v)>c) c=convert(v);
        }
    }
    return c;
}
