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

int Daypos(int year, int month, int day) // get Day position start from Saturday = 0
{
    int a = ((14 - month) / 12);
    int y = year - a;
    int m = month + 12 * a - 2;

    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayShortName(int daypos) 
{
    string Week[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return Week[daypos];
}

bool IsendOfWeek(stDate Date)
{
    return Daypos(Date.year, Date.month, Date.day) == 6;
}

bool IsWeekend(stDate Date)
{
    return (IsendOfWeek(Date) || Daypos(Date.year, Date.month, Date.day) == 5);
}

bool IsBusinessDay(stDate Date)
{
    return !IsWeekend(Date);
}

int DaysUntillEndOfWeek(stDate Date)
{
    if (IsWeekend(Date)) return 0;
    return 7 - Daypos(Date.year, Date.month, Date.day);
}

int DaysUntillEndOfMonth(stDate Date)
{
    return NumberOfDaysInMonth(Date.month, Date.year) - Date.day;
}

int DaysUntillEndOfYear(stDate AcDate) // AcDate Actual Date
{
    stDate End_Of_year;
    End_Of_year.day = 31;
    End_Of_year.month = 12;
    End_Of_year.year = AcDate.year;
    return GetDiferenceInDays(AcDate, End_Of_year);
}


int main()
{
    stDate ActualDate = getActualDate();
    
    cout << "Today is : " << DayShortName(Daypos(ActualDate.year, ActualDate.month, ActualDate.day));
    cout << " , " << ActualDate.day << "/" << ActualDate.month << "/" << ActualDate.year << "\n" << endl;

    cout << "Is it End of Week ?" << endl;
    if (IsendOfWeek(ActualDate)) cout << "Yes end of week\n" << endl;
    else cout << "No not end of week !\n" << endl;

    cout << "Is It Week end ?" << endl;
    if (IsWeekend(ActualDate)) cout << "Yes it is a week end !\n" << endl;
    else cout << "No Not a Week end !\n" << endl;

    if (IsBusinessDay(ActualDate)) cout << "Yes its a buisness Day !\n" << endl;
    else cout << "No Not a business day !\n" << endl;

    cout << "Days untill End Of Week : " << DaysUntillEndOfWeek(ActualDate) << endl;
    cout << "Days untill End Of Month : " << DaysUntillEndOfMonth(ActualDate) << endl;
    cout << "Days untill End Of Year : " << DaysUntillEndOfYear(ActualDate) << endl;

    return 0;
}