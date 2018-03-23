int main()
{
    long long int a=0;
    int b[2]={0,0};
    for(int i=3;i<1000000;i+=2)
    {
        a=i;
        int c=0;
        while(a>2)
        {
            while(a%2==0) {a/=2; c++;}
            while(a%2==1) {a+=a/2+1; c+=2;}
        }
        if(c>b[1]){b[0] = i;b[1]=c;}
    }
    return b[0];
}

