#include<iostream>
//1
int main(void)
{
	using namespace std;
	cout << "My name is XXX XXXXXXX.My address is Jinan,SD,People's Republic of China." << endl;
	return 0;
}
//2
int main(void)
{
	using namespace std;
	cout << "Please enter a distance(Unit:long):";
	double ld;
	cin >> ld;
	double size;
	size = 220 * ld;
	cout << ld << " long is equal to " << size << " size." << endl;
	return 0;
}
//3
using namespace std;
void put1(void);
void put2(void);
int main(void)
{
	put1();
	put1();
	put2();
	put2();
	return 0;
}
void put1(void)
{
	cout << "The blind mice" << endl;
}
void put2(void)
{
	cout << "See how they run" << endl;
}
//4
using namespace std;
int main(void)
{
	cout << "Enter your age:";
	int age;
	cin >> age;
	int month;
	month = age * 12;
	cout << age << " ages are equal to " << month << " months." << endl;
	return 0;
}
//5
using namespace std;
double ToFahrenheit(double Celcius);
int main(void)
{
	cout << "Please enter a Celcius value:";
	double Cs;
	cin >> Cs;
	cout << Cs << " degrees Celcius is " << ToFahrenheit(Cs) << " degrees Fahrenheit." << endl;
	return 0;
}
double ToFahrenheit(double Celcius)
{
	double Fahrenheit;
	Fahrenheit = 1.8 * Celcius + 32.0;
	return Fahrenheit;
}
//6
using namespace std;
double Toasunits(double Ly);
int main(void)
{
	cout << "Enter the number of light years: ";
	double Ly;
	cin >> Ly;
	cout << Ly << " light years = " << Toasunits(Ly) << " astronomical units." << endl;
	return 0;
}
double Toasunits(double Ly)
{
	double Aunits;
	Aunits = 63240 * Ly;
	return Aunits;
}
//7
using namespace std;
void showtime(int hour, int min);
int main(void)
{
	cout << "Enter the number of hours:";
	int hour;
	cin >> hour;
	cout << "Enter the number of minutes:";
	int minutes;
	cin >> minutes;
	showtime(hour, minutes);
	return 0;
}
void showtime(int hour, int min)
{
	cout << "Time:" << hour << ":" << min << endl;
}
