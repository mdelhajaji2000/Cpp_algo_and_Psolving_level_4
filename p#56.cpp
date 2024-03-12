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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
    return (Date1.year < Date2.year) ? true :
           (Date1.year > Date2.year) ? false :
           (Date1.month < Date2.month) ? true :
           (Date1.month > Date2.month) ? false :
           (Date1.day < Date2.day);
}

bool IsDateafterDate2(stDate Date1, stDate Date2) {
    return (Date1.year > Date2.year) ? true :
           (Date1.year < Date2.year) ? false :
           (Date1.month > Date2.month) ? true :
           (Date1.month < Date2.month) ? false :
           (Date1.day > Date2.day);
}

bool IsDate1EqualDat2(stDate Date1, stDate Date2)
{
    return !IsDate1BeforeDate2(Date1, Date2) && !IsDateafterDate2(Date1, Date2);
}

string PrintFullDate(stDate Date)
{
    string FullDate = to_string(Date.day) + "/" + to_string(Date.month) + "/" + to_string(Date.year);
    return FullDate;
}

int main()
{
    cout << "enter Date 1 : " << endl;
    stDate Date1 = readFullDate();
    cout << endl;
    cout << "enter Date 2 : " << endl;
    stDate Date2 = readFullDate();
    cout << endl;

    IsDate1BeforeDate2(Date1, Date2) ? printf("Date1 before Date2") : (IsDateafterDate2(Date1, Date2) ? printf("Date1 after Date2") : printf("Dat1 = Date2"));

    return 0;
}