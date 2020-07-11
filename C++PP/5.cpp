#include<iostream>
#include<array>
#include<string>
#include<cstring>
//1
using namespace std;
int main()
{
	cout << "Enter two interger:";
	int num1, num2;
	cin >> num1;
	cin >> num2;
	int sum = 0;
	for (int i = num1; i <= num2; i++)
		sum += i;
	cout << "The sum between " << num1
		<< " and " << num2
		<< " is " << sum
		<< " ." << endl;
	return 0;
}
//2
using namespace std;
const int Arsize = 100;
int main()
{
	array<long double, Arsize>facts;
	facts[1] = facts[0] = 1;
	for (int i = 2; i < Arsize; i++)
		facts[i] = facts[i - 1] * i;
	for (int i = 0; i < Arsize; i++)
		cout << i << " ! = " << facts[i] << endl;
	return 0;
}
//3
using namespace std;
int main()
{
	double num;
	double sum = 0;
	cout << "Enter a number now.";
	while ((cin >> num) && num != 0)
	{
		sum += num;
		cout << "Now the sum of numbers is " << sum << endl;
		cout << "Enter next number now.";
	}
	cout << "That's all." << endl;
	return 0;
}
//4
using namespace std;
int main()
{
	double daphne = 100;
	double cleo = 100;
	int year = 0;
	for (; cleo <= daphne; year++)
	{
		daphne += 10;
		cleo = cleo * 1.05;
		cout << "The " << year + 1 << " year,"
			"Daphne gain " << daphne << " dollars,and"
			"cleo gain" << cleo << " dollars." << endl;
	}
	cout << "The " << year << " year,Cleo had gained more money than Daphne." << endl;
	return 0;
}
//5
const int MONTH = 12;
using namespace std;
int main()
{
	string month[MONTH] = { "January","February","March","April",
					 "May","June","July","August",
					 "September","October","November","December" };
	double sales[MONTH];
	double sum = 0;
	for (int i = 0; i < MONTH; i++)
	{
		cout << "Please enter the sales quality of " << month[i] << ":";
		cin >> sales[i];
	}
	for (int i = 0; i < MONTH; i++)
		sum += sales[i];
	cout << "The following is every month's sales quality:" << endl;
	for (int i = 0; i < MONTH; i++)
	{
		cout << month[i] << ":" << sales[i] << endl;
	}
	cout << "The total sales of this year is:" << sum << endl;
	return 0;
}
//6
const int MONTH = 12;
const int YEAR = 3;
using namespace std;
int main()
{
	string month[MONTH] = { "January","February","March","April",
					 "May","June","July","August",
					 "September","October","November","December" };
	double sales[YEAR][MONTH];
	double sum[YEAR] = { 0,0,0 };
	double sum_total = 0;
	for (int j = 0; j < YEAR; j++)
	{
		cout << "Please enter the sales quality of year" << j + 1 << ":" << endl;
		for (int i = 0; i < MONTH; i++)
		{
			cout << "Please enter the sales quality of " << month[i] << ":";
			cin >> sales[j][i];
		}
	}
	for (int i = 0; i < YEAR; i++)
	{
		for (int j = 0; j < MONTH; j++)
			sum[i] += sales[i][j];
	}
	for (int i = 0; i < YEAR; i++)
		sum_total += sum[i];
	cout << "The following is every year's sales quality:" << endl;
	for (int j = 0; j < YEAR; j++)
	{
		cout << "Year " << j + 1 << endl;
		for (int i = 0; i < MONTH; i++)
		{
			cout << month[i] << ":" << sales[j][i] << endl;
		}
		cout << "The total sales of year " << j + 1 << " is:" << sum[j] << endl;
		cout << endl;
	}
	cout << "The total sales of three years is:" << sum_total << endl;
	return 0;
}
//7
using namespace std;
struct car {
	string car;
	int made;
};
int main()
{
	cout << "How many cars do you wish to catalog?";
	int num;
	cin >> num;
	cin.get();
	car* ps = new car[num];
	for (int i = 0; i < num; i++)
	{
		cout << "Car #" << i + 1 << ":" << endl;
		cout << "Please enter the make:";
		getline(cin, ps[i].car);
		cout << "Please enter the year made:";
		cin >> ps[i].made;
		cin.get();
	}
	cout << "Here is your colletions:" << endl;
	for (int i = 0; i < num; i++)
	{
		cout << ps[i].made
			<< " " << ps[i].car << endl;
	}
	return 0;
}
//8
using namespace std;
int main()
{
	char word[80];
	int total = 0;
	cout << "Enter words(to stop,type the word done)" << endl;
	while ((cin >> word) && (strcmp(word, "done")))
		total++;
	cout << "You entered a total of " << total << " words." << endl;
	return 0;
}
//9
using namespace std;
int main()
{
	string word;
	int total = 0;
	cout << "Enter words(to stop,type the word done)" << endl;
	while ((cin >> word) && (word != "done"))
		total++;
	cout << "You entered a total of " << total << " words." << endl;
	return 0;
}
//10
using namespace std;
int main()
{
	cout << "Enter number of rows:";
	int rows;
	cin >> rows;
	for (int i = 1; i <= rows; i++)
	{
		for (int j = 1; j <= rows - i; j++)
			cout << '.';
		for (int k = 1; k <= i; k++)
			cout << "*";
		cout << endl;
	}
	return 0;
}

