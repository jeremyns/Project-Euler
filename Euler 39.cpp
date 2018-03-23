int solutions(int t, int sqrt[]);
int bSearch(int arr[], int l, int h, int n);
int main()
{
    int sqrt[1000];
    int sol[1000];
    int ans[2]={0,0};
    for(int i=0;i<1000;i++) {sqrt[i]=i*i; sol[i]=0;}
    for(int a=4;a<500;a++)
        for(int b=1;b<=a&&a+b<500;b++)
        {
            int c=bSearch(sqrt,a,a+b,a*a+b*b);
            if(a+b+c>1000) a=b+1;
            else if(c>0) sol[a+b+c]++;
        }
    for(int i=0;i<1000;i++) if(sol[i]>ans[1]) {ans[0]=i; ans[1]=sol[i];}
    return ans[0];
}

int bSearch(int arr[], int l, int h, int n)
{
	if(l-h>=-1) return -1;
	int mid;
	mid=arr[(l+h)/2];
	if(mid==n) return (l+h)/2;
	else if(mid>n) return bSearch(arr,l,(l+h)/2,n);
	else if(mid<n) return bSearch(arr,(l+h)/2,h,n);
	return -1;
}
