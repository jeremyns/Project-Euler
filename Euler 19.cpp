int daysMonth(int month,int year);
int main()
{
    int day=1,sunday=0;
    for (int i=1900; i<=2000;i++)
        for (int j=1;j<=12;j++)
        {
            day+=daysMonth(j,i);
            if(day%7==0&&i>1900) sunday++;
        }
    return sunday;
}
int daysMonth(int month, int year)
{
    switch(month){
        case 4: case 6: case 9: case 11:
            return 30;
            break;
        case 2:
            if(year%4==0&&year%100!=0||year%400==0)
                return 29;
                else return 28;
            break;
        default:
            return 31;
    }
}
