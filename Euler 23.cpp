#include <vector>
int dSum(int x);
using namespace std;
int main()
{
    long long int c=0;
    int a[28123];
    vector<int> v;
    for (int i=1;i<=28123;i++)
    {
        a[i]=i;
        if(dSum(i)>i)v.push_back(i);
    }
    for(int i=0;i<v.size();i++)
        for(int k=i;k<v.size();k++)
            if(28123>v[i]+v[k]) a[v[i]+v[k]]=0;
    for (int i=0;i<28123;i++) c+=a[i];
    return c;
}
int dSum(int x)
{
    int c=1;
    int i;
    for(i=2;i*i<=x;i++) if(x%i==0) c+=x/i+i;
    i--;
    if(i*i==x)c-=i;
    return c;
}
