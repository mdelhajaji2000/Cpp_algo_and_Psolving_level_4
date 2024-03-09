#include <iostream>
using namespace std;

int ReadPositifNUmber()
{
    int num;
    cout << "enter Year : " << endl;
    cin >> num;
    return num;
}

bool fun1(short y)
{
	return( ( (y% 400 == 0 || y % 4 == 0)&&(y%100!=0) )? true : false);

}

int main()
{
    int Year = ReadPositifNUmber();
    cout << fun1 << endl;

    return 0;
}