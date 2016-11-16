#include<iostream>
#include<clocale>
using namespace std;

int main() {
	setlocale(LC_ALL, "Bulgarian");
	int card, result, kind;

	cout << "Въведете карта: ";
	cin >> card;
	result = card % 13;

	switch (result)
	{
	case 0: cout << "Асо "; break;
	case 1: cout << "Двойка "; break;
	case 2: cout << "Тройка "; break;
	case 3: cout << "Четворка "; break;
	case 4: cout << "Петица "; break;
	case 5: cout << "Шестица "; break;
	case 6: cout << "Седмица "; break;
	case 7: cout << "Осмица "; break;
	case 8: cout << "Девятка "; break;
	case 9: cout << "Десятка "; break;
	case 10: cout << "Вале "; break;
	case 11: cout << "Дама "; break;
	case 12: cout << "Поп "; break;
	default: break;
	}
	if (card == 40 || card == 27)
		kind = card / 13;
	else
		kind = card / 14;

	if (kind == 0)
		cout << "pika \n";
	else if (kind == 1)
		cout << "kupa \n";
	else if (kind == 2)
		cout << "karo \n";
	else
		cout << "spatiq \n";
}