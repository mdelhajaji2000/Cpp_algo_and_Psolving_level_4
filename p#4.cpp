#include <iostream>
using namespace std;

int ReadPositifnumber()
{
    int num;
    cout << "enter Year : ";
    cin >> num;
    return num;
}

bool fun1(short y)
{
	return (y% 400 == 0 || y % 4 == 0)&&(y%100!=0);
}

int DaysInYear(bool IsLeapYear)
{
    if (IsLeapYear)return 366;
    return 365;
}

int HoursInYear(int Daysnum)
{
    return Daysnum * 24;
}

int MinutesInYear(int Daysnum)
{
    return Daysnum * 24 * 60;
}

int SecondsInYear(int Daysnum)
{
    return Daysnum * 24 * 60 * 60;
}

int main()

{
    int Year = ReadPositifnumber();
    int DaysInyear = DaysInYear(fun1(Year));
    cout << "Days in Year : " << DaysInyear << endl;
    cout << "Hours in Year : " << HoursInYear(DaysInyear) << endl;
    cout << "Minutes in Year : " << MinutesInYear(DaysInyear) << endl;
    cout << "Seconds in Year : " << SecondsInYear(DaysInyear) << endl;

    return 0; 
}