//6-4
/*使用new和delete，使用string而不是字符数组，
将初始化改为输入，使程序更灵活*/
#include<iostream>
#include<string>
using namespace std;
struct bop {
	string fullname;
	string title;
	string bopname;
	int preference;/*0--fullname,1--title,2--bopname*/
};
void showmenu();
void ordinal(int num);
void showname(bop* ps, int i);
void showtitle(bop* ps, int i);
void showbopname(bop* ps, int i);
void showprefer(bop* ps, int i);
int main()
{
	cout << "Enter the number of members of BOP.";
	int member;
	int prefer;
	cin >> member;
	while (cin.get() != '\n')
		continue;
	bop* bop_mem = new bop[member];
	for (int i = 0; i < member; i++)
	{
		cout << "Now enter the ";
		ordinal(i + 1);
		cout << " member's fullname:";
		getline(cin, bop_mem[i].fullname);
		cout << "Enter the ";
		ordinal(i + 1);
		cout << " member's title:";
		getline(cin, bop_mem[i].title);
		cout << "Enter the ";
		ordinal(i + 1);
		cout << " member's bopname:";
		getline(cin, bop_mem[i].bopname);
		cout << "Enter the ";
		ordinal(i + 1);
		cout << " member's preference:";
		while (cin >> prefer)
		{
			if ((prefer != 0) && (prefer != 1) && (prefer != 2))
			{
				cout << "Preference only allowed 0,1,2.Please try again:";
				while (cin.get() != '\n')
					continue;
				continue;
			}
			else {
				bop_mem[i].preference = prefer;
				break;
			}
		}
		cout << "OK." << endl;
	}
	showmenu();
	char option;
	cout << "Enter your choice:";
	while (cin >> option)/*Press Ctrl+Z also cause stop*/
	{
		if (option == 'q')
			break;
		else switch (option)
		{
		case 'a':showname(bop_mem, member); break;
		case 'b':showtitle(bop_mem, member); break;
		case 'c':showbopname(bop_mem, member); break;
		case 'd':showprefer(bop_mem, member); break;
		default:break;
		}
		showmenu();
		cout << "Next choice:";
	}
	cout << "Bye!" << endl;
	return 0;
}
void showmenu()
{
	cout << "Benevolent Order of Programmers Report" << endl;
	cout << "a.display by name              b.display by title" << endl;
	cout << "c.display by bopname             d.display by preference" << endl;
	cout << "q.quit" << endl;
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
void showname(bop* ps, int i)
{
	for (int j = 0; j < i; j++)
		cout << ps[i].fullname;
}
void showtitle(bop* ps, int i)
{
	for (int j = 0; j < i; j++)
		cout << ps[i].title;
}
void showbopname(bop* ps, int i)
{
	for (int j = 0; j < i; j++)
		cout << ps[i].bopname;
}
void showprefer(bop* ps, int i)
{
	for (int j = 0; j < i; j++)
	{
		switch (ps[i].preference)
		{
		case 0:cout << ps[i].fullname; break;
		case 1:cout << ps[i].title; break;
		case 2:cout << ps[i].bopname; break;
		default:break;
		}
	}
}
//序数词转换函数：
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

