#pragma once
#include<iostream>
#define I i
namespace amath {
	using namespace std;
	const long double pi = 3.1415926535897932384626433832795028841971;
	const long double e = 2.7182818284590452354;
	const long double ln_2 = 0.69314718055994530942;
	const long double ln_10 = 2.30258509299404568402;
	struct polar {
		double r;
		double arg;
		double z;
	};
	struct carte {
		double x;
		double y;
		double z;
	};
	struct sphere {
		double p;
		double phi;
		double the;
	};
	struct grad {
		double gradx;
		double grady;
		double gradz;
	};
	class Math {
	public:
		void ordinal(int num);
		double recip(double x);//reciprocal
		double sum(double* num, int n);
		double multi(double* num, int n);
		double fav(double* num, int n);
		double fmax(double* num, int n);
		double fmin(double* num, int n);
		void posi_order(double* ar, int n);
		void resv_order(double* ar, int n);
		double fabs(double num);
		double fmod(double num1, double num2);
		double modf(double x, double& y);//把x分为整数和小数部分，返回小数并将整数保存在y
		double floor(double x);//小取整
		double ceil(double x);//大取整
		double powi(double x, int y);//数的整数次幂
		long double fac(int n);//阶乘
		double exp(double);//e^x
		double intergral(double a, double b, double(*fun)(double));//求简单积分
		double interg(double a, double b, double(*fun)(double));//精度更高
		double drvt(double x, double(*fun)(double));
		double par_df_dx(double x, double, double, double(*fun)(double, double, double));
		double par_df_dy(double, double y, double, double(*fun)(double, double, double));
		double par_df_dz(double, double, double z, double(*fun)(double, double, double));
		grad& gradf(double, double, double, double(*fun)(double, double, double));
		double ln(double x);
		double powf(double x, double y);
		double log10(double x);
		double log2(double x);
		double log(double x, double y);//logxy,base on x.
		double sqrt(double x);
		double cubt(double x);
		double nroot(double x, double b);//x的b次方根
		double sin(double);//unit:rad
		double cos(double);
		double tan(double);
		double sec(double);
		double csc(double);
		double cot(double);
		double sinh(double);
		double cosh(double);
		double tanh(double);
		double sech(double);
		double csch(double);
		double coth(double);
		double asin(double);
		double acos(double);
		double atan(double);
		double atan(double x, double y);
		double asec(double);
		double acsc(double);
		double acot(double);
		double asinh(double);
		double acosh(double);
		double atanh(double);
		double asech(double);
		double acsch(double);
		double acoth(double);
		polar carte_to_polar(carte&);
		carte polar_to_carte(polar&);
		sphere carte_to_sphere(carte&);
		carte sphere_to_carte(sphere&);
		sphere polar_to_sphere(polar&);
		polar sphere_to_polar(sphere&);
		double ldexp(double, int);
		double frexp(double, int&);
		double va(double*, int n);
		double stddva(double*, int n);
		double sigma0(double(*fun)(double a), int n);//按fun(x)的映射得到的结果的级数求和，上限为n，从0开始
		double sigma1(double(*fun)(double a), int n);//按fun(x)的映射得到的结果的级数求和，上限为n，从1开始
		double sigma(double(*fun)(double a), int x, int y);
		double product1(double(*fun)(double a), int n);//按fun(x)的映射得到的结果的级数求积，上限为n，从1开始
		double product(double(*fun)(double a), int x, int y);
	};
	class Complex_ {
	private:
		enum mmode { tri, pol, sph };
		double re;
		double im;
		int mode;
	public:
		Complex_();
		Complex_(double r, double i);
		~Complex_();
		void set_tri() { mode = tri; }
		void set_pol() { mode = pol; }
		void set_sph() { mode = sph; }
		friend Complex_ operator+(Complex_& f1, Complex_& f2);
		friend Complex_ operator-(Complex_& f1, Complex_& f2);
		friend Complex_ operator*(Complex_& f1, Complex_& f2);
		friend Complex_ operator*(double a, Complex_& f1);
		Complex_ operator*(double a);
		friend Complex_ operator/(Complex_& f1, Complex_& f2);
		friend Complex_ operator~(Complex_& f1);
		friend std::ostream& operator<<(std::ostream& os, const Complex_& c);
		friend std::istream& operator>>(std::istream& is, Complex_& c);
		friend carte complex_to_carte(const Complex_& f);
		friend polar complex_to_polar(const Complex_& f);
		friend sphere complex_to_sphere(const Complex_& f);
	};
}

