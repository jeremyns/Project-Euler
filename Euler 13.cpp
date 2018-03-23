#include <iostream>
#include <fstream>
void parse(int nums[100][50]);
void sum(int nums[100][50]);
using namespace::std;
int main()
{
    int nums[100][50];
    parse(nums);
    sum(nums);
    return 0;
}
void sum(int nums[100][50])
{
    for(int i=0;i<50;i++) for(int j=0;j<99;j++) nums[j+1][i]+=nums[j][i];
    for(int i=49;i>=0;i--) nums[99][i-1]+=nums[99][i]/10;
    cout<<nums[99][0];
    for(int i=1;i<7;i++) cout<<nums[99][i]%10;
}
void parse(int nums[100][50])
{
    ifstream lst;
    lst.open("list.txt");
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<50;j++) nums[i][j]=lst.get()-48;
        lst.get();
    }
}
