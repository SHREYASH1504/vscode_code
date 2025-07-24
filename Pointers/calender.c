#include<stdio.h>

int is_leap(int y);
int days_in_month(int m,int y);
void printcalendar(int m,int y);
int week_day_number(int d,int m,int y);
long int dd(int d1,int m1,int y1,int d2,int m2,int y2);
long int ddy(int y1,int y2);
long int ddm(int y,int m1,int m2);
long int Janma(int d,int m,int y);
long int Raupya(int d,int m,int y);
long int Suvarna(int d,int m,int y);
long int Hirak(int d,int m,int y);
long int Amrut(int d,int m,int y);
long int Shatabdi(int d,int m,int y);
void name_of_day(int d);
void name_of_month(int d);


int main()
{
    int d,m,y;
    printf("\nGive your date of birth(dd mm yyyy) : ");
    scanf("%d %d %d",&d,&m,&y);
    printf("\n\nHere is calendar of your birth month:\n");
    printcalendar(m,y);
    printf("\n\nFollowing are the important dates in your life:\n");
    Janma(d,m,y);
    Raupya(d,m,y);
    Suvarna(d,m,y);
    Hirak(d,m,y);
    Amrut(d,m,y);
    Shatabdi(d,m,y);
    printf("\n");
}
int is_leap(int y)
{
    /*
    this function tells as if a given year is a leap year
    input y:year number(4 digit)
    return value 1 : leap year, 0 : not a leap year 
    */

    if(y%100==0)
        if(y%400==0) return 1;
        else return 0;
    else 
        if(y%4==0) return 1;
        else return 0;
}

int days_in_month(int m,int y)
{
    /*
    this function gives no of days in given month
    input m:month no (1 to 12) , y:year no (4 digit)
    retun value :no of days in given month(28/29/30/31)
    */

    int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(is_leap(y) && m==2)  return 29;
    return days[m];
}

void printcalendar(int m,int y)
{
    /*
    this function print calendar of given month
    input m:month no (1 to 12) , y:year no (4 digit)
    return value :no
    output:
    */
    int n=days_in_month(m,y);
    int start=week_day_number(1,m,y);
    printf("\nSun\tMon\tTue\tWen\tThus\tfri\tSat\n");

    for (int i = 0; i < start; i++)
    {
        printf("\t");
    }
    int pos=start;
    for (int i = 1; i <= n; i++)
    {
        printf("%2d\t",i);
        pos++;
        if (pos==7)
        {
            printf("\n");
            pos=0;
        }
        
    }
    
}

int week_day_number(int d,int m,int y)
{
    /*
    this function gives week day number for a given date
    intput: d:day of month(1 to 31),m:month no (1 to 12) , y:year no (4 digit)
    output: week day no(0 to 6)
    0:sun,1:mon,...,6:sat
    */

    int rd=13;
    int rm=1;
    int ry=2023;
    int rdow=5;
    long int days=dd(rd,rm,ry,d,m,y);
    int dow = (rdow + days)%7;
    dow = (dow + 7)%7;
    
    
    return dow;

}

long int dd(int d1,int m1,int y1,int d2,int m2,int y2)
{
    /*
    gives no of days between given two dates
    intput:d1,m1,y1:day,no month no and year no of first day
    d2,m2,y2:day no, month no and year no of second day
    output:day difference between first day and second day 
    if first day is smaller than second day then return value :positive
    if first day is greater than second day then return value :negative
    if first day is equal to second day then return value :zero  
    */
    
    return ddy(y1,y2)+(ddm(y2,1,m2)+d2)-(ddm(y1,1,m1)+d1);
}

long int ddy(int y1,int y2)
{
    /*
    this function calculates no of days between 1 jan of year y1 to 1st jan of year y2
    intput :y1 year 1(4 digit)
    y2 year 2(4 digit)
    output:no of days 
    y1<y2: positive no
    y1>y2: negative no
    y1=y2: zero
    */

    long int days=0;
    int temp,flag=0;
    if(y1>y2)
    {
        int temp=y1;
        y1=y2;
        y2=temp;
        flag=1;
    }
    for(int i=y1;i<y2;i++)   
        days+=365+is_leap(i);

    if (flag==1){
       days=-days;
    }
    return days;
}

long int ddm(int y,int m1,int m2)
{
    /*
    this function return no of days between 1st day of month m1 to 1st day of m2 for year y
    intput :y year no ,m1 :month no (1 to 12),m2: 2nd month no(1 to 12)
    output:no of days
    m1<m2:positive
    m1>m2:negative
    m1=m2:zero
    */
   int temp,flag=0;
   if(m1>m2)
   {
      temp=m1;
      m1=m2;
      m2=temp;
      flag=1;
    }
    int days=0;
    for(int i=m1;i<m2;i++){
      days+=days_in_month(i,y);
    }

    if (flag==1){
      days=-days;
    }
    return days;  
}

long int Janma(int d,int m,int y)
{
    int a,b;
    a=week_day_number(d,m,y);
    b=dd(d,m,y,d,m,y);
    printf("\nJanma dinank    :");
    name_of_day(a);
    printf(", %d ",d);
    name_of_month(m);
    printf("%d\t\t",y);
    printf("Your age in days: %5d ",b);
    
}

long int Raupya(int d,int m,int y)
{
    int a,b;
    a=week_day_number(d,m,y+25);
    b=dd(d,m,y,d,m,y+25);
    printf("\nRaupya Mahotsav :");
    name_of_day(a);
    printf(", %d ",d);
    name_of_month(m);
    printf("%d\t\t",y+25);
    printf("Your age in days: %5d ",b);
    
}

long int Suvarna(int d,int m,int y)
{
    int a,b;
    a=week_day_number(d,m,y+50);
    b=dd(d,m,y,d,m,y+50);
    printf("\nSuvarna Mahotsav:");
    name_of_day(a);
    printf(", %d ",d);
    name_of_month(m);
    printf("%d\t\t",y+50);
    printf("Your age in days: %5d ",b);
    
}

long int Hirak(int d,int m,int y)
{
    int a,b;
    a=week_day_number(d,m,y+60);
    b=dd(d,m,y,d,m,y+60);
    printf("\nHirak Mahotsav  :");
    name_of_day(a);
    printf(", %d ",d);
    name_of_month(m);
    printf("%d\t\t",y+60);
    printf("Your age in days: %5d ",b);
    
}

long int Amrut(int d,int m,int y)
{
    int a,b;
    a=week_day_number(d,m,y+75);
    b=dd(d,m,y,d,m,y+75);
    printf("\nAmrut Mahotsav  :");
    name_of_day(a);
    printf(", %d ",d);
    name_of_month(m);
    printf("%d\t\t",y+75);
    printf("Your age in days: %5d ",b);
    
}

long int Shatabdi(int d,int m,int y)
{
    int a,b;
    a=week_day_number(d,m,y+100);
    b=dd(d,m,y,d,m,y+100);
    printf("\nJanma Shatabdi  :");
    name_of_day(a);
    printf(", %d ",d);
    name_of_month(m);
    printf("%d\t\t",y+100);
    printf("Your age in days: %5d ",b);
    
}

void name_of_day(int d)
{
    if (d==0)
    {
        printf("Sunday   ");
    }
    if (d==1)
    {
        printf("Monday   ");
    }
    if (d==2)
    {
        printf("Tuesday  ");
    }
    if (d==3)
    {
        printf("Wednesday");
    }
    if (d==4)
    {
        printf("Thursday ");
    }
    if (d==5)
    {
        printf("Friday   ");
    }
    if (d==6)
    {
        printf("Saturday ");
    }
    
}

void name_of_month(int d)
{ 
    if (d==1)
    {
        printf("January ");
    }
    if (d==2)
    {
        printf("February ");
    }
    if (d==3)
    {
        printf("March ");
    }
    if (d==4)
    {
        printf("April ");
    }
    if (d==5)
    {
        printf("May ");
    }
    if (d==6)
    {
        printf("June ");
    }
    if (d==7)
    {
        printf("July ");
    }
    if (d==8)
    {
        printf("August ");
    }
    if (d==9)
    {
        printf("September ");
    }
    if (d==10)
    {
        printf("October ");
    }
    if (d==11)
    {
        printf("November ");
    }
    if (d==12)
    {
        printf("December ");
    }
}