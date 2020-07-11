#include<iostream>
#include <array>
#include <string>
//1
using namespace std;
double Har_av(double x, double y);
int main()
{
	double num1, num2;
	cout << "Enter two numbers:";
	cin >> num1;
	cin >> num2;
	while (cin.get() != '\n')
		continue;
	while ((num1 != 0) && (num2 != 0))
	{
		double har_av;
		har_av = Har_av(num1, num2);
		cout << "Their harmonic average is:" << har_av << endl;
		cout << "Enter two numbers:";
		cin >> num1;
		cin >> num2;
		while (cin.get() != '\n')
			continue;
	}
	cout << "That's all." << endl;
	return 0;
}
double Har_av(double x, double y)
{
	return (2.0 * x * y) / (x + y);
}
//2
using namespace std;
struct information {
	double* anarray;
	int num;
};
information Createsore(void)
{
	double* score = new double[10];
	int i = 0;
	while ((i < 10) && (cin >> score[i]))
	{
		while (cin.get() != '\n')
			continue;
		i++;
	}
	information elem;
	elem.anarray = score;
	elem.num = i;
	return elem;
}
void Showscore(double* score, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << score[i];
		cout.put(' ');
	}
	cout << endl;
}
double Reportaverage(double* score, int num)
{
	double sum = 0;
	for (int i = 0; i < num; i++)
		sum += score[i];
	double av = sum / num;
	return av;
}
int main()
{
	cout << "Please enter 10 golf scores at "
		"most(Press Ctrl+Z to quit):" << endl;
	information ele = Createsore();
	Showscore(ele.anarray, ele.num);
	cout << "The average score is:" << Reportaverage(ele.anarray, ele.num) << endl;
	return 0;
}
//3
using namespace std;
struct box {
	char maker[40];
	float height;
	float weigh;
	float length;
	float volume;
};
box Createstruct(void)
{
	box elem;
	cout << "Provide maker:";
	cin >> elem.maker;
	while (cin.get() != '\n')
		continue;
	cout << "Provide its size(length,weigh,height):";
	cin >> elem.length;
	cin >> elem.weigh;
	cin >> elem.height;
	return elem;
}
void Showstruct(box elems)
{
	cout << "Maker:" << elems.maker << endl;
	cout << "Length:" << elems.length << endl;
	cout << "Weigh:" << elems.weigh << endl;
	cout << "Height:" << elems.height << endl;
}
void Countvolume(box* pstr)
{
	pstr->volume = pstr->height * pstr->length * pstr->weigh;
}
int main()
{
	box elem = Createstruct();
	Showstruct(elem);
	Countvolume(&elem);
	cout << "Volume:" << elem.volume << endl;
	return 0;
}
//4
using namespace std;
long double probability(unsigned numbers, unsigned picks);
int main()
{
	double total[2];
	double choices[2];
	cout << "Enter the total number of choice on the game card and" << endl;
	cout << "The number of picks allowed of first pick:" << endl;
	while ((cin >> total[0] >> choices[0]) && choices[0] <= total[0])
	{
		cout << "Enter the total number of choice on the game card and" << endl;
		cout << "The number of picks allowed of second pick:" << endl;
		if (((cin >> total[1] >> choices[1]) && choices[1] <= total[1]))
		{
			cout << "You have one chance in ";
			cout << probability(total[0], choices[0]) * probability(total[1], choices[1]);
			cout << " of winnings." << endl;
			cout << "Next two numbers(q to quit):";
		}
		else goto flag;
	}
flag:cout << "Bye." << endl;
	return 0;
}
long double probability(unsigned numbers, unsigned picks)
{
	long double result = 1.0;
	long double n;
	unsigned p;
	for (n = numbers, p = picks; p > 0; n--, p--)
		result = result * n / p;
	return result;
}
//5
using namespace std;
unsigned long long fac(int n);
int main()
{
	int n;
	cout << "Enter a number(q to quit):";
	while (cin >> n)
	{
		cout << n << "!=" << fac(n) << endl;
		cout << "Enter a number(q to quit):";
	}
	cout << "Bye." << endl;
	return 0;
}
unsigned long long fac(int n)
{
	unsigned long long fac = 1ULL;
	for (int i = n; i > 0; i--)
		fac *= i;
	return fac;
}
//6
using namespace std;
int Fill_array(double* ar, int size)
{
	cout << "Enter a series of float numbers." << endl;
	cout << "Attention:the number of numbers should not over the size "
		<< size << ":";
	int i = 0;
	while ((cin >> *ar) && (i < size))
	{
		i++;
		ar++;
	}
	return i;
}
void Show_array(double* ar, int size)
{
	for (int i = 0; i < size; i++)
		cout << ar[i] << endl;
}
void Reverse_array(double* ar, int size)
{
	for (int i = 0, j = size - 1; i <= j; i++, j--)
	{
		double temp;
		temp = ar[i];
		ar[i] = ar[j];
		ar[j] = temp;
	}
}
int main()
{
	cout << "Please provide maximum size of an array:";
	int size;
	cin >> size;
	double* array = new double[size];
	int real_size;
	real_size = Fill_array(array, size);
	cout << "Here is the real array:" << endl;
	Show_array(array, real_size);
	Reverse_array(array, real_size);
	cout << "Here is the reversed array:" << endl;
	Show_array(array, real_size);
	return 0;
}
//7
using namespace std;
double* fill_array(double* start, int limit);
void show_array(double* start, double* end);
void revalue(double r, double* start, double* end);
int main()
{
	cout << "Enter max size:";
	int max;
	cin >> max;
	double* ps_start = new double[max];
	double* ps_end = fill_array(ps_start, max);
	show_array(ps_start, ps_end);
	if (ps_end > ps_start)
	{
		cout << "Enter revaluation factor:";
		double factor;
		while (!(cin >> factor))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input;please enter a number.";
		}
		revalue(factor, ps_start, ps_end);
		show_array(ps_start, ps_end);
	}
	cout << "Done." << endl;
	return 0;
}
double* fill_array(double* start, int limit)
{
	double temp;
	double* process = start;
	for (int i = 0; i < limit; i++, process++)
	{
		cout << "Enter value #" << (i + 1) << ": ";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input;input process terminated." << endl;
			break;
		}
		else if (temp < 0)
			break;
		*process = temp;
	}
	return process;
}
void show_array(double* start, double* end)
{
	int i = 0;
	double* process;
	for (process = start; process <= end; process++, i++)
	{
		cout << "Property #" << (i + 1) << ": $";
		cout << *process << endl;
	}
}
void revalue(double r, double* start, double* end)
{
	double* process;
	for (process = start; process <= end; process++)
		* process *= r;
}
//8. 
//a.
using namespace std;
const int Seasons = 4;
const char* Snames[Seasons] =
{ "Spring", "Summer", "Fall", "Winter" };

void fill(double* pa, int size);
void show(double* pa, int size);
int main()
{
	double expenses[Seasons];
	fill(expenses, Seasons);
	show(expenses, Seasons);
	return 0;
}
void fill(double* pa, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> pa[i];
	}
}
void show(double* pa, int size)
{
	double total = 0.0;
	cout << endl << "EXPENSES" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << Snames[i] << ": $" << pa[i] << endl;
		total += pa[i];
	}
	cout << "Total: $" << total << '\n';
}
//b.
using namespace std;
const int Seasons = 4;
const char* Snames[Seasons] =
{ "Spring", "Summer", "Fall", "Winter" };
struct expense {
	double expenses[Seasons];
};
void fill(expense*, int size);
void show(expense, int size);
int main()
{
	expense expenses;
	fill(&expenses, Seasons);
	show(expenses, Seasons);
	return 0;
}
void fill(expense* pstr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> pstr->expenses[i];
	}
}
void show(expense str, int size)
{
	double total = 0.0;
	cout << endl << "EXPENSES" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << Snames[i] << ": $" << str.expenses[i] << endl;
		total += str.expenses[i];
	}
	cout << "Total: $" << total << '\n';
}
//9
using namespace std;
const int SLEN = 30;
struct student {
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};
void ordinal(int num);
int getinfo(student pa[], int n);
void display1(student st);
void display2(const student* ps);
void display3(const student pa[], int n);
int main()
{
	cout << "Enter class size:";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n')
		continue;
	student* ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; i++)
	{
		cout << "The following is the ";
		ordinal(i + 1);
		cout << " student's information:" << endl;
		display1(ptr_stu[i]);
		cout << endl;
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete[] ptr_stu;
	cout << "Done" << endl;
	return 0;
}
int getinfo(student pa[], int n)
{
	int i = 0;
	for (; i < n; i++)
	{
		cout << "Please enter the ";
		ordinal(i + 1);
		cout << " student's fullname:";
		while ((cin.getline(pa[i].fullname, SLEN)) && (pa[i].fullname[0] == ' '))
			goto flag;
		cout << "Please enter the ";
		ordinal(i + 1);
		cout << " student's hobby:";
		cin.getline(pa[i].hobby, SLEN);
		cout << "Please enter the ";
		ordinal(i + 1);
		cout << " student's ooplevel:";
		cin >> pa[i].ooplevel;
		while (cin.get() != '\n')
			continue;
	}
flag:return i;
}
void display1(student st)
{
	cout << "Name:" << st.fullname << endl;
	cout << "Hobby:" << st.hobby << endl;
	cout << "Ooplevel:" << st.ooplevel << endl;
}
void display2(const student* ps)
{
	cout << "Name:" << ps->fullname << endl;
	cout << "Hobby:" << ps->hobby << endl;
	cout << "Ooplevel:" << ps->ooplevel << endl;
}
void display3(const student pa[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "The following is the ";
		ordinal(i + 1);
		cout << " student's information:" << endl;
		display1(pa[i]);
	}
}
void ordinal(int num)
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
//10
long double calculate(long double x, long double y, long double(*pfun)(long double, long double));
long double add(long double x, long double y);
long double substract(long double x, long double y);
long double multi(long double x, long double y);
long double divis(long double x, long double y);
long double max(long double x, long double y);
long double min(long double x, long double y);
typedef long double(*p_fun)(long double, long double);
int main()
{
	p_fun functions[6] = { add,substract,multi,divis,max,min };
	std::cout << "Enter two float numbers--x,y(q to quit):";
	double x, y;
	while (std::cin >> x >> y)
	{
		std::cout << "x+y    x-y    x*y    x/y    max(x,y)min(x,y)" << std::endl;
		for (int i = 0; i < 6; i++)
		{
			std::cout << functions[i](x, y) << "     ";
		}
		std::cout << std::endl << "Enter two float numbers--x,y(q to quit):";
	}
	std::cout << "Bye." << std::endl;
	return 0;
}
long double calculate(long double x, long double y, long double(*pfun)(long double, long double))
{
	return pfun(x, y);
}
long double add(long double x, long double y)
{
	return x + y;
}
long double substract(long double x, long double y)
{
	return x - y;
}
long double multi(long double x, long double y)
{
	return x * y;
}
long double divis(long double x, long double y)
{
	return x / y;
}
long double max(long double x, long double y)
{
	return(x > y ? x : y);
}
long double min(long double x, long double y)
{
	return(x < y ? x : y);
}

