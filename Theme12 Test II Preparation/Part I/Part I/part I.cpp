#include <iostream>
#include <ctime>
#define M 3
#define N 3


using namespace std;

/*
Задача 1.
Да се съставят функции за:
А) запълване на елементите на правоъгълна матрица от цели числа със случайни стойности в интервал [-10, 80);
Б) отпечатване на стойностите от квадратна матрица в табличен вид;
В) намиране на минималният елемент от вторичния диагонал на матрицата;
Г) размяна на местата на елементите на матрица, като елементите по редове да станат елементи по стълбове;
*/
void matrix_fill(int arr[][N], size_t rows);
void matrix_print(int arr[][N], size_t rows);
int matrix_min_second_diagonal(int arr[][N], size_t rows);
void matrix_change(int arr[][N], size_t rows);

/*Задача 3. Да се състави програма на C++, чрез която от клавиатурата се въвежда изречение с отделни думи
(30..50 знака общо). Като резултат на екрана да се извежда същия текст, но всяка отделна дума да
започва с главна буква, а следващите я букви да са малки. */
void upperFirstLetter(char*);

/*Задача 4.
Да се състави програма на C++, чрез която се въвеждат от 10 до 50 цифри.
Програмата да извежда по колко цифри са въведени от всяка от цифрите от 0 до 9, както и коя е най-срещаната цифра.
*/

int* histogramDigits(char *);
void print_arr_int(int *, size_t);

/*
Задача 5.
Да се състави програма на C++, чрез която по въведен низ, съдържащ няколко думи,
се извежда най-дългата дума, която започва и завършва с един и същи знак.
Изречението трябва да съдържа максимален брой знаци [20..60] и максимален брой думи [3..10].
*/
char * longestWord(char *);

/*
Задача 8.
Да се състави функция, която чрез на случаен принцип генерира низ със случайно генерирана дължина,
съдържащ само малки или големи латински букви, както и интервали.
Функцията да връща като резултат хистограма на срещанията на символите от генерирания текст.
*/
char * stringGen();

/*Задача 9.
Да се състави рекурсивна функция, за отпечатване на триъгълник от главни латински букви. Потребителя въвежда начална и крайна буква, които да формират триъгълника.
Вход: B E
Изход:
B
C	C	C
D	D	D	D	D
E	E	E	E	E	E	E
*/
void print_alpha_triangle(char, char, size_t);
void print_empty_triangle(char, char, size_t);

int main() {
	srand(time(NULL));
	//Задача 3
	char * text = new char[100];
	do {
		cout << "Please enter text: ";
		cin.getline(text, 99);
	} while (strlen(text) < 30 || strlen(text) > 50);

	upperFirstLetter(text);
	cout << text << endl;

	//Задача 4
	cout << "Please enter a lot of digits: ";
	delete[] text;
	text = new char[100];
	cin.getline(text, 99);
	int * histo = NULL;
	histo = histogramDigits(text);
	print_arr_int(histo, 10);

	//Задача 5
	cout << "Please enter a text: ";
	delete[] text;
	text = new char[100];
	cin.getline(text, 99);
	char * word = NULL;
	word = longestWord(text);
	if (word != NULL)
		cout << word << endl;
	else cout << "No such word.\n";


	//Задача 8
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


