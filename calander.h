//----------------------------------------------------------
//          Calander Header File :
//     Library of Functions that contain a Basic Calander
//  functions like function to read correctly a month
//  or a function to print The Day using The numeric Date... 
//  use only Cal namespace !
//  By : Mdelhajaji2000
//----------------------------------------------------------
#pragma once

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

namespace Cal
{

    struct stDate
    {
        int year;
        int month;
        int day;
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
    }

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

    short NumberOfdaysinMonths(short Month, short Year) 
    {
        return (Month == 2) ? IsleapYear(Year) ? 29 : 28 : (Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31;
    }

    int Daypos(int year, int month, int day) // get Day position start from saturday = 0
    {
        int a = ((14 - month) / 12);
        int y = year - a;
        int m = month + 12 * a - 2;

        return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }

    string Day(int daypos)
    {
        string Week[7] = {"Satur", "Mon", "Tue", "Wed", "Thu", "Fri", "Sun"};
        return Week[daypos];
    }

    string DayShortName(int daypos) {
    string Week[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return Week[daypos];
}

    string MonthShortName(int month) 
    {
        string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
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

    int ClaculatDays(int year, int month, int Day) // return the number of days sience the 1st january of the year
    {
        int DaysSum = 0;
        for (int i = month - 1; i > 0; i--)
        {
            DaysSum += NumberOfdaysinMonths(i, year);
        }
        DaysSum += Day;

        return DaysSum;
    }

    stDate TotalDaysToDate(short totalDays, short year)
    {
        stDate date;

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


    bool IsDate1EqualDate2(stDate date1, stDate date2 )
    {
        
        return  (
                 date1.year == date2.year &&
                 date1.month == date2.month &&
                 date1.day == date2.day
                 );
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


    bool Is_Last_Month_In_Year(int month)
    {
        return month == 12;
    }

} // namespace Cal
