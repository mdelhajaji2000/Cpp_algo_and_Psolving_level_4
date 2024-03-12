#include <iostream>
using namespace std;

struct stDate
{
    int year;
    int month;
    int day;
};

stDate readFullDate()
{
    stDate Date;

    cout << "Enter Day : ";
    cin >> Date.day;
    cout << "Enter Month : ";
    cin >> Date.month;
    cout << "Enter Year : ";
    cin >> Date.year;

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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
    return (Date1.year < Date2.year) ? true :
           (Date1.year > Date2.year) ? false :
           (Date1.month < Date2.month) ? true :
           (Date1.month > Date2.month) ? false :
           (Date1.day < Date2.day);
}

bool IsleapYear(int y) // y = year !
{
    return (y% 400 == 0 || y % 4 == 0)&&(y%100!=0);
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

int VacationPeriod(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        if (!(IsWeekend(Date1))) Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return IncludeEndDay ? ++Days : Days;
}



int main()
{
    cout << "Vacation starts : " << endl;
    stDate StartsDate = readFullDate();
    cout << endl;
    cout << "Vacation Ends : " << endl;
    stDate EndsDate = readFullDate();
    cout << endl;

    cout << "Vacation From : " << DayShortName(Daypos(StartsDate.year, StartsDate.month, StartsDate.day)) << " , " << StartsDate.day << "/" << StartsDate.month << "/" << StartsDate.year << endl;
    cout << "Vacation End : " << DayShortName(Daypos(EndsDate.year, EndsDate.month, EndsDate.day)) << " , " << EndsDate.day << "/" << EndsDate.month << "/" << EndsDate.year << "\n" << endl;
    cout << endl;
    
    cout << "Vacation Days is : " << VacationPeriod(StartsDate, EndsDate, false) << endl;

    return 0;
}