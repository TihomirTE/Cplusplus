#include <iostream>
#include <cmath>
#include <clocale>
#include <ctime>
#include <iomanip>

/*Задача 7. Нека имаме двумерен динамичен масив NxN от реални стойности. Да се напишат функции за:
A.	Въвеждане на стойности в масива на случаен принцип в интервал (-16, 166.23);
B.	Отпечатване на елементите на масив в табличен вид;
C.	Отпечатване на елементите от масива, които стоят в клетки образуващи пясачен часовник;
D.	Проверка дали сумите на елементите под главния диагонал и над него (но без него) са равни;
E.	Проверка дали произведението на елементите под главни диагонал е по-голямо от прозиведението на елементите под вторичния диагонал, но без да се включват диагоналите.
*/

using namespace std;
int zad7A(double **, unsigned);
int zad7B(double **, unsigned);
int zad7C(double **, unsigned);

int main() {
	setlocale(LC_ALL, "Bulgarian");
	unsigned N;
	cout << "Въведете N: ";
	cin >> N;
	double ** arr = new double*[N];
	for (unsigned i = 0; i<N; i++) {
		arr[i] = new double[N];
	}

	zad7A(arr, N);
	zad7B(arr, N);
	cout << endl << endl;
	zad7C(arr, N);

	for (unsigned i = 0; i<N; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}


int zad7A(double ** arr, unsigned N) {
	//(-16, 166.23)
	for (unsigned i = 0; i<N; i++) {
		for (unsigned j = 0; j<N; j++) {
			*(*(arr + i) + j) = (166.23 + 16)*(double)rand() / RAND_MAX - 15.9;
		}
	}
	return 0;
}

int zad7B(double ** arr, unsigned N) {
	for (unsigned i = 0; i<N; i++) {
		for (unsigned j = 0; j<N; j++) {
			cout << setw(8) << left << *(*(arr + i) + j) << " ";
		}
		cout << endl;
	}
	return 0;
}

int zad7C(double ** arr, unsigned N) {
	for (unsigned i = 0; i <= N / 2; i++) {
		for (unsigned j = i; j<N - i; j++) {
			cout << setw(8) << left << *(*(arr + i) + j) << " ";
		}
		cout << endl;
	}
	for (unsigned i = N / 2 + 1; i<N; i++) {
		for (unsigned j = N - 1 - i; j <= i; j++) {
			cout << setw(8) << left << *(*(arr + i) + j) << " ";
		}
		cout << endl;
	}
	return 0;
}
