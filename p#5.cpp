#include <iostream>
using namespace std;

bool IsleapYear(short y)
{
	return (y% 400 == 0 || y % 4 == 0)&&(y%100!=0);
}

int DaysInyear(int year)
{
    bool isLeap = IsleapYear(year);
    if (isLeap) return 366;
    return 365;
}

int DaysInmouth(int month, int year,bool isleap)
{
    isleap = IsleapYear(year);
    if (month == 2 && isleap) return 29;
    else if (month == 2) return 28;
    else if (month % 2 == 0) return 30;
    return 31; 
}

int hoursInMonths(int DaysInmonth)
{
    return DaysInmonth * 24;
}

int minutesInMonths(int hoursInMonths)
{
    return hoursInMonths * 60;
}

int SecondsInmonth(int minutesInMonths)
{
    return minutesInMonths * 60;
}

int ReadPositifNumber(string Message)
{
    int num;
    cout << Message;
    cin >> num;
    return num;
}

int main()
{
    short year = ReadPositifNumber("enter Year : ");
    short monthnumber = ReadPositifNumber("enter month number : ");

    int Days_in_month = DaysInmouth(monthnumber, IsleapYear(year));
    int Hours_in_month = hoursInMonths(Days_in_month);
    int Minutes_in_month = minutesInMonths(Hours_in_month);
    int Seconds_in_month = SecondsInmonth(Minutes_in_month);

    cout << "year : " << year << endl;
    cout << "Month : " << monthnumber << endl;
    cout << "============================" << endl;
    cout << "days in month [" << monthnumber << "] is : " << Days_in_month << endl;
    cout << "Hours in month [" << monthnumber << "] is : " << Hours_in_month << endl;
    cout << "Minutes in month [" << monthnumber << "] is : " << Minutes_in_month << endl;
    cout << "Seconds in month [" << monthnumber << "] is : " << Seconds_in_month << endl;
    cout << "============================" << endl;

    return 0;
}