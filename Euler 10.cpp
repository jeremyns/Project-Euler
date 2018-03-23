#include <iostream>
bool isPrime(long long int x);
int main()
{
    long long int c=2;                   //initialize sum to the value of the only even prime
    for(int i=3;i<2000000;i+=2)if(isPrime(i)) c+=i; //only check odd numbers
    std::cout<<c;
    return 0;
}

bool isPrime(long long int x)
{
    for (int i=3;i*i<=x;i+=2) if (x%i==0) return false;  //prime check for odd positive numbers
    return true;
}
