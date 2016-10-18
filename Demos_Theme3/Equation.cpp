#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;



int main(){
	setlocale(LC_ALL, "Bulgarian");
	int a, b, c, x1, x2, D;

	cout << "Enter a:";
	cin >> a;
	cout << "Enter b:";
	cin >> b;
	cout << "Enter c:";
	cin >> c;



	if (a == 0)
	{
		x1 = -c / b;
	}
	else
	{
		D = pow(b, 2) - 4 * a * c;
		if (D < 0)
		{
			cout << "No real roots." << endl;
		}
		else if (D == 0)
		{
			x1 = -b / 2 * a;
			cout << "x1/x2 = " << x1 << endl;
		}
		else
		{
			x1 = -b + sqrt(D) / (2 * a);
			x2 = -b - sqrt(D) / (2 * a);
			cout << "x1 = " << x1 << endl;
			cout << "x2 = " << x2 << endl;
		}
	}










}