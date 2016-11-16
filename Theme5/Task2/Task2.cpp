#include<iostream>
#include<clocale>
using namespace std;

int spellNumber(int);
int main()
{
	setlocale(LC_ALL, "Bulgarian");
	int n;
	cout << "Enter number: ";
	cin >> n;
	spellNumber(n);
	return 0;
}



int spellNumber(int n) 
{
	int d = n / 10, e = n % 10;
	if (e == 0) 
	{
		cout << ((d) ? "десет" : "нула");
	}
	if (d) 
	{
		if (e == 1) cout << "еди";
		if (e == 2) cout << "два";
	}
	switch (e) {
	case 1: if (!d) cout << "едно"; break;
	case 2: if (!d) cout << "две"; break;
	case 3: cout << "три"; break;
	case 4: cout << "четири"; break;
	case 5: cout << "пет"; break;
	case 6: cout << "шест"; break;
	case 7: cout << "седем"; break;
	case 8: cout << "осем"; break;
	case 9: cout << "девет"; break;
	}
	if (d && e != 0) cout << "надесет";
	return 0;
}
