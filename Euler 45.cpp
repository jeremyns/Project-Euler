#include <vector>
using namespace::std;
int main()
{
    int t=1,p=1,h=1,cont=0;
    vector<int> vh;
    vector<int> vhp;
    for(int i=2;cont<2;i++)
    {
        t+=i; p+=3*i-2; h+=4*i-3;
        vh.push_back(h);
        if(p>=vh[0])
        {
            if(p==vh[0]) vhp.push_back(p);
            vh.erase(vh.begin());
        }
        if(vhp.size()>0&&t>=vhp[0])
        {
            if(t==vhp[0])cont++;
            vhp.erase(vhp.begin());
        }
    }
 return t;
}
