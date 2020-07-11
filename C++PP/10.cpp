#include<iostream>
#include<string>
#include<cctype>
#include<cstring>
//1
using namespace std;
class Account {
private:
	string name;
	string account;
	double deposit;
public:
	Account(const string&, const string&, double);
	void Show();
	void AddDeposit(double);
	void OutDeposit(double);
	~Account();
};
Account::Account(const string& n = "Xi JPNG", const string& a = "1234567890123456", double d = 0.0)
{
	name = n;
	account = a;
	deposit = d;
}
Account::~Account()
{

}
void Account::Show()
{
	cout.precision(10);
	cout << "Name:" << name << endl;
	cout << "Bank account number:" << account << endl;
	cout << "Deposit:" << deposit << endl;
}
void Account::AddDeposit(double n)
{
	deposit += n;
}
void Account::OutDeposit(double n)
{
	deposit -= n;
}
int main()
{
	Account a1;
	Account a2 = Account("Abraham Lincoln", "18091865", 120.0);
	Account a3("Sjsal ajsjsq", "27381973", 222);
	Account a4{ "Tadokoro Kouji","11451419",198108.93 };
	a1.Show();
	a2.Show();
	a3.Show();
	a4.Show();
	a1.AddDeposit(398172398713);
	a1.Show();
	a4.AddDeposit(114514);
	a4.Show();
	a4.OutDeposit(1919);
	a4.Show();
	cout << "Create an account through an interactive way:" << endl;
	string name;
	string account;
	double deposit;
	cout << "Name:";
	getline(cin, name);
	while (cin.get() != '\n')
		continue;
	cout << "Account number:";
	getline(cin, account);
	while (cin.get() != '\n')
		continue;
	cout << "Deposit:";
	cin >> deposit;
	Account a(name, account, deposit);
	a.Show();
	return 0;
}
//2
using namespace std;
class Person {
private:
	static const int LIMIT = 25;
	string lname;
	char fname[LIMIT];
public:
	Person() {
		lname = "";
		fname[0] = '\0';
	}//默认
	Person(const string& ln, const char* fn = "Heyyou");//非默认
	void Show()const;
	void FormalShow()const;
};
Person::Person(const string& ln, const char* fn)
//在头文件，函数声明中设置默认值，在函数实现部分，应该把默认值去掉
{
	lname = ln;
	int i;
	for (i = 0; i < strlen(fn); i++)
		fname[i] = fn[i];
	fname[i + 1] = '\0';
}
void Person::Show()const
{
	cout << "First name:" << fname << endl;
	cout << "Last name:" << lname << endl;
}
void Person::FormalShow()const
{
	cout << "Last name" << lname << endl;
	cout << "First name:" << fname << endl;
}
int main()
{
	Person one;
	Person two = Person("Smythecraft");
	Person three("Dimwiddy", "Sam");
	one.Show();
	cout << endl;
	one.FormalShow();
	cout << endl;
	two.Show();
	two.FormalShow();
	cout << endl;
	three.Show();
	cout << endl;
	three.FormalShow();
	cout << endl;
	return 0;
}
//3
//golf.h
#pragma once
//#include<iostream>
class golf {
private:
	static const int Len = 40;
	char fullname[Len];
	int handicap;
public:
	golf(const char* name = " ", int hc = 0);
	int setgolf();
	void Change_Handicap(int hc);
	void showgolf();
};
//golf.cpp
//#include"golf.h"
using namespace std;
golf::golf(const char* name, int hc)
{
	int i;
	for (i = 0; i < strlen(name); i++)
		fullname[i] = name[i];
	fullname[i + 1] = '\0';
	handicap = hc;
}
int golf::setgolf()
{
	char name[Len];
	int hc;
	cout << "Fullname:" << endl;
	cin.getline(name, Len);
	if (name[0] == '\0')
	{
		cerr << "FAIL TO GET NAME." << endl;
		return 0;
	}
	else {
		int i;
		for (i = 0; i < strlen(name); i++)
			fullname[i] = name[i];
		fullname[i + 1] = '\0';
		cout << "Handicap:";
		cin >> hc;
		handicap = hc;
		return 1;
	}
}
void golf::Change_Handicap(int hc)
{
	handicap = hc;
}
void golf::showgolf()
{
	std::cout << "Fullname:" << fullname << std::endl;
	std::cout << "Handicap:" << handicap << std::endl;
}
//c10p3.cpp
//#include"golf.h"
int main()
{
	golf p[2];
	p[0] = golf("Ann Birdfree", 24);
	p[1].setgolf();
	p[0].showgolf();
	p[1].showgolf();
	p[0].Change_Handicap(12);
	p[0].showgolf();
	return 0;
}
//4.
//SALES.h
#pragma once
//#include<iostream>
class Sales {
private:
	static const int QUARTERS = 4;
	double sales[QUARTERS];
	double average;
	double max;
	double min;
public:
	Sales();
	Sales(const double ar[], int n = 4);
	void setSales();
	void showSales();
};
//Sales.cpp
//#include"SALES.h"
using namespace std;
Sales::Sales()
{
	sales[0] = sales[1] = sales[2] = sales[3] = 0;
	average = 0;
	min = 0;
	max = 0;
}
Sales::Sales(const double ar[], int n)
{
	double sum = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		sales[i] = ar[i];
		sum += sales[i];
	}
	average = sum / i;
	double maxi = sales[0];
	for (int j = 1; j < i; j++)
	{
		if (sales[j] > maxi)
			maxi = sales[j];
	}
	max = maxi;
	double mini = sales[0];
	for (int j = 1; j < i; j++)
	{
		if (sales[j] < mini)
			mini = sales[j];
	}
	min = mini;
}
void Sales::setSales()
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
		sales[i] = temp;
		while (cin.get() != '\n')
			continue;
	}
	double sum = 0;
	for (int i = 0; i < QUARTERS; i++)
		sum += sales[i];
	average = sum / QUARTERS;
	double maxi = sales[0];
	for (int i = 1; i < QUARTERS; i++)
	{
		if (sales[i] > maxi)
			maxi = sales[i];
	}
	max = maxi;
	double mini = sales[0];
	for (int i = 1; i < QUARTERS; i++)
	{
		if (sales[i] < mini)
			mini = sales[i];
	}
	min = mini;
}
void Sales::showSales()
{
	cout << "Four quarter's sales:" << endl;
	for (int i = 0; i < QUARTERS; i++)
	{
		cout << "QUARTER " << i + 1 << ":" << sales[i] << endl;
	}
	cout << "Average sales for 4 quarters:" << average << endl;
	cout << "Maximum sales:" << max << endl;
	cout << "Minimum sales:" << min << endl;
}
//c10p4.cpp
//#include"SALES.h"
int main()
{
	double ar[4] = { 11,13,15,17 };
	Sales Sales_2019(ar, 4);
	Sales Sales_2018;
	Sales_2018.setSales();
	Sales_2019.showSales();
	Sales_2018.showSales();
	return 0;
}
//5.
//Stack.h
#pragma once
//#include<iostream>
typedef struct customer {
	char fullname[35];
	double payment;
}Item;
class Stack {
private:
	static const int MAX = 10;
	Item items[MAX];
	double total_pay;
	int top;
public:
	Stack();
	bool isempty()const;
	bool isfull()const;
	bool push(const Item& item);
	bool pop(Item& item);
	double showtotal();
};
//Stack.cpp
//#include"Stack.h"
using namespace std;
Stack::Stack()
{
	total_pay = 0.0;
	top = 0;
}
bool Stack::isempty()const
{
	return top == 0;
}
bool Stack::isfull()const
{
	return top == MAX;
}
bool Stack::push(const Item& item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else return false;
}
bool Stack::pop(Item& item)
{
	if (top > 0)
	{
		total_pay += item.payment;
		item = items[top--];
		return true;
	}
	else
		return false;
}
double Stack::showtotal()
{
	return total_pay;
}
//c10p5.cpp
//#include"Stack.h"
using namespace std;
int main()
{
	Stack s;
	char ch;
	Item i;
	char name[35];
	double pay;
	cout << "Please enter A to add a purchase order." << endl;
	cout << "p to process a PO,or Q to quit." << endl;
	while (cin >> ch && toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch))
		{
			cout << '\a' << endl;
			continue;
		}
		switch (ch)
		{
		case 'A':
		case 'a': {
			cout << "Enter your name:";
			cin.getline(name, 35);
			int j = 0;
			for (; j < strlen(name); j++)
				i.fullname[j] = name[j];
			i.fullname[j + 1] = '\0';
			while (cin.get() != '\n')
				continue;
			cout << "Enter the amount you paid:";
			cin >> pay;
			i.payment = pay;
			if (s.isfull())
				cerr << "Stack is already full." << endl;
			else
			{
				s.push(i);
				cout << "Already paid." << endl;
			}
		}break;
		case 'p':
		case 'P': {
			if (s.isempty())
				cerr << "Stack is already empty." << endl;
			else {
				s.pop(i);
				cout << "Popped." << endl;
				cout << "The total payment is " << s.showtotal() << '.' << endl;
			}
			break;
		}
		}
		cout << "Please enter A to add a purchase order." << endl;
		cout << "p to process a PO,or Q to quit." << endl;
	}
	cout << "Bye." << endl;
	return 0;
}
//6.
//Move.h
#pragma once
//#include<iostream>
class Move {
private:
	double x;
	double y;
public:
	Move(double a = 0, double b = 0);
	void showmove()const;
	Move add(const Move& m)const;
	void reset(double a = 0, double b = 0);
};
//Move.cpp
//#include"Move.h"
using namespace std;
Move::Move(double a, double b)
{
	x = a;
	y = b;
}
void Move::showmove()const
{
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;
}
Move Move::add(const Move& m)const
{
	Move a;
	a.x = m.x;
	a.y = m.y;
	return a;
}
void Move::reset(double a, double b)
{
	x = a;
	y = b;
}
//c10p6.cpp
//#include"Move.h"
using namespace std;
int main()
{
	Move m1;
	m1.showmove();
	m1.reset(2, 3);
	m1.showmove();
	const Move m2(4, 5);
	m1 = m1.add(m2);
	m1.showmove();
	return 0;
}
//7.
//plorg.h
#pragma once
//#include<iostream>
class plorg {
private:
	static const int MAX = 19;
	char fullname[MAX];
	int CI;
public:
	plorg(const char n_name[] = "Plorga", int ci = 50);
	void report()const;
	void reset_name(const char n_name[]);
	void reset_ci(int ci);
	~plorg();
};
//plorg.cpp
//#include"plorg.h"
using namespace std;
plorg::plorg(const char n_name[], int ci)
{
	int i = 0;
	for (; i < strlen(n_name); i++)
		fullname[i] = n_name[i];
	fullname[i + 1] = '\0';
	CI = ci;
}
void plorg::report()const
{
	cout << "Name:" << fullname << endl;
	cout << "Satisfactory index(CI):" << CI << endl;
}
void plorg::reset_name(const char n_name[])
{
	int i = 0;
	for (; i < strlen(n_name); i++)
		fullname[i] = n_name[i];
	fullname[i + 1] = '\0';
}
void plorg::reset_ci(int ci)
{
	CI = ci;
}
plorg::~plorg()
{
	cout << "Bye." << endl;
}
//c10p7.cpp
//#include"plorg.h"
using namespace std;
int main()
{
	plorg p;
	p.report();
	p.reset_name("#PRAGMA ONCE");
	p.reset_ci(100);
	p.report();
	//不用也不能显式地调用析构函数
	return 0;
}
//8.
//List.h,列表存储一个学生不同科目的成绩
#pragma once
//#include<iostream>
//#include<string>
using namespace std;
const int propotion_0 = 3;
const int propotion_1 = 4;
const int propotion_2 = 5;
const int propotion_3 = 4;
const int propotion_4 = 3;//各科成绩的学分
const int propotion_ = propotion_0 + propotion_1 +
propotion_2 + propotion_3 + propotion_4;
typedef struct {
	string fullname;
	double score[5];//各科绩点
	double GPA;
}list;
class List {
private:
	static const int MAX = 26;
	list LIST_[MAX];
	int top;
public:
	List();
	void Add_to_list();
	bool IsEmpty()const;
	bool IsFull()const;
	void Showlist()const;
	void GPA_sequence()const;
	void VisitList(void(*pfun)(list&), list&);
	void VisitThroughList(void(*pfun)(list&));
	void DeleteList(int);//删除列表第n个项目
	int Showtop()const;
	~List();
};
//List.cpp
//#include"List.h"
using namespace std;
List::List()
{
	for (int i = 0; i < MAX; i++)
	{
		LIST_[i].fullname = " ";
		for (int j = 0; j < 5; j++)
			LIST_[i].score[j] = 0.0;
		LIST_[i].GPA = 0.0;
	}
	top = 0;
}
void List::Add_to_list()
{
	list l;
	string n;
	cout << "Enter your name:";
	getline(cin, n);
	while (cin.get() != '\n')
		continue;
	l.fullname = n;
	cout << "Enter your score:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << ":";
		double s;
		while (!(cin >> s))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cerr << "Invalid input.Try again:";
		}
		l.score[i] = s;
	}
	l.GPA = l.score[0] * (propotion_0 / propotion_) +
		l.score[1] * (propotion_1 / propotion_) +
		l.score[2] * (propotion_2 / propotion_) +
		l.score[3] * (propotion_3 / propotion_) +
		l.score[4] * (propotion_4 / propotion_);
	LIST_[top++] = l;
}
bool List::IsEmpty()const
{
	return top == 0;
}
bool List::IsFull()const
{
	return top == MAX;
}
void List::VisitList(void(*pfun)(list&), list& ls)
{
	pfun(ls);
}
void List::VisitThroughList(void(*pfun)(list&))
{
	for (int i = 0; i < MAX; i++)
	{
		pfun(LIST_[i]);
	}
}
void List::DeleteList(int n)
{
	LIST_[n].fullname = " ";
	for (int i = 0; i < 5; i++)
		LIST_[n].score[i] = 0.0;
	LIST_[n].GPA = 0.0;
	top--;
}
List::~List()
{
	cout << "Bye." << endl;
}
int List::Showtop()const
{
	return top;
}
void List::Showlist()const
{
	for (int i = 0; i < MAX; i++)
	{
		cout << "Student" << i + 1 << ":" << endl;
		cout << "Name:" << LIST_[i].fullname << endl;
		cout << "Score:" << endl;
		for (int j = 0; j < 5; j++)
			cout << LIST_[i].score[j];
		cout << "GPA" << LIST_[i].GPA << endl;
	}
}
void List::GPA_sequence()const
{
	double gpas[MAX]{};
	for (int i = 0; i < MAX; i++)
		gpas[i] = LIST_[i].GPA;
	for (int i = 0; i < MAX - 1; i++)
		for (int j = i; j < MAX; j++)
		{
			if (gpas[j] > gpas[i])
			{
				double temp;
				temp = gpas[j];
				gpas[j] = gpas[i];
				gpas[i] = temp;
			}
		}
	cout << "Here is the GPA in sequence:" << endl;
	for (int i = 0; i < MAX; i++)
		cout << gpas[i] << endl;
}
//c10p8.cpp
//#include"List.h"
using namespace std;
int main()
{
	List L;
	list l;
	for (int i = 0; i < 26; i++)
	{
		cout << "Student" << L.Showtop() + 1 << ":" << endl;
		L.Add_to_list();
		cout << "Create success." << endl;
	}
	L.Showlist();
	L.GPA_sequence();
	return 0;
}
