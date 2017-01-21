#include <iostream>
#include <clocale>
#define M 5 // rows
#define N 4 // cols

using namespace std;

//�� �� ������ �������, ����� ������� ����������� �� ����������� ��
void swapver1(int, int); //�� ������ ��������, ������ ����������� �� ������� �� ��������, � �� �� ���������
void swapver2(int &, int &);
void swapver3(int *, int *);

//�� �� �������� �������, ����� ��������� ���������� �� �������� �����
void print(double[][N], size_t);

//�� �� �������� �������, ����� ������� �������� ����� � ������ �������� ���������
void fill(double[][N], size_t);

//�� �� �������� �������, ����� ������ ���� �� ���������� �� �������� �����, ����� ����� �� ������� ��������
double sum_diag(double arr[][N], size_t rows);

//�� �� �������� �������, ����� ������ ���� �� ���������� �� �������� �����, ����� ����� ��� ������� �������� � ���� �����������
double sum_under_diag(double arr[][N], size_t rows);



int main() {
	setlocale(LC_ALL, "Bulgarian");
	int x, y;
	cout << "���� �������� �������� �� x: ";
	cin >> x;
	cout << "���� �������� �������� �� y: ";
	cin >> y;
	swapver1(x, y);
	cout << "�������� �� x ���� ��������� " << x << endl;
	cout << "�������� �� y ���� ��������� " << y << endl;

	swapver2(x, y);
	cout << "�������� �� x ���� ��������� " << x << endl;
	cout << "�������� �� y ���� ��������� " << y << endl;

	swapver3(&x, &y);
	cout << "�������� �� x ���� ��������� " << x << endl;
	cout << "�������� �� y ���� ��������� " << y << endl;

	double matrix[M][N] = {
		{ 1.1, 2.2, 3.3, 4.4 },
		{ 1.2, 2.3, 3.4, 4.5 },
		{ 1.3, 2.4, 3.5, 4.6 },
		{ 1.4, 2.5, 3.6, 4.7 },
		{ 1.5, 2.6, 3.7, 4.8 }
	};

	cout << "O���������� �� ������: \n";
	print(matrix, M);
	cout << endl;
	cout << "������ �� ���������� �� ������� �������� �: "
		<< sum_diag(matrix, M) << endl;
	cout << "������ �� ���������� �� � ��� ������� �������� �: "
		<< sum_under_diag(matrix, M) << endl;

	fill(matrix, M);
	cout << "O���������� �� ������ ���� ���������: \n";
	print(matrix, M);
	return 0;
}

void swapver1(int a, int b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void swapver2(int & a, int & b) {
	int tmp = a;
	a = b;
	b = tmp;
}


void swapver3(int * a, int * b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

double sum_under_diag(double arr[][N], size_t rows) {
	double sum = 0.;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j <= i; j++)
		{
			sum += arr[i][j];
		}
	}
	return sum;
}

double sum_diag(double arr[][N], size_t rows) {
	size_t min = (rows < N) ? rows : N;
	double sum = 0.;
	for (size_t i = 0; i < min; i++)
	{
		sum += arr[i][i];
	}
	return sum;
}


void print(double arr[][N], size_t rows) {
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

void fill(double arr[][N], size_t rows) {
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			arr[i][j] = rand() + (double)rand() / RAND_MAX;
		}
	}
}
