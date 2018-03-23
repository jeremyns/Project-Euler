int dSum(int x);
int main()
{
   int c=0;
   for(int i=3;i<10000;i++)
   if(i==dSum(dSum(i))&&i!=dSum(i)) c+=i;
return c;
}
int dSum(int x)
{
    int y=1;
    for (int i=2;i*i<=x;i++)
            if(x%i==0)
                if(x!=i*i) y+=i+x/i;
                else y = y+i;
    return y;
}

