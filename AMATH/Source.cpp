#include<iostream>
#include"amath.h"
using namespace amath;
Math math_funs;
double function(double x)
{
	return math_funs.sin(x);
}
double rec(double x)
{
	return 1 / x;
}
double prt(double x)
{
	return 1/(x * x);
}
double geo(double x)
{
	return 1 / math_funs.powf(2, x);
}
int main()
{
	cout.precision(10);
	Complex_ c1(3.0, 4.0);
	Complex_ c2(14.0, 22.3);
	c1.set_pol();
	c2.set_pol();
	cout << c1 << endl;
	cout << c2 << endl;
	Complex_ cd = c1 * c2;
	cd.set_pol();
	cout << cd << endl;
	cin.get();
	double m = 1145141919810;
	int y = 0;
	double x = math_funs.frexp(m, y);
	cout << m << "=" << x << "*2^" << y << endl;
	cout << endl;
	double ar[12] = { 1.4,3.1,4.2,5.5,7.8,11.1,18.4,14.2,11.0,7.6,3.5,1.8 };
	for (int i = 0; i < 12; i++)
		cout << ar[i] << ' ';
	cout << endl;
	cout << "Average:" << math_funs.fav(ar, 12)  << endl;
	cout << "Maximum:" << math_funs.fmax(ar, 12) << endl;
	cout << "Minimum:" << math_funs.fmin(ar, 12) << endl;
	for (int i = 0; i < 12; i++)
		cout << math_funs.floor(ar[i]) << ' ';
	cout << endl;
	math_funs.resv_order(ar, 12);
	for (int i = 0; i < 12; i++)
		cout << ar[i] << ' ';
	cout << endl;
	math_funs.posi_order(ar, 12);
	for (int i = 0; i < 12; i++)
		cout << ar[i] << ' ';
	cout << endl;
	cout << "Sum:" << math_funs.sum(ar, 12)<< endl;
	cout << "Variance:" << math_funs.va(ar, 12) << endl;
	cout << "Standard Variance:" << math_funs.stddva(ar, 12) << endl;
	cout << endl;
	carte c = { 3,2,4 };
	polar p = math_funs.carte_to_polar(c);
	cout << c.x << "," << c.y << "," << c.z << endl;
	cout << p.r << "," << p.z << "," << p.arg << endl;
	cout << endl;
	for (int i = 1; i <= 100; i++)
		cout << "ln(" << (i) << ")=" << math_funs.ln(i) << endl;
	cout << endl;
	cout.precision(100);
	cout << "pi=" << 4 * math_funs.atan(1) << endl;
	cout << endl;
	cout.precision(10);
	cout << "sin(pi/4)=" << math_funs.sin(pi / 4) << endl;
	cout << "arcsin(0.5)=" << math_funs.asin(0.5) << endl;
	cout << "arctan(sqrt(3))=" << math_funs.atan(sqrt(3)) << endl;
	cout << "arctan(3,4)=" << math_funs.atan(3, 4) << endl;
	cout << "cosh(3)=" << math_funs.cosh(3) << endl;
	cout << "arccosh(3)=" << math_funs.acosh(3) << endl;
	cout << endl;
	cout << math_funs.intergral(0, pi, function) << endl;
	cout << endl;
	for (int i = 1; i <= 100000; i++)
		cout << "sigma(1-" << i << ")(1/x)=" << math_funs.sigma1(rec, i) << endl;
	cout << endl;
	for (int i = 1; i <= 100000; i++)
		cout << "sigma(1-" << i << ")(1/x^2)=" << math_funs.sigma1(prt, i) << endl;
	cout << endl;
	for (int i = 0; i <= 100000; i++)
		cout << "sigma(0-" << i << ")((1/2)^x)=" << math_funs.sigma0(geo, i) << endl;
	cout << endl;
	cout << "sigma(30-55)(1/x)=";
	cout << math_funs.sigma(rec, 30, 55) << endl;
	return 0;
}