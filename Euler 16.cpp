#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> a;
    a.push_back(1);
    for(int i=0;i<1000;i++)
    {
        if(a.back()!=0) a.push_back(0);
        for(int k=a.size()-1;k>=0;k--)
        {
            a[k]*=2;
            if(a[k]>=10) a[k+1]++;
            a[k]%=10;
        }
    }
    int c=0;
    for(int i=0;i<a.size();i++) c+=a[i];
    return c;
}
