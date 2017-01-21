#include <iostream>
#include <ctime>
#define M 3
#define N 3


using namespace std;

/*
������ 1.
�� �� �������� ������� ��:
�) ��������� �� ���������� �� ����������� ������� �� ���� ����� ��� �������� ��������� � �������� [-10, 80);
�) ����������� �� ����������� �� ��������� ������� � �������� ���;
�) �������� �� ����������� ������� �� ��������� �������� �� ���������;
�) ������� �� ������� �� ���������� �� �������, ���� ���������� �� ������ �� ������ �������� �� ��������;
*/
void matrix_fill(int arr[][N], size_t rows);
void matrix_print(int arr[][N], size_t rows);
int matrix_min_second_diagonal(int arr[][N], size_t rows);
void matrix_change(int arr[][N], size_t rows);

/*������ 3. �� �� ������� �������� �� C++, ���� ����� �� ������������ �� ������� ��������� � ������� ����
(30..50 ����� ����). ���� �������� �� ������ �� �� ������� ����� �����, �� ����� ������� ���� ��
������� � ������ �����, � ���������� � ����� �� �� �����. */
void upperFirstLetter(char*);

/*������ 4.
�� �� ������� �������� �� C++, ���� ����� �� �������� �� 10 �� 50 �����.
���������� �� ������� �� ����� ����� �� �������� �� ����� �� ������� �� 0 �� 9, ����� � ��� � ���-��������� �����.
*/

int* histogramDigits(char *);
void print_arr_int(int *, size_t);

/*
������ 5.
�� �� ������� �������� �� C++, ���� ����� �� ������� ���, �������� ������� ����,
�� ������� ���-������� ����, ����� ������� � �������� � ���� � ���� ����.
����������� ������ �� ������� ���������� ���� ����� [20..60] � ���������� ���� ���� [3..10].
*/
char * longestWord(char *);

/*
������ 8.
�� �� ������� �������, ����� ���� �� ������� ������� �������� ��� ��� �������� ���������� �������,
�������� ���� ����� ��� ������ �������� �����, ����� � ���������.
��������� �� ����� ���� �������� ���������� �� ���������� �� ��������� �� ����������� �����.
*/
char * stringGen();

/*������ 9.
�� �� ������� ���������� �������, �� ����������� �� ���������� �� ������ �������� �����. ����������� ������� ������� � ������ �����, ����� �� �������� �����������.
����: B E
�����:
B
C	C	C
D	D	D	D	D
E	E	E	E	E	E	E
*/
void print_alpha_triangle(char, char, size_t);
void print_empty_triangle(char, char, size_t);

int main() {
	srand(time(NULL));
	//������ 3
	char * text = new char[100];
	do {
		cout << "Please enter text: ";
		cin.getline(text, 99);
	} while (strlen(text) < 30 || strlen(text) > 50);

	upperFirstLetter(text);
	cout << text << endl;

	//������ 4
	cout << "Please enter a lot of digits: ";
	delete[] text;
	text = new char[100];
	cin.getline(text, 99);
	int * histo = NULL;
	histo = histogramDigits(text);
	print_arr_int(histo, 10);

	//������ 5
	cout << "Please enter a text: ";
	delete[] text;
	text = new char[100];
	cin.getline(text, 99);
	char * word = NULL;
	word = longestWord(text);
	if (word != NULL)
		cout << word << endl;
	else cout << "No such word.\n";


	//������ 8
	char * str = NULL;
	str = stringGen();
	cout << str << endl;

	print_alpha_triangle('B', 'E', 0);
	print_empty_triangle('B', 'E', 0);

	int mtx[M][N];
	matrix_fill(mtx, N);
	matrix_print(mtx, N);
	cout << endl << "Min on the second diagonal: " << matrix_min_second_diagonal(mtx, N) << endl;
	matrix_change(mtx, N);
	matrix_print(mtx, N);


	delete[] str;
	delete[] word;
	delete[] histo;
	delete[] text;
	return 0;
}

void upperFirstLetter(char * txt) {
	size_t length = strlen(txt);
	bool flag = false;
	for (size_t i = 0; i < length; i++)
	{
		if ((txt[i] >= 'a' && txt[i] <= 'z') || (txt[i] >= 'A' && txt[i] <= 'Z')) 
		{
			if ((txt[i] >= 'a' && txt[i] <= 'z') && !flag) // first small letter of word
			{
				txt[i] -= 32; // become upper

			}
			else if ((txt[i] >= 'A' && txt[i] <= 'Z') && flag) // upper letter in word
			{
				txt[i] += 32; // become lower
			}
			flag = true; // in the word
		}
		else flag = false; // not in word
	}
}

int* histogramDigits(char * str) {
	size_t sz = strlen(str);
	int * histo = new int[10];

	for (size_t i = 0; i < 10; i++) 
	{
		histo[i] = 0;
	}
	for (size_t i = 0; i < sz; i++) 
	{
		histo[str[i] - '0']++; // counting how many times digit contain in sz
	}
	return histo;
}

void print_arr_int(int * arr, size_t sz) {
	for (size_t i = 0; i < sz; i++) 
	{
		// i -> position            arr[i] -> contain quantities
		cout << i << " is found " << arr[i] << " times\n";
	}
}

char * longestWord(char * str) {

	size_t sz = strlen(str);
	bool flag = false;
	size_t curr_count = 0;
	size_t max_count = 0;
	size_t end_index = 0;
	char beg;
	char end;
	for (size_t i = 0; i < sz; i++) 
	{
		if (!((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)) || i == sz - 1) 
		{
			if (i == sz - 1)curr_count++;

			flag = false;
			end = (i == sz - 1) ? str[i] : str[i - 1];
			if (beg == end && curr_count >= max_count) 
			{
				max_count = curr_count;// 
				end_index = (i == sz - 1) ? i : i - 1;
			}
			curr_count = 0;
		}
		else 
		{
			//cout << str[i] << endl;
			if (!flag) beg = str[i];
			curr_count++;
			flag = true;
		}
	}
	if (max_count && end_index) 
	{
		char * longestword = new char[max_count + 1];
		for (size_t i = end_index - max_count + 1, j = 0; i <= end_index; i++, j++) 
		{
			longestword[j] = str[i];
		}
		longestword[max_count] = '\0';
		return longestword;
	}
	return NULL;
}

char * stringGen() {
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ";
	size_t length = rand() % 271 + 30;//text length [30, 300]
	char * tmp = new char[length + 1];
	for (size_t i = 0; i < length; i++) 
	{
		tmp[i] = alphabet[rand() % 54];
	}
	tmp[length] = '\0';
	return tmp;
}

void print_alpha_triangle(char beg, char end, size_t row) {
	for (size_t i = 0; i < end - beg + 1 - row; i++) 
		cout << ' ';
	for (size_t i = 0; i < 2 * row + 1; i++) 
		cout << (char)(beg + row);
	cout << endl;
	if (row < end - beg)
	{
		print_alpha_triangle(beg, end, ++row);
	}

}

void print_empty_triangle(char beg, char end, size_t row) {
	for (size_t i = 0; i < end - beg - row + 1; i++) 
		cout << ' ';
	for (size_t i = 0; i < 2 * row + 1; i++) 
	{
		if ((row == 0 || row == end - beg) || (i == 0 || i == 2 * row)) cout << (char)(beg + row);
		else cout << ' ';
	}
	cout << endl;
	if (row < end - beg) 
	{
		print_empty_triangle(beg, end, ++row);
	}

}

void matrix_fill(int arr[][N], size_t rows) {
	//[-10, 80)
	for (size_t i = 0; i < rows; i++) 
	{
		for (size_t j = 0; j < N; j++) 
		{
			arr[i][j] = rand() % 90 - 10;
		}
	}
}

void matrix_print(int arr[][N], size_t rows) {
	for (size_t i = 0; i < rows; i++) 
	{
		for (size_t j = 0; j < N; j++) 
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

int matrix_min_second_diagonal(int arr[][N], size_t rows) {
	int min = arr[0][N - 1];
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			if (i + j == N - 1) {
				if (min > arr[i][j])
					min = arr[i][j];
			}
		}
	}
	return min;
}

void matrix_change(int arr[][N], size_t rows) {
	for (size_t i = 0; i < rows; i++) 
	{
		for (size_t j = 0; j < N; j++)
		{
			int tmp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = tmp;
		}
	}
}


