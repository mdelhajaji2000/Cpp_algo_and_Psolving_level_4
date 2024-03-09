#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

int ReadNumber()
{
    int num;
    cout << "enter number : ";
    cin >> num;
    return num;
}

string numberTotext(int number)
{
    if (number == 0)
    {
        return "";
    }
    if (number >= 1 && number <= 19)
    {
        string arr[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        return arr[number];
    }
    if (number >= 20  && number <= 99)
    {
        string arr[] = {"", "", "twenty", "Thirty", "Fourty", "Fifty", "sixty", "Seeventy", "eighty", "ninty"};
        return arr[number / 10] + " " + numberTotext(number % 10);
    }
    if (number >= 100 && number <= 199)
    {
        return "One Hundred " + numberTotext(number % 100);
    }
    if (number >= 200 && number <= 999)
    {
        return numberTotext(number / 100) + " Hundred" + " " + numberTotext(number % 100);
    }
    if (number >= 1000 && number <= 1999)
    {
        return "One Thousend " + numberTotext(number % 1000);
    }
    if (number >= 2000 && number <= 999999)
    {
        return numberTotext(number / 1000) + " Thousend" + " " + numberTotext(number % 1000);
    }
    if (number >= 1000000 && number <= 1999999)
    {
        return "One Million " + numberTotext(number % 1000000);
    }
    if (number >= 2000000 && number <= 999999999)
    {
        return numberTotext(number / 1000000) + "Millions" + " " + numberTotext(number % 1000000);
    }
    if (number >= 1000000000 && number <= 1999999999)
    {
        return "One Billion " + numberTotext(number % 1000000000);
    }
    if (number >= 2000000000 && number <= 999999999999)
    {
        return numberTotext(number / 1000000000) + "Billions " + numberTotext(number % 1000000000);
    }
    return "+infinity" ;
}

int main()
{
    long long number = ReadNumber();
    cout << numberTotext(number) << endl;

    return 0;
}