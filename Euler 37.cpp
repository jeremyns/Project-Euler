#include <vector>
#include <iostream>
int ee(int d){int e=1;while(d>0){d--;e*=10;}return e;}
bool isPrime(int x);
using namespace::std;
int main()
{
    int c=0,d=0;
    vector <int> v; v.push_back(1); v.push_back(1);
    while(c<11)
    {
        v[0]+=2;
        int sum=0;
        bool tPrime=true;
        for(int j=0; j<v.size();j++)
        if(v[j]>=10)
            {
                v[j]=1;
                if(j==v.size()-1) v.push_back(1);
                else if(j<v.size()-2) v[j+1]+=2;
                else v[j+1]++;
            }
        for(int j=0; j<v.size()&&tPrime;j++)
        {
            sum+=v[j]*ee(j);
            int d2=0;
            for(int k=0;k<=j;k++) d2+=v[v.size()-k-1]*ee(j-k);
            if(!isPrime(sum)||!isPrime(d2)) tPrime=false;
        }
        if(tPrime&&isPrime(sum)) {c++; d+=sum;}
    }
    return d;
}
bool isPrime(int x)
{
    if(x==2) return true;
    else if(x%2==0||x==1) return false;
    for(int i=3;i*i<=x;i+=2)
        if(x%i==0) return false;
    return true;
}
