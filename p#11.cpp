#include <iostream>
using namespace std;

struct stDate
{
    int year;
    int month;
    int day;
};

bool IsleapYear(int y)
{
	return (y% 400 == 0 || y % 4 == 0)&&(y%100!=0);
}

short NumberOdaysinMonths(short Month, short Year) {
    return (Month == 2) ? IsleapYear(Year) ? 29 : 28 : (Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31;
}

int readintger(string Message)
{
    int it; // intger
    cout << Message;
    cin >> it;

    return it;
}

int ClaculatDays(int year, int month, int Day)
{
    int DaysSum = 0;
    for (int i = month - 1; i > 0; i--)
    {
        DaysSum += NumberOdaysinMonths(i, year);
    }
    DaysSum += Day;

    return DaysSum;
}


stDate totalDaysToDate(short totalDays, short year)
{
    stDate date;

    date.year = year;
    date.month = 1;

    while (totalDays > NumberOdaysinMonths(date.month, year))
    {
        totalDays -= NumberOdaysinMonths(date.month, year);
        date.month++;
    }

    date.day = totalDays;

    return date;
}



int main()
{
    int year = readintger("enter year : ");
    int month = readintger("enter month : ");
    int Day = readintger("enter day : ");

    cout << "the Days passed from the frist of the year are : " << endl;
    cout << ClaculatDays(year, month, Day);
}