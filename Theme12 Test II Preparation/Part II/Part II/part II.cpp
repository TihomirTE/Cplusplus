//functions.h
#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

/*
������ 1.
�� �� �������� ������� ��:
�) ��������� �� ���������� �� ��������� ������� �� ���� ����� ��� �������� ��������� � �������� [-10, 80).
�) ����������� �� ����������� �� ��������� ������� � �������� ���
�) �������� �� ����������� ������� �� ��������� �������� �� ���������
�) ������� �� ������� �� ���������� �� �������, ���� ���������� �� ������ �� ������ �������� �� ��������
�) ���������� ������� �� ���������
�) �������� �� ���� �� ���������, ����� ��� ���������� ����
�) ������� �� ���������, ���� �� ����� �������� �� ���������, ����� �������� ��� ������ �� ��������� �� �������� �� ��������� �� �������, � ���������� �� �������� ��� ������ �� ��������� ���������� �� �������
�) ����������� �� ������ ����� �������� �� ��������� ��� ������ �� ���������� �� ������� ��������
�) �������� �� ���������� �� ��������� ���  �������� ���, ��� �� ������� �� ����� ��� �� ��������� � � �������� ��� �� ������� �� ������� ��� �� ���������

*/

//zad1a
int fillArray(int**, unsigned, unsigned, unsigned, unsigned);

//zad1b
int printArray(int**, unsigned, unsigned);

//zad1e
unsigned findMaxSumByRow(int**, unsigned, unsigned);

//zad1i
int sortArray(int**, unsigned, unsigned);


/*������ 4.
�� �� ������� �������� �� C++, ���� ����� �� �������� �� 10 �� 50 �����.
���������� �� ������� �� ����� ����� �� �������� �� ����� �� ������� �� 0 �� 9, ����� � ��� � ���-��������� �����.
*/
//zad4
int histogramString(char *);

/*������ 5.
�� �� ������� �������� �� C++, ���� ����� �� ������� ���, �������� ������� ����, �� ������� ���-������� ����,
����� ������� � �������� � ���� � ���� ����.
����������� ������ �� ������� ���������� ���� ����� [20..60] � ���������� ���� ���� [3..10].
*/
char * longestMirrorWord(char *);

/*
������ 6.
�� �� ������� �������� �� C++, ���� ����� �� ������� �����. ���������� �� ������� ���� ���������� �����, ��������� ��� ��������� ���. ������ �������� ����� �� �� ����� ��� �������� ���� ��� ����������� �� ���� ������ ��� �����. ������������ �� ������� �� ���� ������� � ��� �������� ��� �� ������ ���. ���������� �� ������ ���� ������� � �������� �����.
*/
char * printUniqueChars(char *, unsigned &);

//������� �������� ������� �� ���
size_t length(char *);

/*������ 8.
�� �� ������� �������, ����� �������� ��� �� ������� �������, ����� ������� ���� ����� � ������ �������� �����. ��������� �� ���� ���� �� � �������� ����������.
*/
char * genRandText();
#endif


//functions.cpp
#include "functions.h"
#include <iostream>

//zad1a
int fillArray(int** arr, unsigned n, unsigned m, unsigned begin, unsigned end) {
	for (unsigned i = 0; i<n; i++)
		for (unsigned j = 0; j<m; j++)
			arr[i][j] = rand() % (end - begin + 1) + begin;
	//ako elementite biaha doouble formulata e
	//arr[i][j] = (double)rand()/RAND_MAX*(end-begin)+begin;
	return 0;
}

//zad1b
int printArray(int** arr, unsigned n, unsigned m) {
	for (unsigned i = 0; i<n; i++) {
		for (unsigned j = 0; j<m; j++)
			std::cout << arr[i][j] << "\t";
		std::cout << "\n";
	}
	return 0;
}

//zad1e
unsigned findMaxSumByRow(int** arr, unsigned n, unsigned m) {
	int sum = 0;
	int maxSum = 0;
	unsigned maxRow = 0;
	for (unsigned i = 0; i<n; i++) {
		sum = 0;
		for (unsigned j = 0; j<m; j++) {
			sum += arr[i][j];
		}
		if (maxSum < sum) {
			maxSum = sum;
			maxRow = i;
		}
	}
	return maxRow;
}

//zad1i
void sort(int * arr, unsigned n, bool f) {
	for (unsigned i = 0; i<n; i++) {
		for (unsigned j = n - 1; j>i; --j) {
			if (f) {
				if (arr[j - 1]>arr[j]) {
					int tmp = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = tmp;
				}
			}
			else {
				if (arr[j - 1]<arr[j]) {
					int tmp = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = tmp;
				}
			}
		}
	}
}

int sortArray(int ** arr, unsigned n, unsigned m) {
	for (unsigned i = 0; i<n; i++) {
		if (i % 2 == 0)
			sort(arr[i], m, true);
		else
			sort(arr[i], m, false);
	}
	return 0;
}


//������� �������� ������� �� ���
size_t length(char * str) {
	unsigned pos = 0;
	while (str[pos++]);
	return pos;
}

//zad4
int histogramString(char * txt) {
	int digits[10] = { 0 };
	for (unsigned i = 0; i<strlen(txt); i++) {
		if (txt[i] >= 48 && txt[i] <= 57) digits[(int)txt[i] - 48]++;
		//ekvivalentno na
		//if(txt[i]>='0' && txt[i]<='9') digits[(int)txt[i]-48]++;
	}
	int max = digits[0];
	int ind = 0;
	for (int i = 0; i<10; i++) {
		if (max < digits[i]) {
			max = digits[i];
			ind = i;
		}
	}

	std::cout << "Histogram of digits occurance:\n";
	for (int i = 0; i<10; i++) {
		std::cout << i << " -> " << digits[i] << std::endl;
	}
	std::cout << "The most common digit is: " << ind << std::endl;
	return 0;
}


//zad5
char * longestMirrorWord(char * txt) {
	unsigned cnt = 0;//���� ����
	for (unsigned i = 0; i<strlen(txt); i++)
		if (txt[i] == ' ' || txt[i] == '.' || txt[i] == '!' || txt[i] == '?' || txt[i + 1] == '\0') cnt++;

	//�������� ����� �� ����
	char ** words = new char*[cnt];
	//�������������� �� ����� �� ����
	for (unsigned i = 0; i<cnt + 1; i++) {
		words[i] = new char[61];
	}

	int j = 0;//����� �� ����
	int k = 0;//����� �� ����� � ������

	for (unsigned i = 0; i<strlen(txt); i++) {

		if (txt[i] != ' ' && txt[i] != '.' && txt[i] != '!' && txt[i] != '?') {
			words[j][k] = txt[i];
			k++;
		}

		if (txt[i] == ' ' || txt[i] == '.' || txt[i] == '!' || txt[i] == '?' || txt[i + 1] == '\0') {
			words[j][k] = '\0';
			j++;//����� �� �������� ����
			k = 0;//������ �� ������ � �������� ����
		}

	}
	k = 0;
	unsigned maxLength = 0;
	char * word = new char[100];
	for (unsigned i = 0; i<cnt + 1; i++) {
		if (words[i][0] == words[i][strlen(words[i]) - 1]) {
			if (maxLength < strlen(words[i])) {
				maxLength = strlen(words[i]);
				delete[] word;
				word = new char[strlen(words[i]) + 1];
				strcpy(word, words[i]);
			}
		}
	}

	return word;
}

//zad6
char * printUniqueChars(char * txt, unsigned & cnt) {
	char * arr = new char[26];
	std::fill_n(arr, 26, '0');
	unsigned i = 0;
	while (txt[i]) {
		if (txt[i] >= 'a' && txt[i] <= 'z')
			arr[txt[i] - 'a'] = txt[i];
		else if (txt[i] >= 'A' && txt[i] <= 'Z')
			arr[txt[i] - 'A'] = txt[i] + 32;
		i++;
	}
	cnt = 0;
	for (unsigned j = 0; j<26; j++)
		if (arr[j] != '0')	cnt++;

	char * arrUnique = new char[cnt + 1];
	unsigned k = 0;
	for (unsigned j = 0; j<26; j++) {
		if (arr[j] != '0') {
			arrUnique[k] = arr[j];
			k++;
		}
	}
	arrUnique[cnt] = '\0';
	return arrUnique;
}

//zad8
char * genRandText() {
	unsigned len = rand() % 91 + 10, tmp;
	unsigned ch[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26 };//0..25->a..z, a 26  �� �������� �� ��������
	char * genTxt = new char[len + 1];
	for (unsigned i = 0; i<len; i++) {
		if (i == 0) genTxt[i] = (char)(ch[rand() % 26] + 65);//������ �����
		else {
			tmp = ch[rand() % 27];
			if (tmp == 26) genTxt[i] = ' ';
			else genTxt[i] = (char)(tmp + 97);
		}
	}
	genTxt[len] = '\0';
	return genTxt;
}


//main.cpp
#include "functions.h"
#include <iostream>
#include <ctime>

using namespace std;

int main() {
	unsigned N = 5, M = 7;

	//������ ���� �� ������ 1
	cout << "Start task 1:\n";
	srand(time(NULL));

	int ** matrix = new int *[N];
	for (int i = 0; i < N; ++i)
		matrix[i] = new int[M];

	fillArray(matrix, N, M, -10, 123);
	printArray(matrix, N, M);
	cout << "Find the row with maximum sum " << findMaxSumByRow(matrix, N, M) << endl;
	cout << "Sort matrix \n";
	sortArray(matrix, N, M);
	printArray(matrix, N, M);
	for (int i = 0; i < N; ++i)
		delete[] matrix[i];
	delete[] matrix;

	cout << "End task 1!\n";

	cout << "Start task 4:\n";
	//���� ������ 4
	char * number = new char[61];
	cout << "Enter big number: ";
	cin.getline(number, 50);
	histogramString(number);
	delete[] number;
	cout << "End task 4:\n";

	cout << "Start task 5:\n";
	//���� ������ 5
	char * sentance = new char[256];
	cout << "Enter sentance to find longest word: ";
	cin.getline(sentance, 250);
	//sentance = "alabala tral la la la.";
	char * word;
	word = longestMirrorWord(sentance);
	cout << "The longest word is: " << word << endl;
	cout << "The longest word is long: " << strlen(word) << endl;

	delete[] word;
	cout << "End task 5:\n";

	cout << "Start task 6:\n";
	//���� ������ 6
	char * text = new char[256];
	cout << "Enter text to find unique chars: ";
	cin.getline(text, 250);
	unsigned count;
	char * arr;
	arr = printUniqueChars(text, count);

	cout << "Unique characters are: " << arr << endl;
	delete[] arr;
	cout << "End task 6:\n";

	cout << "Start task 8:\n";
	//���� ������ 8
	char * genStr = genRandText();
	cout << "Auto random generated string is: " << genStr << endl;
	delete[] genStr;
	cout << "End task 8:\n";

	return 0;
}

