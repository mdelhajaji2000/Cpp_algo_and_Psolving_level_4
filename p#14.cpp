#include <iostream>

using namespace std;

 
struct sDate
{
	short Day;
	short Month;
	short Year;
};
bool IsDate1EqualDate2(sDate date1, sDate date2 )
{
	
	return  (date1.Year == date2.Year && date1.Month == date2.Month && date1.Day == date2.Day);
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
 
	if (IsDate1EqualDate2(Date1,Date2))
	{
		cout << "Yes ,Date1 is equal Date 2 .\n";
	 }
	else {
		cout << "No ,Date1 is not equal Date 2 .\n";
	}

}