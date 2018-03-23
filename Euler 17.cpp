#include <iostream>
#include <vector>
int letterValue(int i);
int singleDigitValue(int i);
int doubleDigitValue(int i);
int tripleDigitValue(int i){return singleDigitValue(i)+7;};

using namespace std;
int main()
{
    int c=0;
    for(int i =1;i<=1000;i++)
        c+=letterValue(i);
    return c;
}

int letterValue(int i)
{
    int c=0;
    if(i==1000) return 11;
    if(i>100&&i%100!=0) c+=3;
    if(i>99) {c+=tripleDigitValue(i/100);i%=100;}
    if(i>15) {c+=doubleDigitValue(i/10);i%=10;}
    else if(i>=10) {c+=doubleDigitValue(i);i=0;}
    c+=singleDigitValue(i);
    return c;
}
int singleDigitValue(int i)
{
    switch (i){
    case 1: case 2: case 6: return 3; break;
    case 4: case 5: case 9: return 4; break;
    case 3: case 7: case 8: return 5; break;
    default: return 0;
    }
}
int doubleDigitValue(int i)
{
    switch (i){
    case 10:          return 3; break;
    case 1:           return 4; break;
    case 5:  case 6:  case 4: case 12:
                      return 5; break;
    case 2:  case 3:  case 8: case 9:
    case 11:          return 6; break;
    case 7:  case 15: return 7; break;
    case 13: case 14: return 8; break;
    default: return 0;
    }
}
