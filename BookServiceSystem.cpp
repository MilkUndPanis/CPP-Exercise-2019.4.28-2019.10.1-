#include<iostream>
#include<cstdbool>
#include<string>
using namespace std;
const int Y = 1;
const int N = 0;
const int TOTAL_SEAT = 100;
const int TOTAL_BOOKER = 3;
const int ROW = 20;
const int COL = 5;
bool seats[ROW][COL]{};
struct meal {
	bool adult;
	bool child;
	bool Huizu;
}meals[ROW][COL]{};
struct information {
	int identity[18];
	string name;
	bool ticket;
	bool nation;
}info[ROW][COL];
int adults = 0;
int Huizu = 0;
int child = 0;
information& input(information& imf)
{
	cout << "Please enter booker's ID number:";
	unsigned long long temp;
	while (!(cin >> temp) || (temp < 100000000000000000))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "Please enter a 18-bit number.Try again:";
		continue;
	}
	for (int i = 17; i >= 0; i--)
	{
		imf.identity[i] = temp % 10;
		temp /= 10;
	}
	cout << "Your name?";
	getline(cin, imf.name);
	while (cin.get() != '\n')
		continue;
	cout << "Please enter the type of seat:" << endl;
	cout << "A.Business Class           B.Economy Class" << endl;
	char option;
	while (!(cin >> option) || ((option != 'A') && (option != 'B')))
	{
		while (cin.get() != '\n')
			continue;
		cout << "This is invalid.Try again:";
	}
	while (cin.get() != '\n')
		continue;
	if (option == 'A')
		imf.ticket = 1;
	else if (option == 'B')
		imf.ticket = 0;
	cout << "Now tell us whether you are a Huizu:" << endl;
	cout << "Y.Yes              N.No" << endl;
	char op;
	while (!(cin >> op) || ((op != 'Y') && (op != 'N')))
	{
		while (cin.get() != '\n')
			continue;
		cout << "This is invalid.Try again:";
	}
	while (cin.get() != '\n')
		continue;
	if (op == 'Y')
		imf.nation = Y;
	else if (op == 'N')
		imf.nation = N;
	return imf;
}
void bookseat(information& imf)
{
	if (imf.ticket == 1)
		cout << "You want to book a business class." << endl;
	if (imf.ticket == 0)
		cout << "You want to  book a economy class." << endl;
	cout << "Here is all of blank seats:" << endl;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
			if (!seats[i][j])
				cout << "Row" << i << ",Column" << j << " is empty.";
		cout << endl;
	}
	cout << "According above imformation,please provide where you want to book(row,column):";
	int row;
	int col;
	cin >> row;
	cin >> col;
	while (seats[row][col] == 1)
	{
		cout << "This seat is booked.Try again:" << endl;
		cin >> row;
		cin >> col;
	}
	while ((row < 0) || (row >= 20) || (col < 0) || (col >= 5))
	{
		cout << "This is invalid.Try again:" << endl;
		cin >> row;
		cin >> col;
	}
	while ((imf.ticket == 1) && (row > 4))
	{
		cout << "You want to book a business class.Row 5-19 is economy class.Please try again:";
		cin >> row;
		cin >> col;
	}
	while ((imf.ticket == 0) && (row <= 4))
	{
		cout << "You want to book a economy class.Row 0-4 is business class.Please try again:";
		cin >> row;
		cin >> col;
	}
	seats[row][col] = 1;
	info[row][col] = imf;
}
void sysmeal(void)
{
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
		{
			int birth_year = (info[i][j].identity[6] * 1000)
				+ (info[i][j].identity[7] * 100)
				+ (info[i][j].identity[8] * 10)
				+ (info[i][j].identity[9] * 1);
			if (birth_year != 0000)
			{
				if (info[i][j].nation == Y)
					meals[i][j].Huizu = 1;
				else if (2019 - birth_year > 8)
					meals[i][j].adult = 1;
				else if (2019 - birth_year <= 8)
					meals[i][j].child = 1;
			}
		}
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
		{
			if (meals[i][j].adult == 1)
				adults++;
			if (meals[i][j].child == 1)
				child++;
			if (meals[i][j].Huizu == 1)
				Huizu++;
		}
	cout << "We need prepare:" << endl;
	cout << adults << " adults meal;" << endl;
	cout << child << " child meal;" << endl;
	cout << Huizu << " Huizu meal;" << endl;
}
void printinfo(void)
{
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
		{
			cout << "Here is the information of seat:row " << i << " column " << j << endl;
			cout << "ID card number:";
			for (int k = 0; k < 18; k++)
				cout << info[i][j].identity[k];
			cout << endl;
			cout << "Name:";
			cout << info[i][j].name;
			cout << "Type of ticket:";
			if (info[i][j].ticket == 1)
				cout << "Business Class" << endl;
			else if (info[i][j].identity[0] == 0) cout << "Empty" << endl;
			else cout << "Economy Class" << endl;
			cout << "Huizu?";
			if (info[i][j].nation == Y)
				cout << "Yes" << endl;
			else if (info[i][j].identity[0] == 0) cout << "Empty" << endl;
			else cout << "No" << endl;
		}
}
int main()
{
	information book_info;
	int i = 0;
	for (; i < TOTAL_BOOKER; i++)
	{
		cout << "Welcome to the booking service!" << endl;
		book_info = input(book_info);
		bookseat(book_info);
		cout << "Booked success." << endl;
	}
	sysmeal();
	printinfo();
	return 0;
}
