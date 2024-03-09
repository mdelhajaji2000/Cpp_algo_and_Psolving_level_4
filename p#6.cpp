#include<iostream>
#include <vector>
using namespace std;
short ReadYear() {
    int Year = 0;
    do {
        cout << " Please Enter a Year to check  : \n";
        cin >> Year;
    } while (Year < 0);
    return Year;

}
bool IsleapYear(int N) {
    return  ((N % 100 != 0) && (N % 4 == 0)) || (N % 400 == 0);
}

short ReadMonth() {
    short Month = 0;
    do {
        cout << " Please Enter a Month to check  : \n";
        cin >> Month;
    } while (Month < 1 || Month > 12);
    return Month;

}

short NumberOfdaysinMonths(short Month, short Year) {
    return (Month == 2) ? IsleapYear(Year) ? 29 : 28 : (Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31;
}
int DaysToseconds(short NumberofDays) {
    return  NumberofDays * 24 * 60 * 60;
}
int DaysToHours(short NumberofDays) {
   
    return  NumberofDays * 24;
}
int DaysToMinutes(short NumberofDays) {
    
    return NumberofDays * 24 * 60;
}



int main() {
    short Year = ReadYear();
    short Month = ReadMonth();
    short NumberofDays = NumberOdaysinMonths(Month, Year);
    printf("Number of Days in Month [%d] is %d \n", Month, NumberofDays);
    printf("Number of Hours in Month [%d] is %d \n", Month, DaysToHours(NumberofDays));
    printf("Number of Minutes in Month [%d] is %d \n", Month, DaysToMinutes(NumberofDays));
    printf("Number of Seconds in Month [%d] is %d \n", Month, DaysToseconds(NumberofDays));

    system("pause>0");

    return 0;
}