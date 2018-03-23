#include <fstream>
void parse(int b[15][15]);
using namespace std;
int main()
{
    int b[15][15];
    parse(b);
    for(int i=1;i<15;i++)
    {
        b[i][0]+=b[i-1][0];
        b[i][i]+=b[i-1][i-1];
        for(int j=1;j<i;j++) b[i][j]+=max(b[i-1][j],b[i-1][j-1]);
    }
    int a=0;
    for(int i=0;i<15;i++) if(b[14][i]>a) a=b[14][i];
    return a;
}
void parse(int b[15][15])
{
    ifstream lst;
    lst.open("list.txt");
    for(int i=0;!lst.eof();i++)
        for(int j=0;j<=i;j++)
            {
                b[i][j]=(lst.get()-48)*10+lst.get()-48;
                lst.get();
            }
}
