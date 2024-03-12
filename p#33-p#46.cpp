// DecreaseDate Functions : 

#include <iostream>
#include <string>

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

string PrintFullDate(stDate Date)
{
    string FullDate = to_string(Date.day) + "/" + to_string(Date.month) + "/" + to_string(Date.year);
    return FullDate;
}

bool IsleapYear(int y) // y = year !
{
    return (y% 400 == 0 || y % 4 == 0)&&(y%100!=0);
}

short NumberOfDaysInMonth(short Month, short Year) 
{
    return (Month == 2) ? (IsleapYear(Year) ? 29 : 28) : ((Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31);
}

bool IsFristDayInMonth(stDate Date)
{
    return (Date.day == 1);
}

bool IsFristMonthInYear(short month)
{
    return (month == 1);
}

stDate DecreaseDateByOneDay(stDate Date)
{
    if (IsFristDayInMonth(Date))
    {
        if (IsFristMonthInYear(Date.month))
        {
            Date.year--;
            Date.month = 12;
            Date.day = 31;
        }
        else {
            Date.month--;
            Date.day = NumberOfDaysInMonth(Date.month--, Date.year);
        }
    }
    else {
        Date.day--;
    }

    return Date;
}

void DecreaseDateByXDays(stDate &Date, int X)
{
    for (int i = 0; i < X ; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
}

void DecreaseDateByOneWeek(stDate &Date)
{
    DecreaseDateByXDays(Date, 7);
}


void DecreaseDateByXWeeks(stDate &Date, int X)
{
    for (int i = 0; i < X; i++)
    {
        DecreaseDateByOneWeek(Date);
    }
}

void DecreaseDateByOnemonth(stDate &Date)
{
    if (Date.month == 1) 
    {
        Date.month = 12;
        Date.year--;
    }
    else 
    {
        Date.month--;
    }

    int daysInLastMonth = NumberOfDaysInMonth(Date.month, Date.year);
    if (Date.day > daysInLastMonth)
    {
        Date.day = daysInLastMonth;
    }
}


void DecreaseDateByXMonth(stDate &Date, int X)
{
    for (int i = 0; i < X ; i++)
    {
        DecreaseDateByOnemonth(Date);
    }
}

void DecreaseDateByOneYear(stDate &Date)
{
    if (Date.month == 2 && !IsleapYear(Date.year) && Date.day == 29) 
    {
        Date.day = 28; // Move to the last day of February for non-leap years
    }
    Date.year--; // Increment the year
}

void DecreaseDateByXYears(stDate &Date, int X)
{
    for (int i = 0; i < X; i++)
    {
        DecreaseDateByOneYear(Date);
    }
}

void DecreaseDateByOneDecade(stDate &Date)
{
    DecreaseDateByXYears(Date, 10);
}

void DecreaseDateByXDecede(stDate &Date, int X)
{
    for (int i = 0; i < X ; i++)
    {
        DecreaseDateByOneDecade(Date);
    }
}

void DecreaseDateByOneCentry(stDate &Date)
{
    DecreaseDateByXDecede(Date, 10);
}

void DecreaseDateByMillennium(stDate &Date)
{
    for (int i = 0; i < 10; i++) DecreaseDateByOneCentry(Date);
}

int main()
{
    stDate Date;
    //Date = readFullDate();
    Date.day = 31;
    Date.month = 12;
    Date.year = 2022;
    Date = DecreaseDateByOneDay(Date);
    cout << "01-Removing one day is : " << PrintFullDate(Date) << endl;
    DecreaseDateByXDays(Date, 10);
    cout << "02-Removing 10 days is : " << PrintFullDate(Date) << endl;
    DecreaseDateByOneWeek(Date);
    cout << "03-Removing one week is : " << PrintFullDate(Date) << endl;
    DecreaseDateByXWeeks(Date, 10);
    cout << "04-Removing 10 Weeks is : " << PrintFullDate(Date) << endl;
    DecreaseDateByOnemonth(Date);
    cout << "05-Removing one month is : " << PrintFullDate(Date) << endl;
    DecreaseDateByXMonth(Date, 5);
    cout << "06-Removing 5 months is : " << PrintFullDate(Date) << endl;
    DecreaseDateByOneYear(Date);
    cout << "07-Removing one year is : " << PrintFullDate(Date) << endl;
    DecreaseDateByXYears(Date, 10);
    cout << "08-Removing 10 years is : " << PrintFullDate(Date) << endl;
    DecreaseDateByOneDecade(Date);
    cout << "09-Removing one Decade is : " << PrintFullDate(Date) << endl;
    DecreaseDateByXDecede(Date, 10);
    cout << "10-Removing 10 Decade is : " << PrintFullDate(Date) << endl; 
    DecreaseDateByOneCentry(Date);
    cout << "11-Removing one Centry is : " << PrintFullDate(Date) << endl;
    DecreaseDateByMillennium(Date);
    cout << "12-Removing one Millennium is : " << PrintFullDate(Date) << endl;

    return 0;
}

