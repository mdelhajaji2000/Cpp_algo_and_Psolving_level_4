#include <iostream>
using namespace std;

struct stDate
{
    int year;
    int month;
    int day;
};

bool IsLeapYear(int y)
{
	return (y% 400 == 0 || y % 4 == 0)&&(y%100!=0);
}

int readint(string Message)
{
    int num;
    cout << Message;
    cin >> num;

    return num;
}

short NumberOfDaysInMonth(short Month, short Year) 
{
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : ((Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31);
}

stDate TotalDaysToDate(short totalDays, short year)
{
    stDate date;

    date.year = year;
    date.month = 1;

    while (totalDays > NumberOfDaysInMonth(date.month, year))
    {
        totalDays -= NumberOfDaysInMonth(date.month, year);
        date.month++;
    }
    
    date.day = totalDays;

    while (date.month > 12)
    {
        date.month -= 12;
        date.year++;
    }
    
    return date;
}

int TotaleDaysInADate(int year, int month, int day)
{
    int DaysSum = 0;
    for (int i = month - 1; i > 0; i--)
    {
        DaysSum += NumberOfDaysInMonth(i, year);
    }
    DaysSum += day;

    return DaysSum;
}

int main()
{
    stDate date;
    int year = readint("enter year : ");
    int month = readint("enter month : ");
    int Day = readint("enter Day");

    int Totale = TotaleDaysInADate(year, month, Day);
    cout << "Date after adding one Day : ";
    date = TotalDaysToDate(Totale + 1, year);
    cout << date.day << "/" << date.month << "/" << date.year << endl;

    return 0;
}