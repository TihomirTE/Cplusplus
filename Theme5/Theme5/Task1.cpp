#include <iostream>
using namespace std;

/*Задача 1
Вход: 5 *
Изход:
*   * *   * *****
*   * *   * *
***** ***** *
    * *   * *
    * *   * *

*/
int print4ng(int, char);

int main() {
	print4ng(23, '*');
	return 0;
}

int print4ng(int n, char s) {

	//печатаме първи ред
	cout << s; 
	for (int i = 1; i < n - 1; i++) 
		cout << ' '; 
	cout << s << ' ';
	cout << s; 
	for (int i = 1; i< n - 1; i++) 
		cout << ' '; 
	cout << s << ' ';
	for (int i = 1; i <= n; i++) 
		cout << s;
	cout << endl;

	//извеждане на останалите редове до половината
	for (int i = 2; i <= n / 2; i++) 
	{
		cout << s; 
		for (int i = 1; i<n - 1; i++) 
			cout << ' '; 
		cout << s << ' ';
		cout << s; 
		for (int i = 1; i<n - 1; i++) 
			cout << ' '; 
		cout << s << ' ';
		cout << s << endl;
	}
	//извеждане на средния ред
	for (int i = 1; i <= n; i++) 
		cout << s; cout << ' ';
	for (int i = 1; i <= n; i++) 
		cout << s; 
	cout << ' ';
	cout << s << endl;

	//извеждане на всичко под средния ред
	for (int i = 1; i <= n / 2; i++) 
	{
		for (int i = 1; i < n; i++) 
			cout << ' '; 
		cout << s << ' ';
		cout << s; 
		for (int i = 1; i < n - 1; i++)
			cout << ' '; 
		cout << s << ' ';
		cout << s << endl;
	}
	return 0;
}
