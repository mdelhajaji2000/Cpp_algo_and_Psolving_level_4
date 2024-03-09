#include <iostream>
using namespace std;

int Readint(string Message)
{
    int num;
    cout << Message;
    cin >> num;

    return num;
}

bool IsleapYear(short y)
{
	return (y% 400 == 0 || y % 4 == 0)&&(y%100!=0);
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

int main()
{
    int year = Readint("enter year : ");
    int month = Readint("enter month : ");
    int day = Readint("enter Day : ");

    if (Is_Last_Day_In_month(year, month, day)) 
        cout << day << " is the last day of month " << month << endl;
    else 
        cout << day << " is not the last day of month " << month << endl;
    if (Is_Last_Month_In_Year(month))
        cout << month << " month its The last month in " << year << endl;
    else 
        cout << month << " month isn`t The last month in " << year << endl;

    return 0;
}
