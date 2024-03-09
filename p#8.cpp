#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

bool IsLeapYear(int y) {
    return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
}

int ReadYear() {
    int y;
    cout << "Enter Year: ";
    cin >> y;
    return y;
}

int ReadMonth() {
    int m;
    cout << "Enter Month: ";
    cin >> m;
    return m;
}

int DayInWeekOrder(int year, int month, int day) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int a = year / 100;
    int b = a / 4;
    int c = 2 - a + b;
    int d = year % 100;
    int e = 26 * (month + 1) / 10;
    int dayOfWeek = (day + e + d + d / 4 + c + 5) % 7;
    return dayOfWeek;
}

string DayShortName(int daypos) {
    string Week[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return Week[daypos];
}

string MonthShortName(int month) {
    string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                         "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    return months[month - 1];
}

int NumbersOfDaysInMonth(int month, int year) {
    if (month < 1 || month > 12)
        return 0;

    int Days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && IsLeapYear(year))
        return 29;
    else
        return Days[month - 1];
}

void PrintCalendar(int month, int year) {
    int numberOfDays = NumbersOfDaysInMonth(month, year);
    int current = DayInWeekOrder(year, month, 1);

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

int main() {
    int year = ReadYear();
    int month = ReadMonth();
    PrintCalendar(month, year);
    return 0;
}
