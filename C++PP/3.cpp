#include<iostream>
#include<climits>
#include<cmath>
#include<cctype>
#include<string>
//1
const int factor = 12;
const double feet_to_cent = 30.48;
const double inch_to_cent = 25.4;
int main()
{
	using namespace std;
	cout << "Please enter your height by inch." << endl;
	int height_inch;
	cin >> height_inch;
	int height_feet;
	height_feet = height_inch / factor;
	cout << "Your height is "
		<< height_feet
		<< " feet and "
		<< (height_inch % factor)
		<< " inches."
		<< endl;
	cout << "It is equal to "
		<< ((static_cast<double>(height_feet)) * feet_to_cent
			+ static_cast<double>(height_inch % factor) * inch_to_cent)
		<< " centimeters."
		<< endl;
	return 0;
}
//2
const int kilo_to_pound = 2.2;
const double feet_to_cent = 0.3048;
const double inch_to_cent = 0.0254;
int main()
{
	using namespace std;
	while (1)
	{
		cout << "Please enter your height feet and inch:" << endl;
		double height_inch;
		int height_feet;
		cin >> height_feet;
		cin >> height_inch;
		float meters;
		meters = height_feet * feet_to_cent + height_inch * inch_to_cent;
		cout << "Your height is " << meters << " meters." << endl;
		cout << "Please enter your weight by pound:" << endl;
		double pound;
		cin >> pound;
		double kilo;
		kilo = pound / 2.2;
		cout << "Your weight is " << kilo << " kilograms." << endl;
		double BMI;
		BMI = kilo / (pow(meters, 2));
		cout << "Your BMI is " << BMI << " ." << endl;
		if (BMI <= 24 && BMI >= 19)
			cout << "Your BMI is of healthy region." << endl;
		else if (BMI < 19)
			cout << "Too thin when compared with the healthy region." << endl;
		else
			cout << "Too weight when compared with the healthy region." << endl;
	}
	return 0;
}
//3
const int deg_to_min = 60;
const int deg_to_sec = 60 * 60;
int main()
{
	using namespace std;
	cout << "Enter a latitude in degrees,minutes,and seconds:";
	cout << "First,enter the degrees:";
	int degree;
	cin >> degree;
	cout << "Next,enter the minutes of arc:";
	int min;
	cin >> min;
	cout << "Finally,enter the seconds of arc:";
	int sec;
	cin >> sec;
	cout << "North or South?";
	char N_S;
	cin >> N_S;
	if (islower(N_S))
		N_S = toupper(N_S);
	double latitude;
	latitude = degree +
		(double(min) / (double)deg_to_min) +
		((double)sec / static_cast<double>(deg_to_sec));
	cout << "It's " << latitude << N_S << " degrees." << endl;
	return 0;
}
//4
using namespace std;
const int hour_per_day = 24;
const int min_per_hour = 60;
const int sec_per_min = 60;
int main()
{
	cout << "Enter the number of seconds:";
	int secs;
	while ((cin >> secs) && (secs != 'q'))
	{
		int days, hours, minutes, seconds;
		days = secs / (hour_per_day * min_per_hour * sec_per_min);
		hours = (secs % (hour_per_day * min_per_hour * sec_per_min))
			/ (min_per_hour * sec_per_min);
		minutes = ((secs % (hour_per_day * min_per_hour * sec_per_min))
			% (min_per_hour * sec_per_min))
			/ (sec_per_min);
		seconds = ((secs % (hour_per_day * min_per_hour * sec_per_min))
			% (min_per_hour * sec_per_min))
			% (sec_per_min);
		cout << secs << " seconds= "
			<< days << " days,"
			<< hours << " hours,"
			<< minutes << " minutes,"
			<< seconds << "second "
			<< endl;
		cout << "Enter the number of seconds(press q to quit):";
	}
	cout << "THE END." << endl;
	return 0;
}
//5
using namespace std;
int main()
{
	cout << "Enter the country you want to study:";
	char country[20];/*这里先使用传统的C字符串（字符数组）*/
	cin.getline(country, 100);/*C++字符串输入；相当于fgets函数。*/
	for (int i = 0; country[i] != '\0'; i++)
		if (islower(country[i]))
			country[i] = toupper(country[i]);
	cout << "Enter the world's population:";
	unsigned long long world_popu;
	cin >> world_popu;
	cout << "Enter the population off the " << country << " :";
	unsigned long long coun_popu;
	cin >> coun_popu;
	double rate;
	rate = (static_cast<double>(coun_popu)) / ((double)world_popu) * double(100);
	cout << "The population of the " << country << " is " << rate << "% of the world population." << endl;
	return 0;
}
//6.7.综合起来:
using namespace std;
void question_a(void);
void question_b(void);
void american(void);
void european(void);
int main()
{
	cout << "           C++ Primer Plus Page 65 " << endl;
	cout << "A.Question6                       B.Question7" << endl;
	cout << "Press q to quit:";
	char op;
	while ((cin >> op) && (op != 'q'))
	{
		while ((cin.get()) != '\n')
			continue;
		if (islower(op))
		{
			op = toupper(op);
		}
		switch (op)
		{
		case'A':question_a(); break;
		case'B':question_b(); break;
		default:cout << "It is a wrong option.Please retry......" << endl; break;
		}
		cout << "           C++ Primer Plus Page 65 " << endl;
		cout << "A.Question6                       B.Question7" << endl;
		cout << "Press q to quit:";
	}
	cout << "That's all." << endl;
	return 0;
}
void question_a(void)
{
	cout << "          Showing the gasoline_consuming_rate           " << endl;
	cout << "C.American's Style                         D.European's Style" << endl;
	char option;
	cin >> option;
	if (islower(option))
	{
		option = toupper(option);
	}
	switch (option)
	{
	case'C':american(); break;
	case'D':european(); break;
	default:cout << "It is a wrong option.Please retry......" << endl; break;
	}
}
void american(void)
{
	cout << "Enter the riding distance(Unit:miles)";
	double miles;
	cin >> miles;
	cout << "Enter the gasoline consumption(Unit:gallon)";
	double gallon;
	cin >> gallon;
	double rate;
	rate = miles / gallon;
	cout << "Gasoline's consuming rate is " << rate << " miles_per_gallon(mpg)" << endl;
}
void european(void)
{
	cout << "Enter the riding distance(Unit:km)";
	double km;
	cin >> km;
	cout << "Enter the gasoline consumption(Unit:liter)";
	double liter;
	cin >> liter;
	double rate;
	rate = 100 * liter / km;
	cout << "Gasoline's consuming rate is " << rate << " liter_per_100km(l/100km)" << endl;
}
void question_b(void)
{
	cout << "             Choose the mode:" << endl;
	cout << "A.l/100km to mpg            B.mpg to 1/100km" << endl;
	char opt;
	cin >> opt;
	if (islower(opt))
		opt = toupper(opt);
	switch (opt)
	{
	case'A': {cout << "Please enter the gasoline's consuming rate with European style"
		"(liter_per_100km,l/100km):";
		double eurate;
		cin >> eurate;
		double usrate;
		usrate = 100 / (3.875 * 0.6214 * eurate);
		cout << eurate << "1/100km is equal to " << usrate << " mpg(American style)" << endl;
	}; break;
	case 'B': {cout << "Please enter the gasoline's consuming rate with American style"
		"(mpg):";
		double usrate;
		cin >> usrate;
		double eurate;
		eurate = 100 / (3.875 * 0.6214 * usrate);
		cout << usrate << "mpg is equal to " << eurate << " l/100km(European style)" << endl;
	}; break;
	default:cout << "It is a wrong option.Please retry......" << endl; break;
	}
}

