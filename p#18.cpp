#pragma warning(disable : 4996)

#include <iostream>
#include <string>
#include <ctime>

#include "calander.h"

using namespace std;

struct stDate{
    int year;
    int month;
    int day;
};

bool IsleapYear(int y) // y = year !
{
    return (y% 400 == 0 || y % 4 == 0)&&(y%100!=0);
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
    return (Date1.year < Date2.year) ? true :
           (Date1.year > Date2.year) ? false :
           (Date1.month < Date2.month) ? true :
           (Date1.month > Date2.month) ? false :
           (Date1.day < Date2.day);
}

short NumberOfDaysInMonth(short Month, short Year) 
{
    return (Month == 2) ? (IsleapYear(Year) ? 29 : 28) : ((Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31);
}

bool IsLastDayInMonth(stDate Date)
{
    return (Date.day == NumberOfDaysInMonth(Date.month, Date.year));
}

bool IslastMonthInYear(short month)
{
    return (month == 12);
}

stDate IncreaseDateByOneDay(stDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IslastMonthInYear(Date.month))
        {
            Date.month = 1;
            Date.day = 1;
            Date.year++;
        }
        else {
            Date.day = 1;
            Date.month++;
        }
    }
    else {
        Date.day++;
    }

    return Date;
}

int GetDiferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return IncludeEndDay ? ++Days : Days;
}

stDate ReadFullDate()
{
    stDate Date;
    cout << "enter Day : ";
    cin >> Date.day;
    cout << "enter month : ";
    cin >> Date.month;
    cout << "enter Year :";
    cin >> Date.year;

    return Date;
}

string FullDateFromstruct(stDate date)
{
    string FullDate = "";
    FullDate += to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);

    return FullDate;
}

stDate getActualDate()
{
    stDate Date;

    time_t t = time(0);
    tm* now = localtime(&t);

    Date.year = now->tm_year + 1900;
    Date.month = now->tm_mon + 1;
    Date.day = now->tm_mday;

    return Date;
}

int main()
{
    stDate ActualDate = getActualDate();
    cout << "enter your birthday : " << endl;
    stDate birthday = ReadFullDate();

    cout << "you aged : " << GetDiferenceInDays(birthday, ActualDate, true);

    return 0;
}