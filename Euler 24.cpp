#include <iostream>
#include <vector>
using namespace::std;
int factorial(int x){int i=1;for(x;x>0;x--)i*=x;return i;}
int main()
{
    int c=1000000-1;
    vector <int> v;
    for(int i=0;i<=9;i++) v.push_back(i);
    for(int i=9;i>=0;i--)
    {
        c%=factorial(i+1);
        int f=c/factorial(i);
        cout<<v[f];
        v.erase(v.begin()+f);
    }
    return 0;
}
