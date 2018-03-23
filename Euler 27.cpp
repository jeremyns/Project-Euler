bool isPrime(int x)
{
    if(x%2==0||x<2)return false;
    for(int i=3;i*i<=x;i+=2) if(x%i==0) return false;
    return true;
}
int consecutive(int f, int b)
{
    int k=0,c=0;
    for(int i=b;isPrime(f+k);i+=2) {k+=i;c++;}
    return c;
}
int main()
{
    int c[2]={0,0};
    for(int i=-999;i<1000;i+=2) for(int j=i;j<1000;j+=2)
    {int p=consecutive(j,i+1); if(p>c[0]){c[0]=p;c[1]=i*j;}}
    return c[1];
}
