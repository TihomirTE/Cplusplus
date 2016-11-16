#include<iostream>
using namespace std;

int main() {
	int n, m, p, pow, sum = 0;
	cout << "Enter number N: ";
	cin >> n;
	cout << "Enter number M: ";
	cin >> m;
	
	while (m >= n)
	{
		sum += m;
		m--;
	}
	cout << "Sum = " << sum << " -> ";
	if (n > 1)
		p = n;
	else
		p = 2;
	while (p <= sum)
	{
		pow = 0;
		while (sum % p == 0)
		{
			sum /= p;
			pow++;
		}
		if ((p == n && pow > 0) || (p == 2 && pow > 0))
			cout << "(" << p << "^" << pow << ")";
		else if (pow > 0)
			cout << "*(" << p << "^" << pow << ")";
		p++;
	}
	cout << endl;
}