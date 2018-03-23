int main()
{
    long long int ans,num = 600851475143;
    for(ans=3;num>1;ans+=2)     //while our divisor is greater than one increment the answer to next odd number
        while(num%ans==0)       //in case our factor can be divided out multiple times
            num/=ans;           //divide ans into num
    return ans-2;                 //the second to last value on ans will be the greatest prime divisor
}
