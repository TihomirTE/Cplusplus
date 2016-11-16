#include <iostream>
#include<cstdlib>
using namespace std;

int main() {
	int numberUser, numberPC, sumPC = 0, sumUser = 0, randNum, counter = 0;

	do
	{
		if (counter % 2 == 0)
		{
			randNum = rand() % 10 + 1;
			cout << "Enter your number: ";
			cin >> numberUser;
			sumPC += numberUser + randNum;
		}
		else
		{
			randNum = rand() % 10 + 1;
			numberPC = rand() % 10 + 1;
			sumUser += numberPC + randNum;
		}
		counter++;
	} while (sumPC < 100 && sumUser < 100);
	if (sumPC >= 100)
		cout << "PC win with number: " << sumPC << endl;
	else
		cout << "User win with number: " << sumUser << endl;
}