#include<iostream>
#include<string>
#include<cctype>
#include<cstdbool>
#include<fstream>
//1
using namespace std;
int main()
{
	char ch;
	while ((ch = cin.get()) != '@')
	{
		if (isdigit(ch))
			continue;
		else if (islower(ch))
			ch = toupper(ch);
		else if (isupper(ch))
			ch = tolower(ch);
		cout << ch;
	}
	return 0;
}
//2
using namespace std;
int main()
{
	double donation[10];
	double donate;
	int i = 0;
	double sum = 0;
	while (cin >> donate)
	{
		donation[i] = donate;
		sum += donate;
		i++;
	}
	double av = sum / i;
	int Bigger_than_average = 0;
	for (int j = 0; j < i; j++)
		if (donation[j] > av)
			Bigger_than_average++;
	cout << "The average donation is " << av << endl;
	cout << "There is " << Bigger_than_average << " donations"
		" is bigger than average donation." << endl;
	return 0;
}
//3
using namespace std;
void showmenu(void);
int main()
{
	showmenu();
	char options;
	cin >> options;
	while ((options != 'c') && (options != 'p') && (options != 't') && (options != 'g'))
	{
		cout << "Please enter a c,p,t or g.";
		while (cin.get() != '\n')
			continue;
		cin >> options;
	}
	switch (options)
	{
	case 'c':cout << "A tiger is a carnivore." << endl; break;
	case 'p':cout << "Wolfgang Mozart is a pianist." << endl; break;
	case 't':cout << "A maple is a tree." << endl; break;
	case'g':cout << "Hide and Seek is a kind of games." << endl; break;
	default:break;
	}
	return 0;
}
void showmenu(void)
{
	cout << "Please enter one of the following choices:" << endl;
	cout << "c)carnivore                   p)pianist" << endl;
	cout << "t)tree                        g)game" << endl;
}
//Include a cycle :
using namespace std;
void showmenu(void);
int main()
{
	showmenu();
	char options;
	while (cin >> options)/*while((cin>>options)&&(!cin.eof/fail()))*/
	{
		while ((options != 'c') && (options != 'p') && (options != 't') && (options != 'g'))
		{
			cout << "Please enter a c,p,t or g.";
			while (cin.get() != '\n')
				continue;
			cin >> options;
		}
		switch (options)
		{
		case 'c':cout << "A tiger is a carnivore." << endl; break;
		case 'p':cout << "Wolfgang Mozart is a pianist." << endl; break;
		case 't':cout << "A maple is a tree." << endl; break;
		case'g':cout << "Hide and Seek is a kind of games." << endl; break;
		default:break;
		}
		showmenu();
	}
	cout << "That's all." << endl;
	return 0;
}
void showmenu(void)
{
	cout << "Please enter one of the following choices"
		"(press Ctrl+Z to quit):" << endl;
	cout << "c)carnivore                   p)pianist" << endl;
	cout << "t)tree                        g)game" << endl;
}
//5
using namespace std;
const int no_tax = 5000;
const int limit1 = 15000;
const int limit2 = 35000;
const double rate1 = 0.1;
const double rate2 = 0.15;
const double rate3 = 0.2;
double tax(double income);
int main()
{
	int income;
	cout << "Please enter your income:";
	while (cin >> income)
	{
		cout << "You should pay" << tax(income) << " tvarps for tax." << endl;
		cout << "Please enter your income:";
	}
	cout << "That's all." << endl;
	return 0;
}
double tax(double income)
{
	if (income <= no_tax)
		return 0;
	else if (income > no_tax && income <= limit1)
		return income * rate1;
	else if (income > limit1 && income < limit2)
		return limit1 * rate1 + (income - limit1) * rate2;
	else if (income > limit2)
		return limit1 * rate1 + (limit2 - limit1) * rate2 + (income - limit2) * rate3;
}
//6
using namespace std;
struct patron {
	string fullname;
	double donation;
};
void ordinal(int num);
int main()
{
	cout << "Enter the number of donater:";
	int donater;
	while (!(cin >> donater))
	{
		cin.clear();
		cout << "Please enter an interger." << endl;
		cout << "Retry:";
		while (cin.get() != '\n')
			continue;
	}
	while (cin.get() != '\n')
		continue;
	cout << "Now there is " << donater << " donaters." << endl;
	patron* ps = new patron[donater];
	for (int i = 0; i < donater; i++)
	{
		cout << "Enter the fullname of ";
		ordinal(i + 1);
		cout << " donater:";
		getline(cin, ps[i].fullname);
		cout << "Enter amount of donation of ";
		ordinal(i + 1);
		cout << " donater:";
		cin >> ps[i].donation;
		while (cin.get() != '\n')
			continue;
	}
	bool THIS_KIND_OF_PATRON_EXIST = 0;
	cout << "*********************TABLE OF GRAND PATRONS**********************" << endl;
	cout << "NAME            AMOUNT OF DONATION" << endl;
	for (int i = 0; i < donater; i++)
	{
		if (ps[i].donation > 10000)
		{
			cout << ps[i].fullname << "           " << ps[i].donation << endl;
			THIS_KIND_OF_PATRON_EXIST = 1;
		}
		else continue;
	}
	if (THIS_KIND_OF_PATRON_EXIST == 0)
		cout << "none." << endl;
	THIS_KIND_OF_PATRON_EXIST = 0;
	cout << "The rest is other patrons:" << endl;
	for (int i = 0; i < donater; i++)
	{
		if (ps[i].donation <= 10000)
		{
			cout << ps[i].fullname << "        " << ps[i].donation << endl;
			THIS_KIND_OF_PATRON_EXIST = 1;
		}
		else continue;
	}
	if (THIS_KIND_OF_PATRON_EXIST == 0)
		cout << "none." << endl;
	return 0;
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
//7
using namespace std;
int main()
{
	cout << "Enter words(q to quit):" << endl;
	string a_word;
	int others = 0, vowel_begin = 0, conso_begin = 0;
	while ((cin >> a_word))/*Using EOF*/
	{
		char ch = a_word[0];
		if (!isalpha(ch))
			others++;
		else {
			if ((ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u'))
				vowel_begin++;
			else conso_begin++;
		}
	}
	cout << vowel_begin << " words beginning with vowels" << endl;
	cout << conso_begin << " words beginning with consonants" << endl;
	cout << others << " others" << endl;
	return 0;
}
//8
using namespace std;
int main()
{
	ifstream Infile;
	cout << "Enter a filename:";
	string Filename;
	getline(cin, Filename);
	Infile.open(Filename);
	char ch;
	int char_num = 0;
	while (Infile.get(ch))
	{
		char_num++;
	}
	cout << "The file " << Filename << " had " << char_num << " characters." << endl;
	Infile.close();
	return 0;
}
//9
using namespace std;
struct patron {
	string fullname;
	double donation;
};
void ordinal(int num);
int main()
{
	ifstream FILE;
	cout << "Enter the name of source file:" << endl;
	string filename;
	cin >> filename;
	FILE.open(filename);;
	cout << "Enter the number of donater:";
	int donater;
	while (!(FILE >> donater))
	{
		FILE.clear();
		cout << "Please enter an interger." << endl;
		cout << "Retry:";
		while (FILE.get() != '\n')
			continue;
	}
	while (FILE.get() != '\n')
		continue;
	cout << "Now there is " << donater << " donaters." << endl;
	patron* ps = new patron[donater];
	for (int i = 0; i < donater; i++)
	{
		cout << "Enter the fullname of ";
		ordinal(i + 1);
		cout << " donater:";
		getline(FILE, ps[i].fullname);
		cout << "Enter amount of donation of ";
		ordinal(i + 1);
		cout << " donater:";
		FILE >> ps[i].donation;
		while (FILE.get() != '\n')
			continue;
	}
	bool THIS_KIND_OF_PATRON_EXIST = 0;
	cout << "*********************TABLE OF GRAND PATRONS**********************" << endl;
	cout << "NAME            AMOUNT OF DONATION" << endl;
	for (int i = 0; i < donater; i++)
	{
		if (ps[i].donation > 10000)
		{
			cout << ps[i].fullname << "           " << ps[i].donation << endl;
			THIS_KIND_OF_PATRON_EXIST = 1;
		}
		else continue;
	}
	if (THIS_KIND_OF_PATRON_EXIST == 0)
		cout << "none." << endl;
	THIS_KIND_OF_PATRON_EXIST = 0;
	cout << "The rest is other patrons:" << endl;
	for (int i = 0; i < donater; i++)
	{
		if (ps[i].donation <= 10000)
		{
			cout << ps[i].fullname << "        " << ps[i].donation << endl;
			THIS_KIND_OF_PATRON_EXIST = 1;
		}
		else continue;
	}
	if (THIS_KIND_OF_PATRON_EXIST == 0)
		cout << "none." << endl;
	return 0;
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
