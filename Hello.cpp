#include <iostream>
#include <string>>
using namespace std;


void main()
{
	// Some of information for the user
	cout << "Hello! What is your name ? \n";
	string name;
	cin >> name;
	cout << "Hi, " << name << ".Nice to meet you. How are you ? \n";
	string feeling;
	cin >> feeling;
	cout << "Do you like to study informatics in NBU ? \n";
	string likeNBU;
	cin >> likeNBU;
	cout << "Which year are you ? \n";
	int yearOfStudy;
	cin >> yearOfStudy;
	cout << "Which term you are in ? \n";
	int termOfStudy;
	cin >> termOfStudy;

	// Print the information entered the user
	cout << "My name is " << name << ". \n";
	cout << "I am feeling " << feeling << ". \n";
	cout << likeNBU << ", I like to study informatics in NBU \n";
	cout << "I am " << yearOfStudy << " year \n";
	cout << "I am " << termOfStudy << " term \n";
	cout << "Bye :) \n";
}