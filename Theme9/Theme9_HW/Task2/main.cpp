#include <iostream>
#define N 4
#define M 4

using namespace std;

// declare function
int divider(int[][M], size_t);

int main() {
	int sum,
		matrix[N][M] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 1, 2, 3},
		{4, 5, 6, 7}
	};

	sum = divider(matrix, M);
}

int divider(int matrix[][M],size_t len) {
	int sum;
	for (size_t row = 0; row < len; row++)
	{
		for (size_t col = 0; col < len; col++)
		{
			cout << matrix[row][col] << " ";
		}
		cout << endl;
	}
	return sum;
}