#include <iostream>
int main()
{
    long long int x=21,a=1,b=1;
    while(x<41) {a*=x++;a/=b++;}
    std::cout<<a;
    return 0;
}

