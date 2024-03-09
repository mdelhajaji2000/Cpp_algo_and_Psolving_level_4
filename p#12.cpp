#include <iostream>
using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};

bool IsLeapYear(int y)
{
    return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
}

short NumberOfDaysInMonth(short Month, short Year) {
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : ((Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31);
}

int ReadInteger(string Message)
{
    int it; // integer
    cout << Message;
    cin >> it;

    return it;
}

int CalculateDays(int year, int month, int day)
{
    int DaysSum = 0;
    for (int i = month - 1; i > 0; i--)
    {
        DaysSum += NumberOfDaysInMonth(i, year);
    }
    DaysSum += day;

    return DaysSum;
}

Date TotalDaysToDate(short totalDays, short year)
{
    Date date;

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

int main()
{
    int year = ReadInteger("Enter year: ");
    int month = ReadInteger("Enter month: ");
    int day = ReadInteger("Enter day: ");
    int addDays = ReadInteger("Enter days to add: ");

    Date date;
    date = TotalDaysToDate(CalculateDays(year, month, day) + addDays, year);
    cout << "Date after adding " << addDays << " days is: " << date.day << "/" << date.month << "/" << date.year << endl;

    return 0;
}
