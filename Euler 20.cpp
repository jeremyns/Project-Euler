#include <vector>
using namespace std;
int main()
{
    vector<int> a;
    int push[4]={0,0,0,0};
    a.push_back(1);
    a.push_back(0);
    int c=0;
    for(int i=2;i<=100;i++)
    {
        for(int k=0;k<a.size();k++)
        {
            if(k==a.size()-2&&a[k]!=0) for(int j=0;j<4;j++)a.push_back(0);
            a[k]*=i;
            if(a[k]>=1000)
            {
                push[(k+3)%4]+=a[k]/1000;
                a[k]=a[k]%1000;
            }
            a[k]+=push[k%4];
            push[k%4]=0;
            if(a[k]>=10)
            {
                push[(k+1)%4]+=a[k]/10;
                a[k]=a[k]%10;
            }
        }
    }
    for(int i=0;i<a.size();i++)c+=a[i];
    return c;
}


