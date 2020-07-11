//1.
//classic.h
#pragma once
#include<iostream>
class Cd {
private:
	char performers[50];
	char label[20];
	int selections;
	double playtime;
public:
	Cd(const char* sl, const char* s2, int n, double x);
	Cd(const Cd& d);
	Cd();
	virtual ~Cd();
	virtual void report()const;
	virtual Cd& operator=(const Cd& d);
};
class Classic :public Cd {
private:
	char mainwork[40];
public:
	Classic(const char* sl, const char* s2, int n, double x, const char* mw);
	Classic(const Classic& cs);
	Classic();
	~Classic();
	virtual void report()const;
	virtual Classic& operator=(const Classic& cs);
};
//classic.cpp
#include<iostream>
//#include"classic.h"
#include<cstring>
Cd::Cd(const char* sl, const char* s2, int n, double x)
{
	strcpy(performers, sl);
	strcpy(label, s2);
	selections = n;
	playtime = x;
}
Cd::Cd(const Cd& d)
{
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}
Cd::Cd()
{
	performers[0] = '\0';
	label[0] = '\0';
	selections = 0;
	playtime = 0.0;
}
Cd::~Cd()
{

}
void Cd::report()const
{
	std::cout << "Performers:" << performers << std::endl;
	std::cout << "Label:" << label << std::endl;
	std::cout << "Selections:" << selections << std::endl;
	std::cout << "Playtime:" << playtime << std::endl;
}
Cd& Cd::operator=(const Cd& d)
{
	if (this == &d)
		return *this;
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}
Classic::Classic(const char* s1, const char* s2, int n, double x, const char* mw) :Cd(s1, s2, n, x)
{
	strcpy(mainwork, mw);
}
Classic::Classic(const Classic& cs) : Cd(cs)
{
	strcpy(mainwork, cs.mainwork);
}
Classic::Classic() : Cd()
{
	mainwork[0] = '\0';
}
Classic::~Classic()
{

}
void Classic::report()const
{
	Cd::report();
	std::cout << "Main works:" << mainwork << std::endl;
}
Classic& Classic::operator=(const Classic& cs)
{
	if (this == &cs)
		return *this;
	Cd::operator=(cs);
	strcpy(mainwork, cs.mainwork);
	return *this;
}
//c13p1.cpp
#include<iostream>
using namespace std;
//#include"classic.h"
void Bravo(const Cd& disk)
{
	disk.report();
}
int main()
{
	Cd c1("Beatles", "Capital", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat,Fantasia in C",
		"Alfred Brendal", 2, 57.17, "Philips");
	Cd* pcd = &c1;
	cout << "Using object directly" << endl;
	c1.report();
	c2.report();
	cout << "Using type cd*pointer to objects:" << endl;
	pcd->report();
	pcd = &c2;
	pcd->report();
	cout << "Calling a function with a cd reference argument:" << endl;
	Bravo(c1);
	Bravo(c2);
	cout << "Testing assignment:";
	Classic copy;
	copy = c2;
	copy.report();
	return 0;
}
//2.
//classic.h
#pragma once
#include<iostream>
class Cd {
private:
	char* performers;
	char* label;
	int selections;
	double playtime;
public:
	Cd(const char* s1, const char* s2, int n, double x);
	Cd(const Cd& d);
	Cd();
	virtual ~Cd();
	virtual void report()const;
	virtual Cd& operator=(const Cd& d);
};
class Classic :public Cd {
private:
	char* mainwork;
public:
	Classic(const char* s1, const char* s2, int n, double x, const char* mw);
	Classic(const Classic& cs);
	Classic();
	~Classic();
	virtual void report()const;
	virtual Classic& operator=(const Classic& cs);
};
//classic.cpp
#include<iostream>
//#include"classic.h"
#include<cstring>
Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	performers = new char[strlen(s1) + 1];
	strcpy(performers, s1);
	label = new char[strlen(s2) + 1];
	strcpy(label, s2);
	selections = n;
	playtime = x;
}
Cd::Cd(const Cd& d)
{
	performers = new char[strlen(d.performers) + 1];
	strcpy(performers, d.performers);
	label = new char[strlen(d.label) + 1];
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}
Cd::Cd()
{
	performers = nullptr;
	label = nullptr;
	selections = 0;
	playtime = 0.0;
}
Cd::~Cd()
{
	delete[] performers;
	delete[] label;
}
void Cd::report()const
{
	std::cout << "Performers:" << performers << std::endl;
	std::cout << "Label:" << label << std::endl;
	std::cout << "Selections:" << selections << std::endl;
	std::cout << "Playtime:" << playtime << std::endl;
}
Cd& Cd::operator=(const Cd& d)
{
	if (this == &d)
		return *this;
	delete[] performers;
	delete[] label;
	performers = new char[strlen(d.performers) + 1];
	strcpy(performers, d.performers);
	label = new char[strlen(d.label) + 1];
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}
Classic::Classic(const char* s1, const char* s2, int n, double x, const char* mw) :Cd(s1, s2, n, x)
{
	mainwork = new char[strlen(mw) + 1];
	strcpy(mainwork, mw);
}
Classic::Classic(const Classic& cs) : Cd(cs)
{
	mainwork = new char[strlen(cs.mainwork) + 1];
	strcpy(mainwork, cs.mainwork);
}
Classic::Classic() : Cd()
{
	mainwork = nullptr;
}
Classic::~Classic()
{
	delete[] mainwork;
}
void Classic::report()const
{
	Cd::report();
	std::cout << "Main works:" << mainwork << std::endl;
}
Classic& Classic::operator=(const Classic& cs)
{
	if (this == &cs)
		return *this;
	Cd::operator=(cs);
	delete[] mainwork;
	mainwork = new char[strlen(cs.mainwork) + 1];
	strcpy(mainwork, cs.mainwork);
	return *this;
}
//c13p2.cpp = c13p1.cpp;
//3.
// B_L_H.h  -- inheritance and dynamic memory allocation
#pragma once
#include <iostream>
class Base {
private:
	char* label;
	int rating;
public:
	Base(const char* l = "null", int r = 0);
	Base(const Base& rs);
	virtual ~Base();
	char* reportlabel()const { return label; }
	int reportrating()const { return rating; }
	virtual void View()const;
	virtual Base& operator=(const Base& rs);
};
class baseDMA :public Base
{
public:
	baseDMA(const char* l = "null", int r = 0);
	baseDMA(const baseDMA& rs);
	virtual ~baseDMA();
	virtual void View()const;
	baseDMA& operator=(const baseDMA& rs);
	friend std::ostream& operator<<(std::ostream& os,
		const baseDMA& rs);
};
class lacksDMA :public Base
{
private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];
public:
	virtual void View()const;
	lacksDMA(const char* c = "blank", const char* l = "null",
		int r = 0);
	lacksDMA(const char* c, const baseDMA& rs);
	friend std::ostream& operator<<(std::ostream& os,
		const lacksDMA& rs);
};
class hasDMA :public Base
{
private:
	char* style;
public:
	hasDMA(const char* s = "none", const char* l = "null",
		int r = 0);
	hasDMA(const char* s, const baseDMA& rs);
	hasDMA(const hasDMA& hs);
	~hasDMA();
	virtual void View()const;
	hasDMA& operator=(const hasDMA& rs);
	friend std::ostream& operator<<(std::ostream& os,
		const hasDMA& rs);
};
// B_L_H.cpp --dma class methods
//#include "B_L_H.h"
#include <cstring>
Base::Base(const char* l, int r)
{
	label = new char[std::strlen(l) + 1];
	std::strcpy(label, l);
	rating = r;
}
Base::Base(const Base& rs)
{
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
}
Base::~Base()
{
	delete[] label;
}
Base& Base::operator=(const Base& rs)
{
	if (this == &rs)
		return *this;
	delete[] label;
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
}
baseDMA::baseDMA(const char* l, int r) :Base(l, r) {}
baseDMA::baseDMA(const baseDMA& rs) : Base(rs) {}
baseDMA::~baseDMA() {}
baseDMA& baseDMA::operator=(const baseDMA& rs)
{
	Base::operator=(rs);
	return *this;
}
std::ostream& operator<<(std::ostream& os, const baseDMA& rs)
{
	os << "Label: " << rs.reportlabel() << std::endl;
	os << "Rating: " << rs.reportrating() << std::endl;
	return os;
}
lacksDMA::lacksDMA(const char* c, const char* l, int r)
	: Base(l, r)
{
	std::strncpy(color, c, 39);
	color[39] = '\0';
}
lacksDMA::lacksDMA(const char* c, const baseDMA& rs)
	: Base(rs)
{
	std::strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}
std::ostream& operator<<(std::ostream& os, const lacksDMA& ls)
{
	os << (const baseDMA&)ls;
	os << "Color: " << ls.color << std::endl;
	return os;
}
hasDMA::hasDMA(const char* s, const char* l, int r)
	: Base(l, r)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}
hasDMA::hasDMA(const char* s, const baseDMA& rs)
	: Base(rs)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}
hasDMA::hasDMA(const hasDMA& hs)
	: Base(hs)  // invoke base class copy constructor
{
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
}
hasDMA::~hasDMA()
{
	delete[] style;
}
hasDMA& hasDMA::operator=(const hasDMA& hs)
{
	if (this == &hs)
		return *this;
	Base::operator=(hs);  // copy base portion
	delete[] style;         // prepare for new style
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
	return *this;
}
std::ostream& operator<<(std::ostream& os, const hasDMA& hs)
{
	os << (const baseDMA&)hs;
	os << "Style: " << hs.style << std::endl;
	return os;
}
void Base::View()const
{
	std::cout << "Label: " << label << std::endl;
	std::cout << "Rating: " << rating << std::endl;
}
void baseDMA::View()const
{
	std::cout << "Label: " << reportlabel() << std::endl;
	std::cout << "Rating: " << reportrating() << std::endl;
}
void lacksDMA::View()const
{
	std::cout << "Label: " << reportlabel() << std::endl;
	std::cout << "Rating: " << reportrating() << std::endl;
	std::cout << "Color:" << color << std::endl;
}
void hasDMA::View()const
{
	std::cout << *this;
	std::cout << "Style:" << style << std::endl;
}
//c13p3.cpp
#include <iostream>
//#include "B_L_H.h"
int main()
{
	using std::cout;
	using std::endl;
	using std::cin;
	Base* bas[3];
	cout << "Choose displaying mode:" << endl;
	cout << "1.baseDMA    2.lacksDMA    3.hasDMA" << endl;
	int ch;
	while (cin >> ch)
	{
		switch (ch)
		{
		case 1: {
			baseDMA shirt("Portabelly", 8);
			bas[0] = bas[1] = bas[2] = &shirt;
			bas[0]->View();
			bas[1]->View();
			bas[2]->View();
		}break;
		case 2: {
			lacksDMA balloon("red", "Blimpo", 4);
			bas[0] = bas[1] = bas[2] = &balloon;
			bas[0]->View();
			bas[1]->View();
			bas[2]->View();
		}break;
		case 3: {
			hasDMA map("Mercator", "Buffalo Keys", 5);
			bas[0] = bas[1] = bas[2] = &map;
			bas[0]->View();
			bas[1]->View();
			bas[2]->View();
		}break;
		default:break;
			cout << "Choose displaying mode:" << endl;
			cout << "1.baseDMA    2.lacksDMA    3.hasDMA" << endl;
		}
	}
	std::cout << "Bye." << endl;
	return 0;
}
//4.c.operator=()函数原型不同，尤其是原型参数不同类，而operator << ()函数是友元函数，不是类成员函数，所以不能被声明为虚函数。
//其他：
//bop.h
#pragma once
#include<iostream>
class Port {
private:
	char* brand;
	char style[20];
	int bottles;
public:
	Port(const char* br = "none", const char* st = "none", int b = 0);
	Port(const Port& p);
	virtual~Port() { delete[] brand; }
	Port& operator=(const Port& p);
	Port& operator+=(int b);//adds b to bottles
	Port& operator-=(int b);//substracts b from bottles,if available
	char* ReportBrand()const { return brand; }
	const char* ReportStyle()const { return style; }
	int BottleCount()const { return bottles; }
	virtual void Show()const;
	friend std::ostream& operator<<(std::ostream& os, const Port& p);
};
class VintagePort :public Port {
private:
	char* nickname;
	int year;
public:
	VintagePort();
	VintagePort(const char* br, int b, const char* nn, int y);
	VintagePort(const VintagePort& vp);
	~VintagePort();
	VintagePort& operator=(const VintagePort& vp);
	void Show()const;
	friend std::ostream& operator<<(std::ostream& os, const VintagePort& vp);
};
//bop.h
#include<iostream>
//#include"bop.h"
#include<cstring>
Port::Port(const char* br, const char* st, int b)
{
	brand = new char[strlen(br) + 1];
	strcpy(brand, br);
	strcpy(style, st);
	bottles = b;
}
Port::Port(const Port& p)
{
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
}
Port& Port::operator=(const Port& p)
{
	if (this == &p)
		return*this;
	delete[]brand;
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
	return *this;
}
Port& Port::operator+=(int b)
{
	bottles += b;
	return *this;
}
Port& Port::operator-=(int b)
{
	if (bottles < b)
	{
		std::cerr << "Bottles are not enough." << std::endl;
		return *this;
	}
	else
	{
		bottles -= b;
		return *this;
	}
}
void Port::Show()const
{
	std::cout << "Brand:" << brand << std::endl;
	std::cout << "Kind:" << style << std::endl;
	std::cout << "Bottles:" << bottles << std::endl;
}
std::ostream& operator<<(std::ostream& os, const Port& p)
{
	os << p.brand << "," << p.style << "," << p.bottles << std::endl;
	return os;
}
VintagePort::VintagePort() :Port("none", "vintage", 0)
{
	nickname = nullptr;
	year = 82;
}
VintagePort::VintagePort(const char* br, int b, const char* nn, int y) : Port(br, "vintage", b)
{
	nickname = new char[strlen(nn) + 1];
	strcpy(nickname, nn);
	year = y;
}
VintagePort::VintagePort(const VintagePort& vp) :Port(vp)
{
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
}
VintagePort::~VintagePort()
{
	delete[] nickname;
}
VintagePort& VintagePort::operator=(const VintagePort& vp)
{
	if (this == &vp)
		return*this;
	Port::operator=(vp);
	delete[]nickname;
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
	return *this;
}
void VintagePort::Show()const
{
	std::cout << "Brand:" << ReportBrand() << std::endl;
	std::cout << "Kind:" << ReportStyle() << std::endl;
	std::cout << "Bottles:" << BottleCount() << std::endl;
	std::cout << "Nickname:" << nickname << std::endl;
	std::cout << "Year:" << year << std::endl;
}
std::ostream& operator<<(std::ostream& os, const VintagePort& vp)
{
	os << (const Port&)vp;
	os << "," << vp.nickname << "," << vp.year << " years";
	return os;
}
