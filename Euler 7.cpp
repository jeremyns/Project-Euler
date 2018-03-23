#include <iostream>
bool isPrime(int n, int prime[10000]);
int main()
{
    int prime[10000];           //since we are generating our primes in order we can save time by keeping track
    prime[0]=3;                 //of primes that we have already found
    for(int i=0;i<9999;i++)     //starting at three since we are ignoring even numbers
    {
        int p=prime[i]+2;                     //start looking for our next prime after our previous one
        while(!isPrime(p,prime))p+=2;         //keep looking until we've found oure next one.
        prime[i+1]=p;                         //store our next prime
    }
    return prime[9999];
}
bool isPrime(int n, int prime[10000])
{
    for(int i=0;prime[i]*prime[i]<=n;i++)     //only check division with prime numbers and only until we reach the square root
        if(n%prime[i]==0) return false;
    return true;
}


