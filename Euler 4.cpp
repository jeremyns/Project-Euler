bool isPalindrome(int n);
int combinations();
int main()
{
    return combinations();
}
bool isPalindrome(int n)            //returns true only for 6 digit palindromes
{                                   //which is exactly what our answer will be
    int c=0;
    for(int i = 100; i>0; i/=10)    //cuts off last three digits and reverses them
    {
        c+=(n%10)*i;
        n/=10;
    }
    return c==n;                    //compares first 3 digits to reversed last 3 digits
}

int combinations()
{
    int ans[2] = {0,0};
    for(int i=999;i>0;i--)
        for(int j=i;j>0&&j*i>ans[0]*ans[1];j--)     //tries different combinations of answer but
        if(isPalindrome(j*i)&&j*i>ans[0]*ans[1])    //stops trying if the product of combinations is less that that
        {                                           //of any previous solutions
            ans[0]=i;
            ans[1]=j;
        }
    return ans[0]*ans[1];                           //returns answer
}
