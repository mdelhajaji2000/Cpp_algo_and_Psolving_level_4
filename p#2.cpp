#include <iostream>
#include <string>

using namespace std;

int ReadPositifNumber()
{
    cout << "Enter Year : " << endl;
    int num;
    cin >> num;
    return num;
}

bool CheckLeepYear(int Year)
{
    if (Year % 400 == 0)
    {
        return true;
    }
    else if (Year % 100 == 0)
    {
        return false;
    }
    else if (Year % 4 == 0)
    {
        return true;
    }

    return false;
}

int main()
{
    if (CheckLeepYear(ReadPositifNumber())) cout << "Leap Year" << endl;
    else cout << "Not Leap Year" << endl;

    return 0;
}