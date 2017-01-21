#include <iostream>
using namespace std;

void divider(int arr[],int len) {
	int count = 1;
	for (size_t i = 0; i < len; i++)
	{
		cout << "Number " << arr[i] << " has dividers: ";
		while (count <= arr[i])
		{
			if (arr[i] % count == 0)
			{
				cout << count << " ";
			}
			count++;
		}
		count = 1;
		cout << endl;
	}
}


int main() {
	int arr[5] = { 2, 3, 10, 21, 25 };
	divider(arr, 5);
	return 0;
}