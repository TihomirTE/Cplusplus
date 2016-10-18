#include <iostream>
#include <clocale>
using namespace std;

int main(){
	int year, month, days;
	setlocale(LC_ALL, "Bulgarian");
	cout << "Enter an year ";
	cin >> year;
	cout << "Enter a month ";
	cin >> month;
	if (month == 2)
	{
		if (year % 4 == 0)
		{
			days = 29;
		}
		else
		{
			days = 28;
		}
	}
	else if (month == 4 || month == 7 || month == 9 || month == 11)
	{
		days = 30;
	}
	else
	{
		days = 31;
	}

	cout << "The year " << year << ", month " << month << " consist of " << days << " days !" << endl;
}