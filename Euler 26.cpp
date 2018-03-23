int main()
{
    int c[2]={0,0};
    for(int i=3;i<1000;i+=2)
    {
        if(i%10==5) i+=2;
        int d=1,j=10;
        while(j>1)
        {
            while(j<=i&&j>1){j*=10;d++;}
            j-=i;
        }
        if(d>c[0]){c[0]=d;c[1]=i;}
    }
    return c[1];
}
