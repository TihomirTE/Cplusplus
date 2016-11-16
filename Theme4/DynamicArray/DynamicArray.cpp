#include<iostream>
#include<new>

using namespace std;


int main()
{
	// Dynamic Array
	/*int num, *pointer;

	cout << "Enter number: ";
	cin >> num;

	pointer = new int[num];

	for (size_t i = 0; i < num; i++)
	{
	*(pointer + i) = i; // == ponter[i]
	cout << pointer[i] << " ";
	}
	cout << endl;*/

	// Dynamic 2D Array
	int num1, num2;
	cout << "Enter number 1: ";
	cin >> num1;
	cout << "Enter number 2: ";
	cin >> num2;

	int **matrix = new int *[num1];
	for (int row = 0; row < num1; row++)
	{
		matrix[row] = new int[num2];
	}

	for (int row = 0; row < num1; row++)
	{
		for (int col = 0; col < num2; col++)
		{
			cout << "matrix[" << row << "][" << col << "] ";
			cin >> matrix[row][col];
		}
	}

	for (int row = 0; row < num1; row++)
	{
		for (int col = 0; col < num2; col++)
		{
			cout << matrix[row][col] << " ";
		}
		cout << endl;
	}
}