#include <iostream>
#include <clocale>
using namespace std;



int main(){
	setlocale(LC_ALL, "Bulgarian");
	/*unsigned num, a, b, c, d, num1, num2;
	
	do
	{
		cout << " Enter number: ";
		cin >> num;
	} while (num < 1000 || num >= 10000);

	d = num % 10;
	num /= 10;
	c = num % 10;
	num /= 10;
	b = num % 10;
	num /= 10;
	a = num % 10;
	num /= 10;

	num1 = (a * 10) + d;
	num2 = (b * 10) + c;

	if (num1 > num2){
		cout << "Bigger number is :" << num1 << endl;
	}
	else
	{
		cout << "Bigger number is :" << num2 << endl;
	}*/

		/*int num, a, b, c;

		do
		{
			cout << "Въведете число ";
			cin >> num;
			a = num % 10;
			b = ((num / 10) % 10);
			c = num / 100;
		} while ((num < 100 || num > 999) || (a == 0 || b == 0 || c == 0));

		if (num % a == 0 && num % b == 0 && num % c)
		{
			cout << "Да \n";
		}
		else
		{
			cout << "Не \n";
		}*/

	/*int r, x1, x2, y1, y2, inside;

	cout << "Enter r: ";
	cin >> r;
	cout << "Enter x1: ";
	cin >> x1;
	cout << "Enter y1: ";
	cin >> y1;
	cout << "Enter x2: ";
	cin >> x2;
	cout << "Enter y2: ";
	cin >> y2;

	inside = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

	if (inside <= r * r)
	{
		cout << "Yes \n";
	}
	else
	{
		cout << "No \n";
	}*/

	/*int a, b, c, sum;
	int counter = 1;
	for (int i = 100; i < 1000; i++)
	{
		a = i % 10;
		b = (i / 10) % 10;
		c = i % 100;
		sum = a * b * c;
		if (i % sum == 0)
		{
			counter++;
		}
	}

	cout << counter;
}*/


	int num1, num2, num3;

	do
	{
		cout << "Enter num1: ";
		cin >> num1;
		cout << "Enter num2: ";
		cin >> num2;
		cout << "Enter num3: ";
		cin >> num3;

	} while ((num1 > 9 || num1 <= 10000) || (num2 > 9 || num2 <= 10000) || (num3 > 9 || num3 <= 10000));

	for (size_t i = 2; i < num1; i++)
	{
		if (num1 % i == 0 && num2 % i == 0 && num3 % i == 0)
		{
			cout << "н.м.д."
		}
	}