// IncreaseDate Functions : 

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

void increaseDateByXDays(stDate &Date, int X)
{
    for (int i = 0; i < X ; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
}

void increaseDateByOneWeek(stDate &Date)
{
    increaseDateByXDays(Date, 7);
}


void increaseDateByXWeeks(stDate &Date, int X)
{
    for (int i = 0; i < X; i++)
    {
        increaseDateByOneWeek(Date);
    }
}

void IncreaseDateByOnemonth(stDate &Date)
{
    if (Date.month == 12) 
    {
        Date.month = 1;
        Date.year++;
    }
    else 
    {
        Date.month++;
    }

    int daysInNextMonth = NumberOfDaysInMonth(Date.month, Date.year);
    if (Date.day > daysInNextMonth)
    {
        Date.day = daysInNextMonth;
    }
}

void IncreaseDateByXMonth(stDate &Date, int X)
{
    for (int i = 0; i < X ; i++)
    {
        IncreaseDateByOnemonth(Date);
    }
}

void IncreaseDateByOneYear(stDate &Date)
{
    if (Date.month == 2 && !IsleapYear(Date.year) && Date.day == 29) 
    {
        Date.day = 28; // Move to the last day of February for non-leap years
    }
    Date.year++; // Increment the year
}

void IncreaseDateByXYears(stDate &Date, int X)
{
    for (int i = 0; i < X; i++)
    {
        IncreaseDateByOneYear(Date);
    }
}

void IncreaseDateByOneDecade(stDate &Date)
{
    IncreaseDateByXYears(Date, 10);
}

void IncreaseDateByXDecede(stDate &Date, int X)
{
    for (int i = 0; i < X ; i++)
    {
        IncreaseDateByOneDecade(Date);
    }
}

void IncreaseDateByOneCentry(stDate &Date)
{
    IncreaseDateByXDecede(Date, 10);
}

void IncreaseDateByMillennium(stDate &Date)
{
    for (int i = 0; i < 10; i++) IncreaseDateByOneCentry(Date);
}

int main()
{
    stDate Date;
    //Date = readFullDate();
    Date.day = 31;
    Date.month = 12;
    Date.year = 2022;
    Date = IncreaseDateByOneDay(Date);
    cout << "01-Adding one day is : " << PrintFullDate(Date) << endl;
    increaseDateByXDays(Date, 10);
    cout << "02-Adding 10 days is : " << PrintFullDate(Date) << endl;
    increaseDateByOneWeek(Date);
    cout << "03-Adding one week is : " << PrintFullDate(Date) << endl;
    increaseDateByXWeeks(Date, 10);
    cout << "04-Adding 10 Weeks is : " << PrintFullDate(Date) << endl;
    IncreaseDateByOnemonth(Date);
    cout << "05-Adding one month is : " << PrintFullDate(Date) << endl;
    IncreaseDateByXMonth(Date, 5);
    cout << "06-Adding 5 months is : " << PrintFullDate(Date) << endl;
    IncreaseDateByOneYear(Date);
    cout << "07-Adding one year is : " << PrintFullDate(Date) << endl;
    IncreaseDateByXYears(Date, 10);
    cout << "08-Adding 10 years is : " << PrintFullDate(Date) << endl;
    IncreaseDateByOneDecade(Date);
    cout << "09-Adding one Decade is : " << PrintFullDate(Date) << endl;
    IncreaseDateByXDecede(Date, 10);
    cout << "10-Adding 10 Decade is : " << PrintFullDate(Date) << endl; 
    IncreaseDateByOneCentry(Date);
    cout << "11-Adding one Centry is : " << PrintFullDate(Date) << endl;
    IncreaseDateByMillennium(Date);
    cout << "12-Adding one Millennium is : " << PrintFullDate(Date) << endl;

    return 0;
}

