#include"amath.h"
#include<iostream>
using namespace amath;
double h_h(double a, double b)
{
	if (b - a <= 25)
		return 10e-6;
	else if (b - a > 25 && b - a < 800)
		return 10e-5;
	else if (b - a >= 800 && b - a < 10000)
		return 10e-4;
	else if (b - a >= 10000 && b - a < 135000)
		return 10e-3;
	else if (b - a >= 135000 && b - a < 1500000)
		return 10e-2;
	else if (b - a >= 1500000 && b - a < 4000000)
		return 2.5 * 10e-2;
	else if (b - a >= 4000000 && b - a < 8000000)
		return 5 * 10e-2;
	else return 0.1;
}
double fun(double x)
{
	return 1 / x;
}
double fun1(double x)
{
	return 1 / sqrt(1 - x * x);
}
double fun2(double x)
{
	return 1 / (1 + x * x);
}
double fun3(double x)
{
	return 1 / (fabs(x) * sqrt(x * x - 1));
}
void Math::ordinal(int num)
{
	switch (num)
	{
	case 0: {cout << "none"; return; } break;
	case 1: {cout << "first"; return; } break;
	case 2: {cout << "second"; return; } break;
	case 3: {cout << "third"; return; } break;
	case 4: {cout << "forth"; return; } break;
	case 5: {cout << "fifth"; return; }break;
	case 6: {cout << "sixth"; return; }break;
	case 7: {cout << "seventh"; return; }break;
	case 8: {cout << "eighth"; return; }break;
	case 9: {cout << "ninth"; return; }break;
	case 10: {cout << "tenth"; return; }break;
	default:break;
	}
	if (((num % 100 == 0)) || (num % 100 >= 11) && (num % 100 <= 19))
	{
		cout << num << "th";
		return;
	}
	if ((num % 100 >= 20) || ((num % 100 >= 1) && (num % 100 <= 10)))
	{
		if (num % 10 == 1)
			cout << num << "st";
		else if (num % 10 == 2)
			cout << num << "nd";
		else if (num % 10 == 3)
			cout << num << "rd";
		else cout << num << "th";
		return;
	}
}
double Math::recip(double x)
{
	return 1 / x;
}
double Math::sum(double* num, int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += num[i];
	return sum;
}
double Math::multi(double* num, int n)
{
	double sum = 1.0;
	for (int i = 0; i < n; i++)
		sum *= num[i];
	return sum;
}
double Math::fav(double* num, int n)//Counting average number
{
	double sum_n = sum(num, n);
	return sum_n / n;
}
double Math::fmax(double* num, int n)
{
	double max = *num;
	for (int i = 1; i < n; i++)
	{
		if (num[i] > max)
			max = num[i];
	}
	return max;
}
double Math::fmin(double* num, int n)
{
	double min = *num;
	for (int i = 1; i < n; i++)
	{
		if (num[i] < min)
			min = num[i];
	}
	return min;
}
void Math::posi_order(double* ar,int n)
{
	double temp;
	for(int i=0;i<n-1;i++)
		for (int j = i; j < n; j++)
		{
			if (ar[j] < ar[i])
			{
				temp = ar[i];
				ar[i] = ar[j];
				ar[j] = temp;
			}
		}
}
void Math::resv_order(double* ar, int n)
{
	double temp;
	for (int i = 0; i < n - 1; i++)
		for (int j = i; j < n; j++)
		{
			if (ar[j] > ar[i])
			{
				temp = ar[i];
				ar[i] = ar[j];
				ar[j] = temp;
			}
		}
}
double Math::fabs(double num)
{
	return (num > 0) ? num : (-num);
}
double Math::fmod(double num1, double num2)
{
	int int_part = ((int)num1) / ((int)num2);
	return (num1 - num2 * int_part);
}
double Math::modf(double x, double& y)
{
	y= floor(x);
	double digit_part = x - floor(x);
	return digit_part;
}
double Math::floor(double x)
{
	return (int)x;
}
double Math::ceil(double x)
{
	return floor(x) + 1;
}
double Math::powi(double x, int y)
{
	if (y < 0)
		return 1 / powi(x, -y);
	else
	{
		double p = 1.0;
		for (int i = 0; i < y; i++)
			p *= x;
		return p;
	}
}
long double Math::fac(int n)
{
	long double f = 1;
	if (n > 1)
		f = n * fac(n - 1);
	return f;
}
double Math::exp(double x)
{
	double int_part = powi(e, (int)x);
	double fl = x - (int)x;
	double fl_part = 1;
	for (int i = 1; i < 100; i++)
		fl_part += (1 / fac(i)) * powi(fl, i);
	return int_part * fl_part;
}
double Math::intergral(double a, double b, double(*fun)(double))//辅助计算自然对数、反三角函数等，平均时间花费0-0.3s
{
	const int divide = 500000;
	double h = (b - a) / divide;
	double in = fun(a);
	for (int i = 1; i < divide; i++)
	{
		in += (i % 2 == 1 ? 4 : 2) * fun(a + h * i);
	}
	in += fun(b);
	return in * (h / 3);
}
double Math::interg(double a, double b, double(*fun)(double))//为保证精度建议分段积分
{
	const double h = h_h(a, b);
	double divide = (b - a) / h;
	double in = fun(a);
	for (int i = 1; i < divide; i++)
	{
		in += (i % 2 == 1 ? 4 : 2) * fun(a + h * i);
	}
	in += fun(b);
	return in * (h / 3);
}
double Math::drvt(double x, double(*fun)(double))
{
	double df_dx = (fun(x + 10e-6) - fun(x)) / (10e-6);
	return df_dx;
}
double Math::par_df_dx(double x, double y, double z, double(*fun)(double, double, double))
{
	return (fun(x + 10e-6, y, z) - fun(x, y, z)) / (10e-6);
}
double Math::par_df_dy(double x, double y, double z, double(*fun)(double, double, double))
{
	return (fun(x, y + 10e-6, z) - fun(x, y, z)) / (10e-6);
}
double Math::par_df_dz(double x, double y, double z, double(*fun)(double, double, double))
{
	return (fun(x, y , z + 10e-6) - fun(x, y, z)) / (10e-6);
}
grad& Math::gradf(double x, double y, double z, double(*fun)(double , double , double))
{
	grad p;
	p.gradx = par_df_dx(x, y, z, fun);
	p.grady = par_df_dy(x, y, z, fun);
	p.gradz = par_df_dz(x, y, z, fun);
	return p;
}
double Math::ln(double x)//lnx=intergral(1,x,1/x),
//x<1000，基本准确；x>5000,误差为一亿分之一，x>10000，误差为5亿分之一，x>100000，误差为5万分之一。
{
	return intergral(1, x,fun);
}
double Math::powf(double x, double y)
{
	return exp(y * ln(x));//得数大于50万，误差大约为二分之一
}
double Math::log10(double x)
{
	return ln(x) / ln_10;
}
double Math::log2(double x)
{
	return ln(x) / ln_2;
}
double Math::log(double x,double y)
{
	return ln(y) / ln(x);
}
double Math::sqrt(double a)
{
	double _10_ = 1.0;
	while (a > 100)
	{
		a /= 100;
		_10_ *= 10;
	}
	double x = a / 2;
	for (int i = 1; i <= 10; i++)
		x = (x / 2 + a / (2 * x));
	return x * _10_;
}
double Math::cubt(double a)
{
	double _10_ = 1.0;
	while (a > 1000)
	{
		a /= 1000;
		_10_ *= 10;
	}
	double x = a / 2;
	for (int i = 1; i <= 10; i++)
		x = ((2*x) / 3 + a / (3 * powi(x,2)));
	return x * _10_;
}
double Math::nroot(double a,double b)//建议b小于500.
{
	double _10_ = 1.0;
	while (a > powi(10,b))
	{
		a /= powi(10, b);
		_10_ *= 10;
	}
	double x = a / 2;
	for (int i = 1; i <= 500000; i++)
		x = (((b-1)* x) / b + a / (b * powi(x, b-1)));
	return x * _10_;
}
double Math::sin(double r)
{
	if (r < 0)
		return -sin(-r);
	while (r >= 2 * pi)
	{
		r -= 2 * pi;
	}
	if (r > pi)
		return -sin(r - pi);
	if ((r > pi / 2) && (r <= pi))//下面两个区间都左开右闭合
		return sin(pi - r);
	if ((r > pi / 4) && (r <= pi / 2))
		return cos(pi / 2 - r);
	if ((r >= 0) && (r <= pi / 4))
	{
		double sinr=0;
		for(int i=0;i<10;i++)
			sinr+=(powi(-1,i)*powi(r,2*i+1))/fac(2*i+1);
		return sinr;
	}
}
double Math::cos(double r)
{
	if (r < 0)
		return cos(-r);
	while (r >= 2 * pi)
	{
		r -= 2 * pi;
	}
	if (r > pi)
		return cos(2 * pi - r);
	if ((r > pi / 2) && (r <= pi))//下面两个区间都左开右闭合
		return -cos(pi - r);
	if ((r > pi / 4) && (r <= pi / 2))
		return sin(pi / 2 - r);
	if ((r >= 0) && (r <= pi / 4))
	{
		double cosr = 1;
		for (int i = 1; i < 10; i++)
			cosr += ((powi(-1, i) * powi(r, 2 * i)) / fac(2 * i));
		return cosr;
	}
}
double Math::tan(double r)
{
	return sin(r) / cos(r);
}
double Math::sec(double r)
{
	return (1 / cos(r));
}
double Math::csc(double r)
{
	return (1 / sin(r));
}
double Math::cot(double r)
{
	return (1 / tan(r));
}
double Math::sinh(double x)
{
	return (powf(e, x) - powf(e, -x)) / 2;
}
double Math::cosh(double x)
{
	return (powf(e, x) + powf(e, -x)) / 2;
}
double Math::tanh(double x)
{
	return (sinh(x)) / (cosh(x));
}
double Math::coth(double x)
{
	return (cosh(x)) / (sinh(x));
}
double Math::sech(double x)
{
	return 1 / (cosh(x));
}
double Math::csch(double x)
{
	return 1 / (sinh(x));
}
double Math::asin(double y)
{
	if ((y > 1) || (y < -1))
		return -1;
	if (y == 1)
		return pi / 2;
	if (y == -1)
		return -pi / 2;
	else return intergral(0, y, fun1);
}
double Math::acos(double y)
{
	return pi / 2 - asin(y);
}
double Math::atan(double y)
{
	return intergral(0, y, fun2);
}
double Math::atan(double x, double y)
{
	return atan(y / x);
}
double Math::acot(double y)
{
	return pi / 2 - atan(y);
}
double Math::asec(double y)
{
	if ((y > -1) && (y < 1))
		return-1;
	if (y == 1)
		return 0;
	if (y == -1)
		return pi;
	else if (y > 1)
		return (intergral(sqrt(2), y, fun3) + pi / 4);//special point
	else if (y < 1)
		return pi - asec(-y);
}
double Math::acsc(double y)
{
	return pi / 2 - asec(y);
}
double Math::asinh(double x)
{
	return ln(x + sqrt(x * x + 1));
}
double Math::acosh(double x)
{
	return ln(x - sqrt(x * x - 1));
}
double Math::atanh(double x)
{
	return (1 / 2) * ln((1 - x) / (1 + x));
}
double Math::acoth(double x)
{
	return ln((1 + sqrt(x * x + 1)) / fabs(x));
}
double Math::asech(double x)
{
	return ln((1 + sqrt(1 - x * x)) / x);
}
double Math::acsch(double x)
{
	return (1 / 2) * ln((1 + x) / (x - 1));
}
polar Math::carte_to_polar(carte& tri)
{
	polar pol;
	pol.r = sqrt(powi(tri.x, 2) + powi(tri.y, 2));
	pol.arg = atan(tri.x, tri.y);
	pol.z = tri.z;
	return pol;
}
carte Math::polar_to_carte(polar& pol)
{
	carte tri;
	tri.x = pol.r * cos(pol.arg);
	tri.y = pol.r * sin(pol.arg);
	tri.z = pol.z;
	return tri;
}
sphere Math::carte_to_sphere(carte& tri)
{
	sphere sph;
	sph.p = sqrt(powi(tri.x, 2) + powi(tri.y, 2) + powi(tri.z, 2));
	sph.phi = atan(tri.z, sqrt(powi(tri.x, 2) + powi(tri.y, 2)));
	sph.the = atan(tri.x, tri.y);
	return sph;
}
carte Math::sphere_to_carte(sphere& sph)
{
	carte tri;
	tri.x = sph.p * sin(sph.phi) * cos(sph.the);
	tri.y = sph.p * sin(sph.phi) * sin(sph.the);
	tri.z = sph.p * cos(sph.phi);
	return tri;
}
sphere Math::polar_to_sphere(polar& pol)
{
	sphere sph;
	sph.p = sqrt(powi(pol.r, 2) + powi(pol.z, 2));
	sph.phi = atan(pol.z, pol.r);
	sph.the = pol.arg;
	return sph;
}
polar Math::sphere_to_polar(sphere& sph)
{
	polar pol;
	pol.r = sph.p * sin(sph.phi);
	pol.z = sph.p * cos(sph.phi);
	pol.arg = sph.the;
	return pol;
}
double Math::ldexp(double x, int y)
{
	return x * powi(e, y);
}
double Math::frexp(double x, int& y)
{
	int i = 0;
	if ((x <= 2) && (x >= -2))
	{
		y = i;
		return x;
	}
	else
	{
		while ((x > 2) || (x < -2))
		{
			x /= 2;
			i++;
		}
		y = i;
		return x;
	}
}
double Math::va(double* ar, int n)
{
	double av = fav(ar, n);
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += powi((ar[i]-av),2);
	}
	return sum / n;
}
double Math::stddva(double* ar, int n)
{
	return sqrt(va(ar, n));
}
double Math::sigma0(double(*fun)(double a), int n)
{
	double sum = 0;
	for (int i = 0; i <= n; i++)
		sum += fun(i);
	return sum;
}
double Math::sigma1(double(*fun)(double a), int n)
{
	double sum = 0;
	for (int i = 1; i <= n; i++)
		sum += fun(i);
	return sum;
}
double Math::sigma(double(*fun)(double a), int x,int y)
{
	double sum = 0;
	for (int i = x; i <= y; i++)
		sum += fun(i);
	return sum;
}
double Math::product1(double(*fun)(double a), int n)
{
	double pro = 1.0;
	for (int i = 1; i <= n; i++)
		pro *= fun(i);
	return pro;
}
double Math::product(double(*fun)(double a), int x, int y)
{
	double pro = 1.0;
	for (int i = x; i <= y; i++)
		pro *= fun(i);
	return pro;
}
Complex_::Complex_()
{
	re = 0.0;
	im = 0.0;
	mode = tri;
}
Complex_::Complex_(double r, double i)
{
	re = r;
	im = i;
	mode = tri;
}
Complex_::~Complex_()
{

}
Complex_ amath::operator+(Complex_& f1, Complex_& f2)
{
	return Complex_(f1.re + f2.re, f1.im + f2.im);
}
Complex_ amath::operator-(Complex_& f1, Complex_& f2)
{
	return Complex_(f1.re - f2.re, f1.im - f2.im);
}
Complex_ amath::operator*(Complex_& f1, Complex_& f2)
{
	return Complex_(f1.re * f2.re - f1.im * f2.im, f1.re * f2.im + f1.im * f2.re);
}
Complex_ amath::operator*(double a, Complex_& f1)
{
	return Complex_(f1.re * a, f1.im * a);
}
Complex_ Complex_::operator*(double a)
{
	return Complex_(re * a, im * a);
}
Complex_ amath::operator/(Complex_& f1, Complex_& f2)
{
	return Complex_((f1.re * f2.re + f1.im * f2.im) / (f2.re * f2.re + f2.im * f2.im)
		, (f1.im * f2.re - f1.re * f2.im) / (f2.re * f2.re + f2.im * f2.im));
}
Complex_ amath::operator~(Complex_& f1)
{
	return Complex_(f1.re, -f1.im);
}
std::ostream& amath::operator<<(std::ostream& os, const Complex_& c)
{
	if (c.mode == c.tri)
		os << c.re << "+" << c.im << "i";
	else if (c.mode == c.pol)
	{
		os << complex_to_polar(c).r << "∠" << complex_to_polar(c).arg;
	}
	else if (c.mode == c.sph)
	{
		os << complex_to_sphere(c).p << "∠" << complex_to_sphere(c).phi << "∠" << complex_to_sphere(c).the;
	}
	else
		os << "Error mode.";
	return os;
}
std::istream& amath::operator>>(std::istream& is, Complex_& c)
{
	std::cout << "Please enter the real part:";
	is >> c.re;
	std::cout << "Please enter the imaginary part:";
	is >> c.im;
	return is;
}
carte amath::complex_to_carte(const Complex_& f)
{
	carte c;
	c.x = f.re;
	c.y = f.im;
	c.z = 0;
	return c;
}
polar amath::complex_to_polar(const Complex_& f)
{
	Math t;
	carte tri = complex_to_carte(f);
	polar pol = t.carte_to_polar(tri);
	return pol;
}
sphere amath::complex_to_sphere(const Complex_& f)
{
	Math t;
	carte tri = complex_to_carte(f);
	sphere sph = t.carte_to_sphere(tri);
	return sph;
}