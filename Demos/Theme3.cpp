#include <iostream>
#include <clocale>
using namespace std;


int main(){
	/*setlocale(LC_ALL, "Bulgarian");
	int a, b, c, x1, x2, D;*/

	/*cout << "Enter a:";
	cin >> a;
	cout << "Enter b:";
	cin >> b;
	cout << "Enter c:";
	cin >> c;

	int maximum = a;

	if (b > maximum)
	{
		maximum = b;
	}
	if (c > maximum)
	{
		maximum = c;
	}

	cout << "The maximum number is : " << maximum << endl;*/


	/*if (a > b && a > c)
	{
		cout << "Maximum number is a: " << a << endl;
	}
	else
	{
		if (b > a && b > c)
		{
			cout << "Maximum number is b: "<< b << endl;
		}
		else
		{
			cout << "Maximum number is c: " << c << endl;
		}
		
	}*/


	/*if (a > b){
	maximum = a;
	}
	else
	{
	maximum = b;
	}
	if (c > maximum){
	maximum = c;
	}

	cout << "Maximum number is :" << maximum << endl;*/


	int x, y;

	cout << "Enter x: ";
	cin >> x;
	cout << "Enter y: ";
	cin >> y;

	while (y == 0)
	{
		cout << "Please, enter positive value of y ";
		cin >> y;
	}
	cout << "x/y = " << x / y << endl;
}