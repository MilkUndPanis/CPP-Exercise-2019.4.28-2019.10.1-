//1.
//Tv_Remote.h
#pragma once
#ifndef TV_REMOTE_H
#define TV_REMOTE_H
#include<iostream>
class Remote;
class Tv {
private:
	int state;
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;
public:
	friend class Remote;
	enum { off, on };
	enum { Minval, Maxval = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };
	Tv(int s = off, int mc = 125) :state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {};
	void onoff() { state = (state == on) ? off : on; }
	bool ison()const { return state == on; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna ? Cable : Antenna); }
	void set_input() { input = (input == TV ? DVD : TV); }
	bool set_status(Remote& r);
	void setting()const;
};
class Remote {
private:
	int mode;
	uint32_t status;
public:
	friend class Tv;
	enum { Normal, Mutual };
	Remote(int m = Tv::TV, uint32_t s = Normal) :mode(m), status(s) {};
	bool volup(Tv& t) { return t.volup(); }
	bool voldown(Tv& t) { return t.voldown(); }
	void onoff(Tv& t) { t.onoff(); }
	void chanup(Tv& t) { t.chanup(); }
	void chandown(Tv& t) { t.chandown(); }
	void set_chan(Tv& t, int c) { t.channel = c; }
	void set_mode(Tv& t) { t.set_mode(); }
	void set_input(Tv& t) { t.set_input(); }
	uint32_t showstatus() { return status; }
	bool set_status(Tv& t);
};
bool Tv::volup()
{
	if (volume < Maxval)
	{
		volume++;
		return true;
	}
	else return false;
}
bool Tv::voldown()
{
	if (volume > Minval)
	{
		volume--;
		return true;
	}
	else return false;
}
void Tv::chanup()
{
	if (channel < maxchannel)
		channel++;
	else channel = 1;
}
void Tv::chandown()
{
	if (channel > 1)
		channel++;
	else channel = maxchannel;
}
void Tv::setting()const
{
	using std::cout;
	using std::endl;
	cout << "Tv is " << (state == off ? "off" : "on") << endl;
	if (state == on)
	{
		cout << "Volume setting=" << volume << endl;
		cout << "Channel setting=" << channel << endl;
		cout << "Mode=" << (mode == Antenna ? "Antenna" : "Cable") << endl;
		cout << "Input=" << (input == TV ? "TV" : "DVD") << endl;
	}
}
bool Tv::set_status(Remote& r)
{
	if (state == off)
		return false;
	else
	{
		r.status = (r.status == r.Normal ? r.Mutual : r.Normal);
		return true;
	}
}
bool Remote::set_status(Tv& t)
{
	if (t.state == t.off)
		return false;
	else
	{
		status = (status == Normal ? Mutual : Normal);
		return true;
	}
}
#endif
//c15p1.cpp
#include<iostream>
//#include"Tv_Remote.h"
#include<ctime>
uint32_t gaussf(double f)
{
	return static_cast<uint32_t>(f);
}
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	Tv MyTele;
	Remote MyTele_s_Remote;
	MyTele_s_Remote.onoff(MyTele);
	MyTele_s_Remote.chanup(MyTele);
	cout << "The status now is " << MyTele_s_Remote.showstatus() << endl;
	MyTele_s_Remote.set_status(MyTele);
	cout << "The status now is " << MyTele_s_Remote.showstatus() << endl;
	srand(time(0));
	uint32_t t = gaussf(rand());
	for (int i = 0; i < t; i++)
		MyTele_s_Remote.set_status(MyTele);
	cout << "After " << t << " times of transitions,the status now is " << MyTele_s_Remote.showstatus() << endl;
	return 0;
}
//2.
//c15p2.cpp
#include<iostream>
#include<stdexcept>
#include<cmath>
class bad_hmean :public std::logic_error {
public:
	bad_hmean(const char* what_arg) :logic_error(what_arg) {};
};
class bad_gmean :public std::logic_error {
public:
	bad_gmean(const char* what_arg) :logic_error(what_arg) {};
};
double hmean(double a, double b)
{
	if (a == -b) throw bad_hmean("bad arguments to hmean()");
	return 2.0 * a * b / (a + b);
}
double gmean(double a, double b)
{
	if (a < 0 || b < 0) throw bad_gmean("bad arguments to gmean()");
	return sqrt(a * b);
}
int main()
{
	using std::cout;
	using std::endl;
	using std::cin;
	double x, y, z, q;
	cout << "Enter two numbers:";
	while (cin >> x >> y)
	{
		try {
			z = hmean(x, y);
			cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
			q = gmean(x, y);
			cout << "Geometric mean of " << x << " and " << y << " is " << q << endl;
			cout << "Enter next set of numbers<q to quit>:";
		}
		catch (bad_hmean& bg)
		{
			cout << bg.what() << endl;
			cout << "Enter next set of numbers<q to quit>:";
			continue;
		}
		catch (bad_gmean& bg)
		{
			cout << bg.what() << endl;
			cout << "Enter next set of numbers<q to quit>:";
			continue;
		}
	}
	cout << "Bye!" << endl;
	return 0;
}
//3.
//c15p3.cpp
#include<iostream>
#include<stdexcept>
#include<cmath>
class father_of_bad_means :public std::logic_error {
private:
	double u;
	double v;
public:
	father_of_bad_means(double m_u, double m_v, const char* what_arg) :u(m_u), v(m_v), logic_error(what_arg) {};
	double reportu() { return u; }
	double reportv() { return v; }
	virtual void report() = 0;
};
class bad_hmean :public father_of_bad_means {
public:
	bad_hmean(double m_u, double m_v, const char* what_arg) :father_of_bad_means(m_u, m_v, what_arg) {};
	virtual void report() {
		std::cout << "Argument :" << reportu() << " and " << reportv() << std::endl;
		std::cout << "Function name:hmean()" << std::endl;
	}
};
class bad_gmean :public father_of_bad_means {
public:
	bad_gmean(double m_u, double m_v, const char* what_arg) :father_of_bad_means(m_u, m_v, what_arg) {};
	virtual void report() {
		std::cout << "Argument :" << reportu() << " and " << reportv() << std::endl;
		std::cout << "Function name:gmean()" << std::endl;
	}
};
double hmean(double a, double b)
{
	if (a == -b) throw bad_hmean(a, b, "bad arguments to hmean()");
	return 2.0 * a * b / (a + b);
}
double gmean(double a, double b)
{
	if (a < 0 || b < 0) throw bad_gmean(a, b, "bad arguments to gmean()");
	return sqrt(a * b);
}
int main()
{
	using std::cout;
	using std::endl;
	using std::cin;
	double x, y, z, q;
	cout << "Enter two numbers:";
	while (cin >> x >> y)
	{
		try {
			z = hmean(x, y);
			cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
			q = gmean(x, y);
			cout << "Geometric mean of " << x << " and " << y << " is " << q << endl;
			cout << "Enter next set of numbers<q to quit>:";
		}
		catch (father_of_bad_means& fg)
		{
			fg.report();
			cout << fg.what() << endl;
			break;
		}
	}
	cout << "Bye!" << endl;
	return 0;
}
//4.（其他两个文件不变）
// c15p4.cpp -- nested exceptions
#include <iostream>
#include <typeinfo>
//#include "Sales.h"
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	double vals1[12] = {
		1220, 1100, 1122, 2212, 1232, 2334,
		2884, 2393, 3302, 2922, 3002, 3544 };
	double vals2[12] = {
		12, 11, 22, 21, 32, 34,
		28, 29, 33, 29, 32, 35
	};
	Sales sales1(2011, vals1, 12);
	LabeledSales sales2("Blogstar", 2012, vals2, 12);
	cout << "First try block:\n";
	try
	{
		int i;
		cout << "Year = " << sales1.Year() << endl;
		for (i = 0; i < 12; ++i)
		{

			cout << sales1[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "Year = " << sales2.Year() << endl;
		cout << "Label = " << sales2.Label() << endl;
		for (i = 0; i <= 12; ++i)
		{

			cout << sales2[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "End of try block 1.\n";
	}
	catch (std::logic_error& bad)//第一代基类logic_error对象的引用可以指向nbad_index
								 //与bad_index对象，用它作为捕获块的参数
	{
		if (typeid(bad) == typeid(LabeledSales::nbad_index))//如果该引用指向的对象确实是nbad_index类
		{
			cout << bad.what();
			cout << "Company: " << dynamic_cast<LabeledSales::nbad_index&>(bad).label_val() << endl;
			//通过dynamic_cast<Type&/Type*>(ps/*ps)将指向派生类或基类对象的引用或指针
			//转换为基类引用或指针（向上转换或同级转换），这里使用同级转换（即以nbad_index为“基类”），下同
			cout << "bad index: " << dynamic_cast<LabeledSales::nbad_index&>(bad).bi_val() << endl;
		}
		else if (typeid(bad) == typeid(Sales::bad_index))//如果该引用指向的对象确实是bad_index类
		{
			cout << bad.what();
			cout << "bad index: " << dynamic_cast<Sales::bad_index&>(bad).bi_val() << endl;
			//也是同级转换（即以bad_index为“基类”）
		}
	}
	//下一块catch工作原理与以上完全一致
	cout << "\nNext try block:\n";
	try
	{
		sales2[2] = 37.5;
		sales1[20] = 23345;
		cout << "End of try block 2.\n";
	}
	catch (std::logic_error& bad)
	{
		if (typeid(bad) == typeid(LabeledSales::nbad_index))
		{
			cout << bad.what();
			cout << "Company: " << dynamic_cast<LabeledSales::nbad_index&>(bad).label_val() << endl;
			cout << "bad index: " << dynamic_cast<LabeledSales::nbad_index&>(bad).bi_val() << endl;
		}
		else if (typeid(bad) == typeid(Sales::bad_index))
		{
			cout << bad.what();
			cout << "bad index: " << dynamic_cast<Sales::bad_index&>(bad).bi_val() << endl;
		}
	}
	cout << "done\n";
	return 0;
}
