#pragma once
                                // Letter on we will meke this labrary compatble withc any cpp file !
#include <iostream>
#include <string>
#include <iomanip>

using namespace std; // You can keep this if you prefer

namespace cal
{

    template<typename T>
    struct stDate
    {
        T year;
        T month;
        T day;
    };

    int Read_month(string message = "enter month : ")
    {
        int month;
        do
        {
            cout << message;
            cin >> month;
        } while (month > 12 || month < 1);
        return month;
    }

    int Read_year(string message)
    {
        int year;
        cout << message;
        cin >> year;
        return year; // Add return statement
    }

    bool IsleapYear(short y)
    {
        return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
    }

    int DaysInyear(int year)
    {
        bool isLeap = IsleapYear(year);
        if (isLeap) return 366;

        return 365;
    }

    short NumberOfdaysinMonths(short Month, short Year) 
    {
        return (Month == 2) ? (IsleapYear(Year) ? 29 : 28) : ((Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31);
    }

    int Daypos(int year, int month, int day) // get Day position start from Saturday = 0
    {
        int a = ((14 - month) / 12);
        int y = year - a;
        int m = month + 12 * a - 2;

        return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }

    string Day(int daypos)
    {
        string Week[7] = {"Saturday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Sunday"};
        return Week[daypos];
    }

    string DayShortName(int daypos) 
    {
        string Week[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
        return Week[daypos];
    }

    string MonthShortName(int month) 
    {
        string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        return months[month - 1];
    }

    int NumbersOfDaysInMonth(int month, int year) 
    {
        if (month < 1 || month > 12)
            return 0;

        int Days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month == 2 && IsleapYear(year))
            return 29;
        else
            return Days[month - 1];
    }

    void PrintCalendar(int month, int year) 
    {
        int numberOfDays = NumbersOfDaysInMonth(month, year);
        int current = Daypos(year, month, 1);

        cout << "\n  _______________" << MonthShortName(month) << " " << year << "_______________\n\n";
        cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

        // Print leading spaces
        for (int i = 0; i < current; i++)
            cout << "     ";

        // Print days of the month
        for (int day = 1; day <= numberOfDays; day++) {
            cout << setw(5) << day;
            if (++current == 7) {
                current = 0;
                cout << endl;
            }
        }
        cout << "\n  _________________________________\n";
    }

    int ClaculatDays(int year, int month, int Day) // return the number of days since the 1st January of the year
    {
        int DaysSum = 0;
        for (int i = month - 1; i > 0; i--)
        {
            DaysSum += NumberOfdaysinMonths(i, year);
        }
        DaysSum += Day;

        return DaysSum;
    }

    template<typename T>
    stDate<T> TotalDaysToDate(short totalDays, short year)
    {
        stDate<T> date;

        date.year = year;
        date.month = 1;

        while (totalDays > NumberOfdaysinMonths(date.month, year))
        {
            totalDays -= NumberOfdaysinMonths(date.month, year);
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

    template<typename T>
    bool IsDate1EqualDate2(stDate<T> date1, stDate<T> date2 )
    {
        return (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day);
    } 

    int GetLastDayinMonth(int year, int month)
    {
        int LastDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return (month == 2 && IsleapYear(year)) ? 29 : LastDay[month - 1];
    }

    bool Is_Last_Day_In_month(int year, int month, int Day)
    {
        return Day == GetLastDayinMonth(year, month);
    }

    template<typename T>
    bool Is_Last_Day_In_month(stDate<T> Date)
    {
        return Date.day == GetLastDayinMonth(Date.year, Date.month);
    }

    bool Is_Last_Month_In_Year(int month)
    {
        return month == 12;
    }

    template<typename T>
    stDate<T> IncreaseDateByOneDay(stDate<T> Date) // increase date by one day {function needed in other function}
    {
        if (Is_Last_Day_In_month(Date))
        {
            if (Is_Last_Month_In_Year(Date.month))
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

    template<typename T>
    bool IsDate1BeforeDate2(stDate<T> Date1, stDate<T> Date2) {
        return (Date1.year < Date2.year) ? true :
            (Date1.year > Date2.year) ? false :
            (Date1.month < Date2.month) ? true :
            (Date1.month > Date2.month) ? false :
            (Date1.day < Date2.day);
    }

    template<typename T>
    int GettDiferenceInDays(stDate<T> Date1, stDate<T> Date2, bool IncludeEndDay = false)
    {
        int Days = 0;
        while (IsDate1BeforeDate2(Date1, Date2))
        {
            Days++;
            Date1 = IncreaseDateByOneDay(Date1);
        }

        return IncludeEndDay ? ++Days : Days;
    }

    template<typename T>
    std::string FullDateFromstruct(stDate<T> date)
    {
        std::string FullDate = "";
        FullDate += std::to_string(date.day) + "/" + std::to_string(date.month) + "/" + std::to_string(date.year);

        return FullDate;
    }

} // namespace cal
