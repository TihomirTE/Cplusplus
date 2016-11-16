#include <iostream>
using namespace std;

int main() {
	int side;
	char symbol;

	cout << "Enter lenght side for the triangle: ";
	cin >> side;
	cout << "Enter symbol: ";
	cin >> symbol;
	char symbolStar = '*';

	for (int row = 0; row <= side; row++) {
		for (int col = 0; col < row - 1; col++)
		{
			if (col == 0 || col == (row - 2))
				cout << symbolStar;
			else 
				cout << symbol;
		}
		if (row == side) 
		{
			cout << endl;
			for (int last = 0; last < side; last++) 
				cout << symbolStar;
		}
		cout << endl;
	}
}




