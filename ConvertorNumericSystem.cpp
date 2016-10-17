#include <iostream>
#include <list>
using namespace std;


int main(){

	int numericSystem, number;
	int currentNumber = 0;
	list<int> newNumber;
	cout << "Enter Numeric System ";
	cin >> numericSystem;
	cout << "Enter Decimal number ";
	cin >> number;
	
	while (number > 0){

		currentNumber = number % numericSystem;
		newNumber.push_front(currentNumber);
		number /= numericSystem;
	}

	cout << number << "(10) = ";

	for (list<int>::iterator i = newNumber.begin(); i != newNumber.end(); ++i) {
		cout << *i;
	}
	cout << "(" << numericSystem << ")\n";

	return 0;
}