#include <iostream>
using namespace std;
int main()
{
    int c=1,t=1;
    for(int i=2;i<1001;i+=2)for(int j=0;j<4;j++){t+=i;c+=t;}
    return c;
}
