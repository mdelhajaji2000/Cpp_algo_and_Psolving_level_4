#include <iostream>
using namespace std;

int readpositifNumber(const string Message)
{
    int number;
    cout << Message;
    cin >> number;
    return number;
}

int Daypos(int year, int month, int day)
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

int main()
{
    short year = readpositifNumber("enter year : ");
    short monthNumber = readpositifNumber("enter month : ");
    short day= readpositifNumber("enter day : ");

    cout << "Date : " << day << "/" << monthNumber << "/" << year << endl;
    cout << "Day pos : " << Daypos(year, monthNumber, day) << endl;
    cout << "day : " << Day(Daypos(year, monthNumber, day)) << endl;

    return 0;
}