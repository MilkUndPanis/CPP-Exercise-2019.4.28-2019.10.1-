//1. 
//wine.h
#pragma once
#include<iostream>
#include<valarray>
using namespace std;
template<class T1, class T2>
class Pair {
private:
	T1 a;
	T2 b;
public:
	T1& first();
	T2& second();
	T1 first()const { return a; }
	T2 second()const { return b; }
	Pair(const T1& aval, const T2& bval) :a(aval), b(bval) {}
	Pair() {}
};
template<class T1, class T2>
T1& Pair<T1, T2>::first()
{
	return a;
}
template<class T1, class T2>
T2& Pair<T1, T2>::second()
{
	return b;
}
typedef valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt>PairArray;
class Wine {
private:
	string lname;
	PairArray year_and_bottles;
	int yn;
public:
	Wine(const char* l = "Null", const int yr[] = {}, const int bot[] = {}, int y = 0);
	Wine(const char* l, int y);
	~Wine() {}
	void Getbottles();
	void Show()const;
	const string& Label()const { return lname; }
	int Sum()const;
};
//wine.cpp
#include<iostream>
//#include"Wine.h"
using namespace std;
Wine::Wine(const char* l, const int yr[], const int bot[], int y)
	:lname(l), yn(y)
{
	year_and_bottles = PairArray(ArrayInt(y), ArrayInt(y));
	for (int i = 0; i < y; i++)
	{
		year_and_bottles.first()[i] = yr[i];
		year_and_bottles.second()[i] = bot[i];
	}
}
Wine::Wine(const char* l, int y) :lname(l), yn(y)
{
	year_and_bottles = PairArray(ArrayInt(y), ArrayInt(y));
}
void Wine::Getbottles()
{
	cout << "Enter " << lname << " data for " << yn << " years:" << endl;
	for (int i = 0; i < yn; i++)
	{
		cout << "Enter year:";
		int y;
		while (!(cin >> y))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cerr << "Error__Try again:";
		}
		year_and_bottles.first()[i] = y;
		cout << "Enter bottles for that year:";
		int bt;
		while (!(cin >> bt))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cerr << "Error__Try again:";
		}
		year_and_bottles.second()[i] = bt;
	}
}
void Wine::Show()const
{
	cout << "Wine:" << lname << endl;
	cout << "Year    Bottles" << endl;
	for (int i = 0; i < yn; i++)
	{
		cout << year_and_bottles.first()[i] << "    " << year_and_bottles.second()[i] << endl;
	}
}
int Wine::Sum()const
{
	int sum = 0;
	for (int i = 0; i < yn; i++)
	{
		sum += year_and_bottles.second()[i];
	}
	return sum;
}
//c114.p1
#include<iostream>
//#include"Wine.h"
using namespace std;
int main()
{
	cout << "Enter name of wine:";
	char lab[50];
	cin.getline(lab, 50);
	cout << "Enter the number of years:";
	int yrs;
	while (!(cin >> yrs))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cerr << "Invalid input,please try again:";
	}
	Wine holding(lab, yrs);
	holding.Getbottles();
	holding.Show();
	const int YRS = 3;
	int y[YRS] = { 1993,1995,1998 };
	int b[YRS] = { 48,60,72 };
	Wine more("Gushing Grape Red", y, b, YRS);
	more.Show();
	cout << "Total bottles for " << more.Label() << ":" << more.Sum() << endl;
	cout << "Bye." << endl;
	return 0;
}
//2. 
//wine.h
#pragma once
#include<iostream>
#include<valarray>
using namespace std;
template<class T1, class T2>
class Pair {
private:
	T1 a;
	T2 b;
public:
	T1& first();
	T2& second();
	T1 first()const { return a; }
	T2 second()const { return b; }
	Pair(const T1& aval, const T2& bval) :a(aval), b(bval) {}
	Pair() {}
};
template<class T1, class T2>
T1& Pair<T1, T2>::first()
{
	return a;
}
template<class T1, class T2>
T2& Pair<T1, T2>::second()
{
	return b;
}
typedef valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt>PairArray;
class Wine :private PairArray {
private:
	string lname;
	int yn;
public:
	Wine(const char* l = "Null", const int yr[] = {}, const int bot[] = {}, int y = 0);
	Wine(const char* l, int y);
	~Wine() {}
	void Getbottles();
	void Show()const;
	const string& Label()const { return lname; }
	int Sum()const;
};
//wine.cpp
#include<iostream>
//#include"Wine.h"
using namespace std;
Wine::Wine(const char* l, const int yr[], const int bot[], int y)
	:lname(l), yn(y), PairArray(ArrayInt(y), ArrayInt(y))
{
	for (int i = 0; i < y; i++)
	{
		PairArray::first()[i] = yr[i];
		PairArray::second()[i] = bot[i];
	}
}
Wine::Wine(const char* l, int y) :lname(l), yn(y), PairArray(ArrayInt(y), ArrayInt(y)) {}
void Wine::Getbottles()
{
	cout << "Enter " << lname << " data for " << yn << " years:" << endl;
	for (int i = 0; i < yn; i++)
	{
		cout << "Enter year:";
		int y;
		while (!(cin >> y))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cerr << "Error__Try again:";
		}
		PairArray::first()[i] = y;
		cout << "Enter bottles for that year:";
		int bt;
		while (!(cin >> bt))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cerr << "Error__Try again:";
		}
		PairArray::second()[i] = bt;
	}
}
void Wine::Show()const
{
	cout << "Wine:" << lname << endl;
	cout << "Year    Bottles" << endl;
	for (int i = 0; i < yn; i++)
	{
		cout << PairArray::first()[i] << "    " << PairArray::second()[i] << endl;
	}
}
int Wine::Sum()const
{
	int sum = 0;
	for (int i = 0; i < yn; i++)
	{
		sum += PairArray::second()[i];
	}
	return sum;
}
//c14p2.cpp=c14p1.cpp;
//3.
//QueueTp.h
#pragma once
#include<cstring>
using namespace std;
template<class T>
class Queue {
private:
	struct Node {
		T item;
		Node* next;
	};
	static const int MAXSIZE = 10;
	Node* front;
	Node* rear;
	int items;
	const int qsize;
	Queue(const Queue& q) :qsize(0) {}
	Queue* operator=(const Queue& q) { return *this; }
public:
	Queue(int qs = MAXSIZE);
	~Queue();
	bool isempty()const { return items == 0; }
	bool isfull()const { return items == qsize; }
	int queuecount()const { return items; }
	bool enqueue(const T& t);
	bool dequeue(T& t);
};
template<class T>
Queue<T>::Queue(int qs) :qsize(qs)
{
	front = rear = nullptr;
	items = 0;
}
template<class T>
Queue<T>::~Queue()
{
	Node* temp;
	while (front != nullptr)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}
template<class T>
bool Queue<T>::enqueue(const T& t)
{
	if (isfull())
		return false;
	Node* add = new Node;
	add->item = t;
	add->next = nullptr;
	items++;
	if (front == nullptr)
		front = add;
	else
		rear->next = add;
	return true;
}
template<class T>
bool Queue<T>::dequeue(T& t)
{
	if (front == nullptr)
		return false;
	t = front->item;
	items--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = nullptr;
	return true;
}
//Worker.h
#pragma once
#include<iostream>
using namespace std;
class Worker
{
private:
	string fullname;
	long id;
public:
	Worker() :fullname("no one"), id(0L) {}
	Worker(const string& s, long n)
		: fullname(s), id(n) {}
	~Worker(); // pure virtual function
	void Show() const;
	void Set();
};
// workermi.cpp -- working class methods with MI
#include <iostream>
#include<string>
//#include"Worker.h"
using namespace std;
Worker::~Worker() { }
void Worker::Show() const
{
	cout << "Name: " << fullname << endl;
	cout << "Employee ID: " << id << endl;
}
void Worker::Set()
{
	getline(cin, fullname);
	cout << "Enter worker's ID: ";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}
//c14p3.cpp
#include<iostream>
#include<cstring>
//#include"QueueTp.h"
//#include"Worker.h"
using namespace std;
int main()
{
	Queue<Worker>* Qworker = new Queue<Worker>(20);
	Worker w1("A", 0);
	Worker w2("B", 1);
	if (Qworker->isempty())
	{
		cout << "Qworker is empty!\n";
	}
	Qworker->enqueue(w1);
	Qworker->enqueue(w2);
	cout << "Qworker count: " << Qworker->queuecount() << endl;
	Worker w3("hello", 2);
	Qworker->enqueue(w3);
	Qworker->enqueue(w2);
	cout << "Qworker count: " << Qworker->queuecount() << endl;
	Worker temp;
	Qworker->dequeue(temp);
	cout << "Dequeue: " << endl;
	temp.Show();
	Qworker->dequeue(temp);
	cout << "Dequeue: " << endl;
	temp.Show();
	cout << "Qworker count: " << Qworker->queuecount() << endl;
}
//4.
//Person.h
#pragma once
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
class Person {
private:
	string gname;
	string fname;
public:
	Person(const char* gn = " ", const char* fn = " ");
	Person(const Person& p);
	virtual ~Person() {}
	virtual void Show()const;
};
class Gunslinger :public virtual Person {
private:
	int notch;
	double ntime;
public:
	Gunslinger(const char* gn = " ", const char* fn = " ", int n = 0, double nt = 10);
	Gunslinger(const Gunslinger& g);
	virtual ~Gunslinger() {};
	virtual void Show()const;
	double Draw()const { return ntime; }
};
class PokerPlayer :public virtual Person {
public:
	PokerPlayer(const char* gn = " ", const char* fn = " ");
	PokerPlayer(const PokerPlayer& p);
	virtual ~PokerPlayer() {}
	int Draw()const
	{
		srand(time(0));
		return static_cast<int>(52 * (rand()) / RAND_MAX);
	}
	//using the Show() function of Person
};
class BadDude :public PokerPlayer, public Gunslinger {
public:
	BadDude(const char* gn = " ", const char* fn = " ", int n = 0, double nt = 10);
	BadDude(const BadDude& p);
	virtual ~BadDude() {}
	double Gdraw()const;
	int Cdraw()const;
	virtual void Show()const;
};
//Person.cpp
#include<iostream>
//#include"Person.h"
using namespace std;
Person::Person(const char* gn, const char* fn) :gname(gn), fname(fn) {}
Person::Person(const Person& p) : gname(p.gname), fname(p.fname) {}
void Person::Show()const
{
	cout << "Given name:" << gname << endl;
	cout << "Family name:" << fname << endl;
}
Gunslinger::Gunslinger(const char* gn, const char* fn, int n, double nt)
	:Person(gn, fn), notch(n), ntime(nt) {}
Gunslinger::Gunslinger(const Gunslinger& g) : Person(g), notch(g.notch), ntime(g.ntime) {}
void Gunslinger::Show()const
{
	Person::Show();
	cout << "Number Of Notch In the Gun:" << notch << endl;
	cout << "Drawing time:" << ntime << endl;
}
PokerPlayer::PokerPlayer(const char* gn, const char* fn) :Person(gn, fn) {}
PokerPlayer::PokerPlayer(const PokerPlayer& p) : Person(p) {}
BadDude::BadDude(const char* gn, const char* fn, int n, double nt)
	: Gunslinger(gn, fn, n, nt), Person(gn, fn) {}
BadDude::BadDude(const BadDude& p) : Gunslinger(p) {}
int BadDude::Cdraw()const
{
	return PokerPlayer::Draw();
}
double BadDude::Gdraw()const
{
	return Gunslinger::Draw();
}
void BadDude::Show()const
{
	Gunslinger::Show();
}
//c14p4.cpp_test
#include<iostream>
//#include"Person.h"
using namespace std;
int main()
{
	Gunslinger g_o("Abbey", "Masculine", 14, 0.6);
	PokerPlayer p_o("Pool", "Addison");
	g_o.Draw();
	p_o.Draw();
	g_o.Show();
	p_o.Show();
	BadDude b_o("Abbey", "Addison", 3718, 0.6);
	b_o.Cdraw();
	b_o.Gdraw();
	b_o.Show();
	return 0;
}
//5.
//emp.h
#pragma once
#include<iostream>
#include<string>
using namespace std;
class abstr_emp {
private:
	string fname;
	string lname;
	string job;
public:
	abstr_emp();
	abstr_emp(const char* fn, const char* ln, const char* j);
	abstr_emp(const abstr_emp& e);
	virtual void ShowAll()const;
	virtual void SetAll();
	friend ostream& operator<<(ostream& os, const abstr_emp& e);
	virtual ~abstr_emp() {};//经过验证这里不能是纯虚函数
};
class employee :public abstr_emp {
public:
	employee();
	employee(const char* fn, const char* ln, const char* j);
	employee(const employee& e);
	~employee() {}
	virtual void ShowAll()const;
	virtual void SetAll();
};
class manager :virtual public abstr_emp {
private:
	int inchargeof;
protected:
	int InChargeOf()const { return inchargeof; }
	int& InChargeOf() { return inchargeof; }
public:
	manager();
	manager(const char* fn, const char* ln, const char* j, int ico = 0);
	manager(const abstr_emp& e, int ico);
	manager(const manager& m);
	virtual ~manager() {}
	virtual void ShowAll()const;
	virtual void SetAll();
};
class fink :virtual public abstr_emp {
private:
	string reportsto;
protected:
	const string ReportsTo()const { return reportsto; }
	string& ReportsTo() { return reportsto; }
public:
	fink();
	fink(const char* fn, const char* ln, const char* j, const char* rpo);
	fink(const abstr_emp& e, const char* rpo);
	fink(const fink& e);
	virtual ~fink() {}
	virtual void ShowAll()const;
	virtual void SetAll();
};
class highfink :public manager, public fink {
public:
	highfink();
	highfink(const char* fn, const char* ln, const char* j, const char* rpo, int ico);
	highfink(const abstr_emp& e, const char* rpo, int ico);
	highfink(const fink& f, int ico);
	highfink(const manager& m, const char* rpo);
	highfink(const highfink& h);
	virtual void ShowAll()const;
	virtual void SetAll();
};
//emp.cpp
#include<iostream>
//#include"emp.h"
using namespace std;
abstr_emp::abstr_emp()
{
	fname = "null";
	lname = "null";
	job = "seeking......";
}
abstr_emp::abstr_emp(const char* fn, const char* ln, const char* j)
	:fname(fn), lname(ln), job(j) {}
abstr_emp::abstr_emp(const abstr_emp& e) : fname(e.fname), lname(e.lname), job(e.job) {}
void abstr_emp::ShowAll()const
{
	cout << "First name:" << fname << endl;
	cout << "Last name:" << lname << endl;
	cout << "Job:" << job << endl;
}
void abstr_emp::SetAll()
{
	cout << "Enter first name:";
	getline(cin, fname);
	cout << "Enter last name:";
	getline(cin, lname);
	cout << "Enter the job:";
	getline(cin, job);
}
ostream& operator<<(ostream& os, const abstr_emp& e)
{
	os << e.fname << " " << e.lname << " " << e.job << endl;
	return os;
}
employee::employee() :abstr_emp() {}
employee::employee(const char* fn, const char* ln, const char* j) : abstr_emp(fn, ln, j) {}
employee::employee(const employee& e) : abstr_emp(e) {}
void employee::ShowAll()const
{
	abstr_emp::ShowAll();
}
void employee::SetAll()
{
	abstr_emp::SetAll();
}
manager::manager() :abstr_emp(), inchargeof(0) {}
manager::manager(const char* fn, const char* ln, const char* j, int ico) : abstr_emp(fn, ln, j), inchargeof(ico) {}
manager::manager(const abstr_emp& e, int ico) : abstr_emp(e), inchargeof(ico) {}
manager::manager(const manager& m) : abstr_emp(m), inchargeof(m.inchargeof) {}
void manager::ShowAll()const
{
	abstr_emp::ShowAll();
	cout << "InChargeOf:" << InChargeOf() << endl;
}
void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "Inchargeof:";
	while (!(cin >> inchargeof))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cerr << "Invalid.Please try again:";
	}
}
fink::fink() :abstr_emp(), reportsto("Nothing......") {}
fink::fink(const char* fn, const char* ln, const char* j, const char* rpo)
	: abstr_emp(fn, ln, j), reportsto(rpo) {}
fink::fink(const abstr_emp& e, const char* rpo) : abstr_emp(e), reportsto(rpo) {}
fink::fink(const fink& e) : abstr_emp(e), reportsto(e.reportsto) {}
void fink::ShowAll()const
{
	abstr_emp::ShowAll();
	cout << "Reports to:" << ReportsTo() << endl;
}
void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Reports to:";
	getline(cin, reportsto);
}
highfink::highfink() :manager(), fink(), abstr_emp() {}
highfink::highfink(const char* fn, const char* ln, const char* j, const char* rpo, int ico)
	: manager(fn, ln, j, ico), fink(fn, ln, j, rpo), abstr_emp(fn, ln, j) {}
highfink::highfink(const abstr_emp& e, const char* rpo, int ico)
	: manager(e, ico), fink(e, rpo), abstr_emp(e) {}
highfink::highfink(const fink& f, int ico) : fink(f), manager(f, ico), abstr_emp(f) {}
highfink::highfink(const manager& m, const char* rpo) : manager(m), fink(m, rpo), abstr_emp(m) {}
highfink::highfink(const highfink& h) : manager(h), fink(h), abstr_emp(h) {}
void highfink::ShowAll()const
{
	abstr_emp::ShowAll();
	cout << "InChargeOf:" << InChargeOf() << endl;
	cout << "Reports to:" << ReportsTo() << endl;
}
void highfink::SetAll()
{
	abstr_emp::SetAll();
	int ico;
	cout << "Inchargeof:";
	while (!(cin >> ico))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cerr << "Invalid.Please try again:";
	}
	manager::InChargeOf() = ico;
	cout << "Reports to:";
	string rpt;
	getline(cin, rpt);
	ReportsTo() = rpt;
}
//pe14-5.cpp
#include<iostream>
using namespace std;
//#include"emp.h"
int main()
{
	employee em("Trip", "Harris", "Thumper");
	cout << em << endl;
	em.ShowAll();
	manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	cout << ma << endl;
	ma.ShowAll();
	fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
	cout << fi << endl;
	fi.ShowAll();
	highfink hf(ma, "Curly Kew");
	hf.ShowAll();
	cout << "Press a key for next phase:" << endl;
	cin.get();
	highfink hf2;
	hf2.SetAll();
	cout << "Using an abstr_emp * pointer:" << endl;
	abstr_emp* tri[4] = { &em,&fi,&hf,&hf2 };
	for (int i = 0; i < 4; i++)
		tri[i]->ShowAll();
	return 0;
}
