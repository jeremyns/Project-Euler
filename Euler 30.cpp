#include <iostream>
int main()
{
    int pow[10];
    int d[5][10];
    int c=-1;
    for(int i=0;i<10;i++)
    {
        pow[i]=i*i*i*i*i;
        d[0][i]=i*10;
        for(int j=1;j<5;j++) d[j][i]=d[j-1][i]*10;
    }
    for(int q=0;q<10;q++)
    for(int w=0;w<10;w++)
    for(int e=0;e<10;e++)
    for(int r=0;r<10;r++)
    for(int t=0;t<10;t++)
    for(int y=0;y<10;y++)
        if(pow[q]+pow[w]+pow[e]+pow[r]+pow[t]+pow[y] ==
            d[4][q]+d[3][w]+d[2][e]+d[1][r]+d[0][t]+y)
        c+=d[4][q]+d[3][w]+d[2][e]+d[1][r]+d[0][t]+y;
    return c;
}
