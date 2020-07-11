//Chapter 18 P838
//1.
#include<iostream>
#include<initializer_list>
template<typename T>
T average_list(std::initializer_list<T>il)
{
	T sum = 0;
	T item = 0;
	for (std::initializer_list<T>::iterator p = il.begin(); p != il.end(); p++)
	{
		sum += *p;
		item++;
	}
	return sum / item;
}
int main()
{
	using namespace std;
	auto q = average_list({ 15.4,10.7,9.0 });
	cout << q << endl;
	cout << average_list({ 20,30,19,17,45,38 }) << endl;
	auto ad = average_list<double>({ 'A',70,65.33 });
	cout << ad << endl;
	return 0;
}
//2.
//Cpmv.h
#pragma once
#include<iostream>
class Cpmv {
public:
	struct Info {
		std::string qcode;
		std::string zcode;
	};
private:
	Info* pi;
public:
	Cpmv();
	Cpmv(std::string q, std::string z);
	Cpmv(const Cpmv& cp);
	Cpmv(Cpmv&& mv);
	~Cpmv();
	Cpmv& operator=(const Cpmv& cp);
	Cpmv& operator=(Cpmv&& mv);
	Cpmv operator+(const Cpmv& obj)const;
	void Display()const;
	void D()const;
};
//Cpmv.cpp
#include<iostream>
//#include "Cpmv.h"
#include<string>
using namespace std;
Cpmv::Cpmv()
{
	pi = new Info;
	pi->qcode = "NULL";
	pi->zcode = "NULL";
	cout << "Default constructor called." << endl;
}
Cpmv::Cpmv(std::string q, std::string z)
{
	pi = new Info;
	pi->qcode = q;
	pi->zcode = z;
	cout << "String constructor called." << endl;
}
Cpmv::Cpmv(const Cpmv& cp)
{
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	cout << "Copy constructor called." << endl;
}
Cpmv::Cpmv(Cpmv&& mv)
{
	pi = new Info;
	pi->qcode = mv.pi->qcode;
	pi->zcode = mv.pi->zcode;
	mv.pi->qcode = "NULL";
	mv.pi->zcode = "NULL";
	cout << "Move constructor called." << endl;
}
Cpmv::~Cpmv()
{
	delete pi;
	cout << "Destructor called." << endl;
}
Cpmv& Cpmv::operator=(const Cpmv& cp)
{
	if (this == &cp)
		return *this;
	delete pi;
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	cout << "Copy assignment operator called." << endl;
	return *this;
}
Cpmv& Cpmv::operator=(Cpmv&& mv)
{
	if (this == &mv)
		return *this;
	delete pi;
	pi = new Info;
	pi->qcode = mv.pi->qcode;
	pi->zcode = mv.pi->zcode;
	mv.pi->qcode = "NULL";
	mv.pi->zcode = "NULL";
	cout << "Move assignment operator called." << endl;
	return *this;
}
Cpmv Cpmv::operator+(const Cpmv& obj)const
{
	Cpmv temp;//Already called Cpmv::Cpmv();
	temp.pi->qcode = pi->qcode + obj.pi->qcode;
	temp.pi->zcode = pi->zcode + obj.pi->zcode;
	cout << "Plus operator called." << endl;
	return temp;
}
void Cpmv::Display()const
{
	cout << pi->qcode << " " << pi->zcode << endl;
	cout << "Display() called." << endl;
}
void Cpmv::D()const
{
	cout << pi << endl;
}
#include<iostream>
#include<string>
//#include"Cpmv.h"
using namespace std;
int main()
{
	Cpmv obj0;
	Cpmv obj1("ABC", "DEF");
	Cpmv obj2(obj0);
	Cpmv obj3(obj1 + obj2);
	obj0.Display();
	obj1.Display();
	obj2.Display();
	obj3.Display();
	Cpmv obj4 = obj3;
	Cpmv obj5 = obj3 + obj4;
	obj4.Display();
	obj5.Display();
	obj0.D();
	obj1.D();
	obj2.D();
	obj3.D();
	obj4.D();
	obj5.D();
	return 0;
}
//3.
#include<iostream>
long double sum_value() { return 0; }//空的情形
template<typename T>
long double sum_value(const T& value)
{
	return value;//参数包只剩一个元素的情形
}
template<typename T, typename ...Args>
long double sum_value(const T& value, const Args& ...args)
{
	return value + sum_value(args...);
}
int main()
{
	long double s = sum_value(1.7, 2.2, 5.0);
	std::cout << s << std::endl;
	return 0;
}
//4.
// functor.cpp -- using a functor
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
template<class T>  // functor class defines operator()()
class TooBig
{
private:
	T cutoff;
public:
	TooBig(const T& t) : cutoff(t) {}
	bool operator()(const T& v) { return v > cutoff; }
};
auto outint = [](int n)->void {std::cout << n << " "; };
int main()
{
	using namespace std;
	TooBig<int> f100(100); // limit = 100
	int vals[10] = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };
	list<int> yadayada(vals, vals + 10); // range constructor
	list<int> etcetera(vals, vals + 10);
	cout << "Original lists:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	yadayada.remove_if(f100);               // use a named function object
	etcetera.remove_if(TooBig<int>(200));   // construct a function object
	cout << "Trimmed lists:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	return 0;
}
