int main()
{
    int a=1,b=1,ans=0,lim=4000000;
    for(int i=0;a<lim;i++)
    {                           //every third Fibonacci number is even
        if(i%3==1&&a<lim) ans+=a;      //so a will be even whenever i%3 == 1
        else if(i%3==2&&b<lim)ans+=b;  //and b will be even when i%3 == 2
        a+=b;                   //next term for a.
        b+=a;                   //next term for b.
    }
    return ans;
}
