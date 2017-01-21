#include <string>
#include <cstring>
#include <iostream>

using namespace std;


int stepen(int, int);
unsigned fibonachi(unsigned);

int main() {

	/*int result = stepen(2, 6);
	cout << result;*/
	int resultFib = fibonachi(5);
	cout << resultFib << endl;
}

int stepen(int number, int st) {
	if (st == 0)
	{
		return 1;
	}
	else
	{
		return number*stepen(number, st - 1);
	}
}

unsigned fibonachi(unsigned n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fibonachi(n - 2) + fibonachi(n - 1);
}
