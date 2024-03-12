#include <iostream>

using namespace std;

bool IsLeapYear(int Year)
{
	return((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
}
short NumberOfDaysInMonth(short year, short month)
{
	if (month < 1 || month>12)
	{
		return 0;
	}

	short arrNumberOdays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : arrNumberOdays[month];
}
short NumberOfDaysFromTheBeginingOfYear(short year, short month, short day)
{
	short TotalDays = 0;

	for (int i = 1; i < month; i++)
	{
		TotalDays+= NumberOfDaysInMonth(year, i);
	}
	TotalDays+= day;

	return TotalDays;
}
struct sDate
{
	short Day;
	short Month;
	short Year;
};
bool IsDate1LessThanDate2(short DaysOrderDate1, short DaysOrderDate2)
{
	return DaysOrderDate1 < DaysOrderDate2;
} 
short ReadDay()
{
	short day = 0;
	do {
		cout << "Please enter day ?";
		cin >> day;
	} while (day > 31 || day < 1);
	return day;
 }
short ReadMonth()
{
	short Month;
	do {
		cout << "Please enter a Month? ";
		cin >> Month;
	} while (Month > 12 || Month < 1);
	return Month;
}
short ReadYear()
{
	short year;
	do {
		cout << "Please enter year? ";
		cin >> year;
	} while (year < 1);
	return year;
}
sDate ReadFullDate()
{
	sDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}
int main()
{
	sDate Date1 = ReadFullDate();
	cout << "\n\n";
	sDate Date2 = ReadFullDate();
	short DaysOrderDate1= NumberOfDaysFromTheBeginingOfYear(Date1.Year,Date1. Month,Date1. Day);
	short DaysOrderDate2 = NumberOfDaysFromTheBeginingOfYear(Date2.Year, Date2.Month, Date2.Day);

	if (IsDate1LessThanDate2(DaysOrderDate1, DaysOrderDate2))
	{
		cout << "Yes ,Date 1 less than Date 2 .";
	 }
	else {
		cout << "No ,Date 1 not less than Date 2 .";
	}

}