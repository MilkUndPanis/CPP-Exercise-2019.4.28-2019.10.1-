#include<iostream>
#include<cstring>
#include<string>
//1
//golf.h
#pragma once//只要在头文件的头部加上#pragma once 就能保证头文件只被包含一次
//#include<iostream>
const int Len = 40;
struct golf {
	char fullname[Len];
	int handicap;
};
void setgolf(golf& g, const char* name, int hc);
int setgolf(golf& g);
void handicap(golf& g, int hc);
void showgolf(const golf& g);
//golf.cpp
//#include "golf.h"
void setgolf(golf& g, const char* name, int hc)
{
	int i;
	for (i = 0; i < strlen(name); i++)
		g.fullname[i] = name[i];
	g.fullname[i] = '\0';
	g.handicap = hc;
}
int setgolf(golf& g)
{
	std::cout << "Fullname:" << std::endl;
	std::cin.getline(g.fullname, Len);
	if (g.fullname[0] == '\0')
	{
		std::cout << "FAIL TO GET NAME." << std::endl;
		return 0;
	}
	else {
		std::cout << "Handicap:";
		std::cin >> g.handicap;
		return 1;
	}
}
void handicap(golf& g, int hc)
{
	g.handicap = hc;
}
void showgolf(const golf& g)
{
	std::cout << "Fullname" << g.fullname << std::endl;
	std::cout << "Handicap:" << g.handicap << std::endl;
}
//c9p1.cpp
//#include"golf.h"
int main()
{
	golf golf[2];
	setgolf(golf[0], "Ann Birdfree", 24);
	setgolf(golf[1]);
	showgolf(golf[0]);
	handicap(golf[0], 12);
	showgolf(golf[0]);
	return 0;
}
//2
void strcount(std::string str);
int main()
{
	using namespace std;
	string input;
	char next;
	cout << "Enter a line:" << endl;
	getline(cin, input);
	while (cin)/*Press Ctrl+Z to quit.*/
	{
		strcount(input);
		cout << "Enter next line(press Ctrl+Z to quit):" << endl;
		getline(cin, input);
	}
	cout << "Bye" << endl;
	return 0;
}
void strcount(std::string str)
{
	using namespace std;
	static int total = 0;
	int count = str.size();
	cout << "\"" << str << "\" contains ";
	total += count;
	cout << count << " characters" << endl;
	cout << total << " characters total" << endl;
}
//3
struct chaff {
	char dross[20];
	int slag;
};
char buffer[100];
int main()
{
	chaff* ar = new(buffer)chaff[2];
	for (int i = 0; i < 2; i++)
	{
		std::cout << "For the " << i + 1 << (i == 0 ? "st" : "nd") << " chaff,enter the dross:";
		std::cin.getline(ar[i].dross, 20);
		std::cout << "Enter the amount of slag:";
		std::cin >> ar[i].slag;
		while (std::cin.get() != '\n')
			continue;
	}
	for (int i = 0; i < 2; i++)
	{
		std::cout << i + 1 << (i == 0 ? "st" : "nd") << " chaff:" << std::endl;
		std::cout << "Dross:" << ar[i].dross << " Slag:" << ar[i].slag << std::endl;
	}
	return 0;
}
//4
//SALES.h
#pragma once
//#include<iostream>
namespace SALES {
	const int QUARTERS = 4;
	struct Sales {
		double Sales[QUARTERS];
		double average;
		double max;
		double min;
	};
	void setSales(Sales& s, const double ar[], int n);
	void setSales(Sales& s);
	void showSales(const Sales& s);
}
//Sales.cpp
//#include"SALES.h"
namespace SALES {
	using namespace std;
	void setSales(Sales& s, const double ar[], int n)
	{
		double sum = 0;
		int i;
		for (i = 0; i < n; i++)
		{
			s.Sales[i] = ar[i];
			sum += s.Sales[i];
		}
		s.average = sum / i;
		double max = s.Sales[0];
		for (int j = 1; j < i; j++)
		{
			if (s.Sales[j] > max)
				max = s.Sales[j];
		}
		s.max = max;
		double min = s.Sales[0];
		for (int j = 1; j < i; j++)
		{
			if (s.Sales[j] < min)
				min = s.Sales[j];
		}
		s.min = min;
	}
	void setSales(Sales& s)
	{
		cout << "Please provide sales for 4 quarters:" << endl;
		double temp;
		for (int i = 0; i < QUARTERS; i++)
		{
			cout << i + 1 << ':';
			while (!(cin >> temp))
			{
				cin.clear();
				while (cin.get() != '\n')
					continue;
				cout << "Error!Please try again:";
			}
			s.Sales[i] = temp;
			while (cin.get() != '\n')
				continue;
		}
		double sum = 0;
		for (int i = 0; i < QUARTERS; i++)
			sum += s.Sales[i];
		s.average = sum / QUARTERS;
		double max = s.Sales[0];
		for (int i = 1; i < QUARTERS; i++)
		{
			if (s.Sales[i] > max)
				max = s.Sales[i];
		}
		s.max = max;
		double min = s.Sales[0];
		for (int i = 1; i < QUARTERS; i++)
		{
			if (s.Sales[i] < min)
				min = s.Sales[i];
		}
		s.min = min;
	}
	void showSales(const Sales& s)
	{
		cout << "Four quarter's sales:" << endl;
		for (int i = 0; i < QUARTERS; i++)
		{
			cout << "QUARTER " << i + 1 << ":" << s.Sales[i] << endl;
		}
		cout << "Average sales for 4 quarters:" << s.average << endl;
		cout << "Maximum sales:" << s.max << endl;
		cout << "Minimum sales:" << s.min << endl;
	}
}
//c9p4.cpp
//#include"SALES.h"
using namespace SALES;
int main()
{
	Sales year_2019{};
	Sales year_2018{};
	double Sales_2018[4]{ 11.9,13.2,14.5,16.6 };
	setSales(year_2018, Sales_2018, 4);
	showSales(year_2018);
	setSales(year_2019);
	showSales(year_2019);
	return 0;
}
