#include<iostream>
#include<string>
#include<cctype>
#include<cstring>
//1
using namespace std;
void fun(const char* str, int n = 0)
{
	if (n == 0)
		cout << str << endl;
	else if (n > 0)
	{
		n--;
		cout << n << ' ';
		fun(str, n);
	}
}
int main()
{
	const char* str = "You need a cure.";
	fun(str);
	fun(str, 6);
	return 0;
}
//2
using namespace std;
struct CandyBar {
	string brand;
	double weight;
	int calories;
};
void CreateCandyBar(CandyBar& stru, const string bran = "Millennium",
	double weigh = 2.85, int calo = 350)
{
	stru.brand = bran;
	stru.weight = weigh;
	stru.calories = calo;
}
void ShowCandyBar(const CandyBar& stru)
{
	cout << "Here is the informations:" << endl;
	cout << "Brand:" << stru.brand << endl;
	cout << "Weight:" << stru.weight << endl;
	cout << "Energy:" << stru.calories << " Calories" << endl;
}
int main()
{
	cout << "Please provide the number of candies you want to deal:";
	int candy;
	while (!(cin >> candy))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "This is invalid.Try again:";
	}
	while (cin.get() != '\n')
		continue;
	CandyBar* candies = new CandyBar[candy];
	for (int i = 0; i < candy; i++)
	{
		cout << "Do you want to use the default set?" << endl;
		cout << "A.Yes                  B.No" << endl;
		char options;
		while (!(cin >> options) || ((options != 'A') && (options != 'B')))
		{
			cout << "Invalid.Try again:";
		}
		if (options == 'A')
			CreateCandyBar(candies[i]);
		else
		{
			cout << "Enter the brand:";
			string bran;
			getline(cin, bran);
			while (cin.get() != '\n')
				continue;
			cout << "Enter the weight:";
			double weigh;
			cin >> weigh;
			cout << "Enter the energy(unit:calories)";
			int calo;
			cin >> calo;
			CreateCandyBar(candies[i], bran, weigh, calo);
		}
	}
	cout << "Done created." << endl;
	for (int i = 0; i < candy; i++)
	{
		cout << "Candy " << (i + 1) << ':' << endl;
		ShowCandyBar(candies[i]);
	}
	return 0;
}
//3
using namespace std;
void Turn_Upper(string& str)
{
	int length = str.size();
	for (int i = 0; i < length; i++)
		str[i] = toupper(str[i]);
}
int main()
{
	cout << "Enter a string(Ctrl+Z to quit):";
	string strl;
	while ((getline(cin, strl)))
	{
		Turn_Upper(strl);
		cout << strl << endl;
		cout << "Next string(Ctrl+Z to quit):";
	}
	cout << "Bye." << endl;
	return 0;
}
//4
using namespace std;
struct stringy {
	char* str;
	int ct;
};
void set(stringy& str, char* strl)
{
	str.str = strl;
	str.ct = strlen(strl);
}
void show(stringy& str, int times = 1)
{
	for (int i = 0; i < times; i++)
	{
		cout << str.str << endl;
	}
}
void show(const char* str, int times = 1)
{
	for (int i = 0; i < times; i++)
	{
		cout << str << endl;
	}
}
//5
using namespace std;
template<typename T>
T maxn(T ar[], int n)
{
	T max = ar[0];
	int i = 1;
	while (ar[i] > max)
	{
		max = ar[i];
		i++;
	}
	return max;
}

int main()
{
	int ar1[5] = { 1,2,3,4,5 };
	double ar2[5] = { 1.0,3.0,5.1,6.9,9.0 };
	cout << maxn(ar1, 5) << endl;
	cout << maxn(ar2, 5) << endl;
	return 0;
}
//6
using namespace std;
template<typename T>
T maxn(T ar[], int n)
{
	T max = ar[0];
	int i = 1;
	while (ar[i] > max)
	{
		max = ar[i];
		i++;
	}
	return max;
}
template<>  string maxn<>(string ar[], int n)
{
	int* size = new int[n];
	for (int i = 0; i < n; i++)
		size[i] = ar[i].size();
	int max = size[0];
	int i = 1;
	while (size[i] > max)
	{
		max = size[i];
		i++;
	}
	return ar[i - 1];
}
int main()
{
	int ar1[6] = { 3829,321984,3982,1982,32109 };
	double ar2[4] = { 432.3242,342.342,543,514 };
	cout << maxn(ar1, 5) << endl;
	cout << maxn(ar2, 5) << endl;
	string ar3[3] = { "Aging and Disability Services Division Administrative Office.",
				   "3416 Goni Road, Suite D-132. Carson City, NV 89706 (775) 687-4210. adsd@adsd.nv.gov.",
				   " ADSD Fact Sheets 2019. ADSD Fact Sheets 2019" };
	cout << maxn(ar3, 3) << endl;
	return 0;
}
//7
using namespace std;
struct debts {
	char name[50];
	double amount;
};
template<typename T>
T SumArray(T arr[], int n)
{
	cout << "template A" << endl;
	T sum = arr[0];
	for (int i = 1; i < n; i++)
		sum += arr[i];
	return sum;
}
template<typename T>
T SumArray(T* arr[], int n)
{
	cout << "template B" << endl;
	T sum = *arr[0];
	for (int i = 1; i < n; i++)
		sum += *arr[i];
	return sum;
}
int main()
{
	int things[6] = { 13,21,103,301,310,130 };
	debts mr_E[3] = {
		{"Ima Wolfe",2400.0},
		{"Ura Foxe",1300.0},
		{"Iby Stout",1800.0}
	};
	double* pd[3];
	for (int i = 0; i < 3; i++)
		pd[i] = &(mr_E[i].amount);
	cout << "Summary of Mr.E's counts of things:";
	cout << SumArray(things, 6);
	cout << endl << "Summary of Mr.E's debts:";
	cout << SumArray(pd, 3) << endl;
	return 0;
}

