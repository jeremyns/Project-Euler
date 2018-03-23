#include<iostream>
int main()
{
  int squareSum = 10000*10201/4, sumSquare=0,s=0;   //(1+2..+99+100)^2== (100*101/2)^2 which simplifies to 10000*10201/4
  for(int i=0;i<100;i++)
  {
      s+=2*i+1;                                     //s will always be the next perfect square without the need for repetitive multiplication
      sumSquare+=s;                                 //0+1=1 1+3=4 4+5=9 9+7=16 ect.
  }
 return squareSum-sumSquare;
}
