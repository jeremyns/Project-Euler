int divisors(int x);
int main()
{
    int c=1;
    for(int i=2;divisors(c)<500;i++) c+=i;         //if c has more than 500 divisors, where c is a triangle number
    return c;
}

int divisors(int x)
{
    int square=0;                               //will be set to 1 if number is perfect square
    int c=0,s=4,t=3;                            //s and t will compute next perfect square value with addition instead of multiplication
    for(int i=2;s<=x;i++)
    {
        t+=2;
        s+=t;
        if(x%i==0) c++;                         //each divisor has a reflection across the square root
        if(s==x) square++;                      //divisor has no reflection is it is the square root
    }
    return c*2-square;
}
