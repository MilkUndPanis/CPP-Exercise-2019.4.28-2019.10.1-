//1
//vector.h
#pragma once
#include<iostream>
namespace VECTOR {
	class Vector {
	public:
		enum Mode { RECT, POL };
	private:
		double x;
		double y;
		double mag;
		double ang;
		Mode mode;
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		double xval()const { return x; }
		double yval()const { return y; }
		double magval()const { return mag; }
		double angval()const { return ang; }
		void polar_mode();
		void rect_mode();
		Vector operator+(const Vector& b)const;
		Vector operator-(const Vector& b)const;
		Vector operator-()const;
		Vector operator*(double n)const;
		friend Vector operator*(double n, const Vector& a);
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);
	};
}
// vector.cpp
#include <cmath>
//#include "vector.h"
using namespace std;
namespace VECTOR
{
	const double Rad_to_deg = 45.0 / atan(1.0);
	void Vector::set_mag()
	{
		mag = sqrt(x * x + y * y);
	}
	void Vector::set_ang()
	{
		if (x == 0.0 && y == 0.0)
			ang = 0.0;
		else
			ang = atan2(y, x);
	}
	void Vector::set_x()
	{
		x = mag * cos(ang);
	}
	void Vector::set_y()
	{
		y = mag * sin(ang);
	}
	Vector::Vector()
	{
		x = y = mag = ang = 0.0;
		mode = RECT;
	}
	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}
	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}
	Vector::~Vector()    // destructor
	{
	}
	void Vector::polar_mode()    // set to polar mode
	{
		mode = POL;
	}
	void Vector::rect_mode()     // set to rectangular mode
	{
		mode = RECT;
	}
	Vector Vector::operator+(const Vector& b) const
	{
		return Vector(x + b.x, y + b.y);
	}
	Vector Vector::operator-(const Vector& b) const
	{
		return Vector(x - b.x, y - b.y);
	}
	Vector Vector::operator-() const
	{
		return Vector(-x, -y);
	}
	Vector Vector::operator*(double n) const
	{
		return Vector(n * x, n * y);
	}
	Vector operator*(double n, const Vector& a)
	{
		return a * n;
	}
	std::ostream& operator<<(std::ostream& os, const Vector& v)
	{
		if (v.mode == Vector::RECT)
			os << "(x,y) = (" << v.x << ", " << v.y << ")";
		else if (v.mode == Vector::POL)
		{
			os << "(m,a) = (" << v.mag << ", "
				<< v.ang * Rad_to_deg << ")";
		}
		else
			os << "Vector object mode is invalid";
		return os;
	}
}
//c11p1.cpp
#include <iostream>
#include <fstream>
#include <cstdlib>      
#include <ctime>        
//#include "vector.h"
int main()
{
	using namespace std;
	using namespace VECTOR;
	ofstream OF;
	OF.open("random.txt");
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		OF << "Target Distance:" << target << ",Step Size:" << dstep << endl;
		while (result.magval() < target)
		{
			OF << result << endl;
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		OF << "After " << steps << " steps, the subject "
			"has the following location:\n";
		OF << result << endl;
		result.polar_mode();
		OF << " or\n" << result << endl;
		OF << "Average outward distance per step = "
			<< result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	OF.close();
	cout << "Bye!\n";
	return 0;
}
//2.
//理解为需要手动调用xval（）等函数
//vector.h
#pragma once
#include<iostream>
namespace VECTOR {
	class Vector {
	public:
		enum Mode { RECT, POL };
	private:
		double x;
		double y;
		double mag;
		double ang;
		Mode mode;
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		double xval() { set_x(); return x; }
		double yval() { set_y(); return y; }
		double magval() { set_mag(); return mag; }
		double angval() { set_ang(); return ang; }
		void polar_mode();
		void rect_mode();
		Vector operator+(const Vector& b)const;
		Vector operator-(const Vector& b)const;
		Vector operator-()const;
		Vector operator*(double n)const;
		friend Vector operator*(double n, const Vector& a);
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);
	};
}
// vector.cpp
#include <cmath>
//#include "vector.h"
using namespace std;
namespace VECTOR
{
	const double Rad_to_deg = 45.0 / atan(1.0);
	void Vector::set_mag()
	{
		mag = sqrt(x * x + y * y);
	}
	void Vector::set_ang()
	{
		if (x == 0.0 && y == 0.0)
			ang = 0.0;
		else
			ang = atan2(y, x);
	}
	void Vector::set_x()
	{
		x = mag * cos(ang);
	}
	void Vector::set_y()
	{
		y = mag * sin(ang);
	}
	Vector::Vector()
	{
		x = y = mag = ang = 0.0;
		mode = RECT;
	}
	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}
	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}
	Vector::~Vector()    // destructor
	{
	}
	void Vector::polar_mode()    // set to polar mode
	{
		mode = POL;
	}
	void Vector::rect_mode()     // set to rectangular mode
	{
		mode = RECT;
	}
	Vector Vector::operator+(const Vector& b) const
	{
		return Vector(x + b.x, y + b.y);
	}
	Vector Vector::operator-(const Vector& b) const
	{
		return Vector(x - b.x, y - b.y);
	}
	Vector Vector::operator-() const
	{
		return Vector(-x, -y);
	}
	Vector Vector::operator*(double n) const
	{
		return Vector(n * x, n * y);
	}
	Vector operator*(double n, const Vector& a)
	{
		return a * n;
	}
	std::ostream& operator<<(std::ostream& os, const Vector& v)
	{
		if (v.mode == Vector::RECT)
			os << "(x,y) = (" << v.x << ", " << v.y << ")";
		else if (v.mode == Vector::POL)
		{
			os << "(m,a) = (" << v.mag << ", "
				<< v.ang * Rad_to_deg << ")";
		}
		else
			os << "Vector object mode is invalid";
		return os;
	}
}
//c11p2.cpp
#include <iostream>
#include <cstdlib>      
#include <ctime>        
//#include "vector.h"
int main()
{
	using namespace std;
	using namespace VECTOR;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		cout << "Target Distance:" << target << ",Step Size:" << dstep << endl;
		while (result.magval() < target)
		{
			cout << result << endl;
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			step.xval();
			step.yval();
			result = result + step;
			steps++;
		}
		cout << "After " << steps << " steps, the subject "
			"has the following location:\n";
		cout << result << endl;
		result.polar_mode();
		cout << " or" << endl;
		result.magval();
		result.angval();
		cout << result << endl;
		cout << "Average outward distance per step = "
			<< result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";
	return 0;
}
//3.
#pragma once
// vect.h -- Vector class with <<, mode state
#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
namespace VECTOR
{
	class Vector
	{
	public:
		enum Mode { RECT, POL };
		// RECT for rectangular, POL for Polar modes
	private:
		double x;          // horizontal value
		double y;          // vertical value
		double mag;        // length of vector
		double ang;        // direction of vector in degrees
		Mode mode;         // RECT or POL
	// private methods for setting values
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		double xval() const { return x; }       // report x value
		double yval() const { return y; }       // report y value
		double magval() const { return mag; }   // report magnitude
		double angval() const { return ang; }   // report angle
		void polar_mode();                    // set mode to POL
		void rect_mode();                     // set mode to RECT
	// operator overloading
		Vector operator+(const Vector& b) const;
		Vector operator-(const Vector& b) const;
		Vector operator-() const;
		Vector operator*(double n) const;
		// friends
		friend Vector operator*(double n, const Vector& a);
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);
	};

}   // end namespace VECTOR
#endif
// vect.cpp -- methods for the Vector class
#include <cmath>
//#include "vect.h"   // includes <iostream>
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
	// compute degrees in one radian
	const double Rad_to_deg = 45.0 / atan(1.0);
	// should be about 57.2957795130823

	// private methods
	// calculates magnitude from x and y
	void Vector::set_mag()
	{
		mag = sqrt(x * x + y * y);
	}

	void Vector::set_ang()
	{
		if (x == 0.0 && y == 0.0)
			ang = 0.0;
		else
			ang = atan2(y, x);
	}

	// set x from polar coordinate
	void Vector::set_x()
	{
		x = mag * cos(ang);
	}

	// set y from polar coordinate
	void Vector::set_y()
	{
		y = mag * sin(ang);
	}

	// public methods
	Vector::Vector()             // default constructor
	{
		x = y = mag = ang = 0.0;
		mode = RECT;
	}

	// construct vector from rectangular coordinates if form is r
	// (the default) or else from polar coordinates if form is p
	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}

	// reset vector from rectangular coordinates if form is
	// RECT (the default) or else from polar coordinates if
	// form is POL
	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}

	Vector::~Vector()    // destructor
	{
	}

	void Vector::polar_mode()    // set to polar mode
	{
		mode = POL;
	}

	void Vector::rect_mode()     // set to rectangular mode
	{
		mode = RECT;
	}

	// operator overloading
	// add two Vectors
	Vector Vector::operator+(const Vector& b) const
	{
		return Vector(x + b.x, y + b.y);
	}

	// subtract Vector b from a
	Vector Vector::operator-(const Vector& b) const
	{
		return Vector(x - b.x, y - b.y);
	}

	// reverse sign of Vector
	Vector Vector::operator-() const
	{
		return Vector(-x, -y);
	}

	// multiply vector by n
	Vector Vector::operator*(double n) const
	{
		return Vector(n * x, n * y);
	}

	// friend methods
	// multiply n by Vector a
	Vector operator*(double n, const Vector& a)
	{
		return a * n;
	}

	// display rectangular coordinates if mode is RECT,
	// else display polar coordinates if mode is POL
	std::ostream& operator<<(std::ostream& os, const Vector& v)
	{
		if (v.mode == Vector::RECT)
			os << "(x,y) = (" << v.x << ", " << v.y << ")";
		else if (v.mode == Vector::POL)
		{
			os << "(m,a) = (" << v.mag << ", "
				<< v.ang * Rad_to_deg << ")";
		}
		else
			os << "Vector object mode is invalid";
		return os;
	}

}  // end namespace VECTOR
// c11p3.cpp -- using the Vector class
// compile with the vect.cpp file
#include <iostream>
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype
//#include "vect.h"
int main()
{
	using namespace std;
	using namespace VECTOR;
	srand(time(0));     // seed random-number generator
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	unsigned long max_steps = 0;
	unsigned long min_steps = -1;//上限，比上限大的数就从下限开始
	unsigned long total_steps = 0;
	double average_steps = 0;
	int test_times = 0;
	std::cout << "Enter test times:";
	cin >> test_times;
	for (int i = 0; i < test_times; i++)
	{
		std::cout << "Enter target distance (q to quit): ";
		if (!(cin >> target))
			break;
		std::cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		while (result.magval() < target)
		{
			std::cout << result << endl;
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		std::cout << "After " << steps << " steps, the subject "
			"has the following location:\n";
		std::cout << result << endl;
		result.polar_mode();
		std::cout << " or\n" << result << endl;
		std::cout << "Average outward distance per step = "
			<< result.magval() / steps << endl;
		total_steps += steps;
		if (steps > max_steps)
		{
			max_steps = steps;
		}
		else if (steps < min_steps)
		{
			min_steps = steps;
		}
		steps = 0;
		result.reset(0.0, 0.0);
	}
	average_steps = (double)(total_steps / test_times);
	std::cout << "Total steps=" << total_steps << endl;
	std::cout << "Average steps=" << average_steps << endl;
	std::cout << "Maximum steps=" << max_steps << endl;
	std::cout << "Minimum steps=" << min_steps << endl;
	std::cout << "Bye!" << endl;
	return 0;
}
//4.
// mytime3.h -- Time class with friends
#ifndef MYTIME3_H_
#define MYTIME3_H_
#include <iostream>

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	friend const Time operator+(const Time& t1, const Time& t2);
	friend const Time operator-(const Time& t1, const Time& t2);
	friend const Time operator*(const Time& t, double mult);
	friend Time operator*(double m, const Time& t)
	{
		return t * m;
	}   // inline definition
	friend std::ostream& operator<<(std::ostream& os, const Time& t);

};
#endif
// mytime3.cpp  -- implementing Time methods
//#include "mytime3.h"
Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::AddHr(int h)
{
	hours += h;
}

void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

const Time operator+(const Time& t1, const Time& t2)
{
	Time sum;
	sum.minutes = t1.minutes + t2.minutes;
	sum.hours = t1.hours + t2.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

const Time operator-(const Time& t1, const Time& t2)
{
	Time diff;
	int tot1, tot2;
	tot1 = t2.minutes + 60 * t2.hours;
	tot2 = t1.minutes + 60 * t1.hours;
	diff.minutes = (tot2 - tot1) % 60;
	diff.hours = (tot2 - tot1) / 60;
	return diff;
}

const Time operator*(const Time& t, double mult)
{
	Time result;
	long totalminutes = t.hours * mult * 60 + t.minutes * mult;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

std::ostream& operator<<(std::ostream& os, const Time& t)
{
	os << t.hours << " hours, " << t.minutes << " minutes";
	return os;
}
//usetime3.cpp -- using the fourth draft of the Time class
// compile usetime3.cpp and mytime3.cpp together
#include <iostream>
//#include "mytime3.h"
int main()
{
	using std::cout;
	using std::endl;
	Time aida(3, 35);
	Time tosca(2, 48);
	Time temp;

	cout << "Aida and Tosca:\n";
	cout << aida << "; " << tosca << endl;
	temp = aida + tosca;     // operator+()
	cout << "Aida + Tosca: " << temp << endl;
	temp = aida * 1.17;  // member operator*()
	cout << "Aida * 1.17: " << temp << endl;
	cout << "10.0 * Tosca: " << 10.0 * tosca << endl;
	// std::cin.get();
	return 0;
}
//5.
// stonewt.h -- definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_
using namespace std;
class Stonewt
{
private:
	enum status { to_stone, to_pds_left, to_pounds };
	enum { Lbs_per_stn = 14 };      // pounds per stone
	int stone;                    // whole stones
	double pds_left;              // fractional pounds
	double pounds;                // entire weight in pounds
	int mode;
public:
	void set_to_stone() { mode = to_stone; }
	void set_to_pounds() { mode = to_pounds; }
	void set_to_pds_left() { mode = to_pds_left; }
	Stonewt(double lbs);          // constructor for double pounds
	Stonewt(int stn, double lbs); // constructor for stone, lbs
	Stonewt();                    // default constructor
	~Stonewt();
	friend ostream& operator<<(ostream& os, const Stonewt& s);   // show weight in stone format
};
#endif
// stonewt.cpp -- Stonewt methods
#include <iostream>
using std::cout;
//#include "stonewt.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs)
{
	stone = int(lbs) / Lbs_per_stn;    // integer division
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs)
{
	if (mode == to_stone)
		stone = stn;
	else if (mode == to_pds_left)
		pds_left = lbs;
	else if (mode == to_pounds)
		pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()          // default constructor, wt = 0
{
	stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt()         // destructor
{
}

// show weight in stones
ostream& operator<<(ostream& os, const Stonewt& s)
{
	if (s.mode == Stonewt::to_pounds)
		os << s.pounds << "pounds." << endl;
	else
		os << s.stone << " stone, " << s.pds_left << " pounds" << endl;
	return os;
}
// stone.cpp -- user-defined conversions
// compile with stonewt.cpp
#include <iostream>
using std::cout;
//#include"stonewt.h"
void display(const Stonewt& st, int n);
int main()
{
	Stonewt incognito = 275; // uses constructor to initialize
	Stonewt wolfe(285.7);    // same as Stonewt wolfe = 285.7;
	Stonewt taft(21, 8);
	incognito.set_to_stone();
	wolfe.set_to_stone();
	taft.set_to_pounds();
	std::cout << "The celebrity weighed ";
	cout << incognito;
	std::cout << "The detective weighed ";
	cout << wolfe;
	std::cout << "The President weighed ";
	cout << taft;
	incognito = 276.8;      // uses constructor for conversion
	taft = 325;             // same as taft = Stonewt(325);
	std::cout << "After dinner, the celebrity weighed ";
	cout << incognito;
	std::cout << "After dinner, the President weighed ";
	cout << taft;
	display(taft, 2);
	std::cout << "The wrestler weighed even more.\n";
	display(422, 2);
	std::cout << "No stone left unearned\n";
	return 0;
}
void display(const Stonewt& st, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << "Wow! ";
		cout << st;
	}
}


//6.
// stonewt.h -- definition for the Stonewt class
#pragma once
#include<iostream>
using namespace std;
class Stonewt
{
private:
	enum status { to_stone, to_pds_left, to_pounds };
	enum { Lbs_per_stn = 14 };      // pounds per stone
	int stone;                    // whole stones
	double pds_left;              // fractional pounds
	double pounds;                // entire weight in pounds
	int mode;
public:
	void set_to_stone() { mode = to_stone; }
	void set_to_pounds() { mode = to_pounds; }
	void set_to_pds_left() { mode = to_pds_left; }
	Stonewt(double lbs);          // constructor for double pounds
	Stonewt(int stn, double lbs); // constructor for stone, lbs
	Stonewt();                    // default constructor
	~Stonewt();
	friend bool operator<(const Stonewt& s1, const Stonewt& s2);
	friend bool operator>(const Stonewt& s1, const Stonewt& s2);
	friend bool operator==(const Stonewt& s1, const Stonewt& s2);
	friend bool operator!=(const Stonewt& s1, const Stonewt& s2);
	friend bool operator<=(const Stonewt& s1, const Stonewt& s2);
	friend bool operator>=(const Stonewt& s1, const Stonewt& s2);
	friend ostream& operator<<(ostream& os, const Stonewt& s);   // show weight in stone format
};
// stonewt.cpp -- Stonewt methods
#include <iostream>
using std::cout;
//#include "stonewt.h"
Stonewt::Stonewt(double lbs)
{
	stone = int(lbs) / Lbs_per_stn;    // integer division
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
	mode = to_pounds;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs)
{
	if (mode == to_stone)
		stone = stn;
	else if (mode == to_pds_left)
		pds_left = lbs;
	else if (mode == to_pounds)
		pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()          // default constructor, wt = 0
{
	stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt()         // destructor
{
}

// show weight in stones
ostream& operator<<(ostream& os, const Stonewt& s)
{
	if (s.mode == Stonewt::to_pounds)
		os << s.pounds << "pounds." << endl;
	else
		os << s.stone << " stone, " << s.pds_left << " pounds" << endl;
	return os;
}
bool operator<(const Stonewt& s1, const Stonewt& s2)
{
	return s1.pounds < s2.pounds;
}
bool operator>(const Stonewt& s1, const Stonewt& s2)
{
	return s1.pounds > s2.pounds;
}
bool operator==(const Stonewt& s1, const Stonewt& s2)
{
	return s1.pounds == s2.pounds;
}
bool operator!=(const Stonewt& s1, const Stonewt& s2)
{
	return s1.pounds != s2.pounds;
}
bool operator<=(const Stonewt& s1, const Stonewt& s2)
{
	return s1.pounds <= s2.pounds;
}
bool operator>=(const Stonewt& s1, const Stonewt& s2)
{
	return s1.pounds >= s2.pounds;
}
// stone.cpp -- user-defined conversions
// compile with stonewt.cpp
#include <iostream>
//#include"stonewt.h"
using namespace std;
int main()
{
	Stonewt s6[6]{ 123,74,57 };
	std::cout << "Now provide three stone weights:" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << ":";
		double temp;
		while (!(cin >> temp))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "It is invalid.Try again:";
		}
		while (cin.get() != '\n')
			continue;
		s6[i + 3] = temp;
	}
	int index_min = 0;
	int index_max = 0;
	for (int i = 0; i < 6; i++)
	{
		if (s6[i] > s6[index_max])
			index_max = i;
		if (s6[i] < s6[index_min])
			index_min = i;
	}
	Stonewt s_t = 11;
	int ele = 0;
	for (int i = 0; i < 6; i++)
	{
		if (s6[i] >= s_t)
			ele++;
	}
	cout << "Minimum element is " << index_min + 1 << " : " << s6[index_min] << endl;
	cout << "Maximum element is " << index_max + 1 << " : " << s6[index_max] << endl;
	cout << "There is " << ele << " element which is bigger than 11 stone." << endl;
	return 0;
}
//7.
//Complex0.h
#pragma once
#include<iostream>
class Complex_ {
private:
	double re;
	double im;
public:
	Complex_();
	Complex_(double r, double i);
	~Complex_();
	friend Complex_ operator+(Complex_& f1, Complex_& f2);
	friend Complex_ operator-(Complex_& f1, Complex_& f2);
	friend Complex_ operator*(Complex_& f1, Complex_& f2);
	friend Complex_ operator*(double a, Complex_& f1);
	Complex_ operator*(double a);
	friend Complex_ operator~(Complex_& f1);
	friend std::ostream& operator<<(std::ostream& os, const Complex_& c);
	friend std::istream& operator>>(std::istream& is, Complex_& c);
};
//Complex0.cpp
#include<iostream>
//#include"Complex0.h"
Complex_::Complex_()
{
	re = 0;
	im = 0;
}
Complex_::Complex_(double r, double i)
{
	re = r;
	im = i;
}
Complex_::~Complex_()
{

}
Complex_ operator+(Complex_& f1, Complex_& f2)
{
	return Complex_(f1.re + f2.re, f1.im + f2.im);
}
Complex_ operator-(Complex_& f1, Complex_& f2)
{
	return Complex_(f1.re - f2.re, f1.im - f2.im);
}
Complex_ operator*(Complex_& f1, Complex_& f2)
{
	return Complex_(f1.re * f2.re - f1.im * f2.im, f1.re * f2.im + f1.im * f2.re);
}
Complex_ operator*(double a, Complex_& f1)
{
	return Complex_(f1.re * a, f1.im * a);
}
Complex_ Complex_::operator*(double a)
{
	return Complex_(re * a, im * a);
}
Complex_ operator~(Complex_& f1)
{
	return Complex_(f1.re, -f1.im);
}
std::ostream& operator<<(std::ostream& os, const Complex_& c)
{
	os << c.re << "+" << c.im << "i";
	return os;
}
std::istream& operator>>(std::istream& is, Complex_& c)
{
	std::cout << "Please enter the real part:";
	is >> c.re;
	std::cout << "Please enter the imaginary part:";
	is >> c.im;
	return is;
}
#include<iostream>
//#include"Complex0.h"
using namespace std;
int main()
{
	Complex_ a(3.0, 4.0);
	Complex_ c;
	cout << "Enter a complex number (q to quit):" << endl;
	while (cin >> c)
	{
		cout << "c is " << c << endl;
		cout << "complex conjugate is " << ~c << endl;
		cout << "a is " << a << endl;
		cout << "a+c is " << a + c << endl;
		cout << "a-c is " << a - c << endl;
		cout << "a*c is " << a * c << endl;
		cout << "2*c is " << 2 * c << endl;
		cout << "c*2 is " << c * 2 << endl;
		cout << "Enter a complex number(q to quit)" << endl;
	}
	cout << "Done!" << endl;
	return 0;
}
