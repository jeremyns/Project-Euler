bool isPrime(int x);
bool check(int x, int d);
int e(int d){int e=10;for(int i=0;i<d;i++)e*=10;return e;}
int l(int d){int e=0;for(int i=0;d>0;i++){d/=10;e++;}return e-1;}
int main()
{
    int c=0;
    for(int i=1;i<1000000;i+=2)
    {
        for(int j=0;j<l(i);j++) if(i/e(j)%2==0&&i>e(j)) i+=e(j);
        if (check(i,l(i)-1)) c++;
    }
    return c;
}
bool isPrime(int x)
{
    for(int i=3;i*i<=x;i+=2)if(x%i==0) return false;
    return true;
}
bool check(int x, int d)
{
    for(int i=0;i<d+2;i++)
    {
        if(!isPrime(x)) return false;
        int t=(x%10)*e(d);
        x/=10;
        x+=t;
    }
    return true;
}
