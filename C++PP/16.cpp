//1
#include<iostream>
#include<string>
using namespace std;
bool ispalin(string& str)
{
	int size = str.size();
	for (int i = 0; i < size; i++)
	{
		if (str[i] == str[size - 1 - i])
		{
			continue;
		}
		else return false;
	}
	return true;
}
int main()
{
	string a;
	getline(cin, a);
	if (ispalin(a) == true)
	{
		cout << "The string " << a << " is a palindrome." << endl;
	}
	else cout << "The string " << a << " is not a palindrome." << endl;
	return 0;
}
//2
#include<iostream>
#include<string>
#include<cctype>
using namespace std;
bool ispalin(string& str)
{
	string str_tst;
	int size = str.size();
	for (int i = 0, j = 0; i < size; i++)
	{
		if (ispunct(str[i]))
		{
			continue;
		}
		if (isupper(str[i]))
		{
			str_tst.push_back(toupper(str[i]));//此处用数组表示法逐下标赋值会发生错误
			j++;
			continue;
		}
		str_tst.push_back(str[i]);
	}
	int size_tst = str_tst.size();
	for (int i = 0; i < size_tst; i++)
	{
		if (str_tst[i] == str_tst[size_tst - 1 - i])
		{
			continue;
		}
		else return false;
	}
	return true;
}
int main()
{
	string a;
	getline(cin, a);
	if (ispalin(a) == true)
	{
		cout << "The string " << a << " is a palindrome." << endl;
	}
	else cout << "The string " << a << " is not a palindrome." << endl;
	return 0;
}
//3
// hangman.cpp -- 从文件里读取单词得到wordlist其他不变
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include<fstream>
#include<vector>
using namespace std;
int main()
{
	vector<string>wordlist;
	string inword;
	ifstream file;
	file.open("text.txt");
	while (file >> inword)
	{
		wordlist.push_back(inword);
	}
	srand(std::time(0));
	char play;
	cout << "Will you play a word game? <y/n> ";
	cin >> play;
	play = tolower(play);
	while (play == 'y')
	{
		string target = wordlist[rand() % wordlist.size()];
		int length = target.size();
		string attempt(length, '-');
		string badchars;
		int guesses = 6;
		cout << "Guess my secret word. It has " << length
			<< " letters, and you guess\n"
			<< "one letter at a time. You get " << guesses
			<< " wrong guesses.\n";
		cout << "Your word: " << attempt << endl;
		while (guesses > 0 && attempt != target)
		{
			char letter;
			cout << "Guess a letter: ";
			cin >> letter;
			if (badchars.find(letter) != string::npos
				|| attempt.find(letter) != string::npos)
			{
				cout << "You already guessed that. Try again.\n";
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos)
			{
				cout << "Oh, bad guess!\n";
				--guesses;
				badchars += letter; // add to string
			}
			else
			{
				cout << "Good guess!\n";
				attempt[loc] = letter;
				// check if letter appears again
				loc = target.find(letter, loc + 1);
				while (loc != string::npos)
				{
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "Your word: " << attempt << endl;
			if (attempt != target)
			{
				if (badchars.length() > 0)
					cout << "Bad choices: " << badchars << endl;
				cout << guesses << " bad guesses left\n";
			}
		}
		if (guesses > 0)
			cout << "That's right!\n";
		else
			cout << "Sorry, the word is " << target << ".\n";
		cout << "Will you play another? <y/n> ";
		cin >> play;
		play = tolower(play);
	}
	file.close();
	cout << "Bye\n";
	return 0;
}
//4.
#include<algorithm>
#include<list>
#include<iostream>
using std::list;
int reduce(long ar[], int n)
{
	list<long>va(ar, ar + n);
	va.sort();
	va.unique();
	int size = va.size();
	int i = 0;
	for (auto ps = va.begin(); ps != va.end(); ps++, i++)
	{
		ar[i] = *ps;
	}
	for (i = size; i < n; i++)
	{
		ar[i] = 0;
	}
	return size;
}
int main()
{
	long ar[10] = { 14,17,35,22,22,14,35,35,14,17 };
	int resize = reduce(ar, 10);
	std::cout << resize << std::endl;
	for (int i = 0; i < resize; i++)
	{
		std::cout << ar[i] << ' ';
	}
	return 0;
}
//5.
#include<algorithm>
#include<list>
#include<iostream>
using std::list;
template<typename T>
int reduce(T ar[], int n)
{
	list<T>va(ar, ar + n);
	va.sort();
	va.unique();
	int size = va.size();
	int i = 0;
	for (auto ps = va.begin(); ps != va.end(); ps++, i++)
	{
		ar[i] = *ps;
	}
	for (i = size; i < n; i++)
	{
		ar[i] = 0;
	}
	return size;
}
template<>
int reduce<std::string>(std::string ar[], int n)
{
	list<std::string>va(ar, ar + n);
	va.sort();
	va.unique();
	int size = va.size();
	int i = 0;
	for (auto ps = va.begin(); ps != va.end(); ps++, i++)
	{
		ar[i] = *ps;
	}
	for (i = size; i < n; i++)
	{
		ar[i] = "";
	}
	return size;
}
int main()
{
	long ar[10] = { 14,17,35,22,22,14,35,35,14,17 };
	int resize1 = reduce<long>(ar, 10);
	std::cout << resize1 << std::endl;
	for (int i = 0; i < resize1; i++)
	{
		std::cout << ar[i] << ' ';
	}
	std::cout << std::endl;
	std::string sr[10] = { "sjd","wjhdas","dhadsa","udaih","hdsa","sjd","awhid","udaih"
						,"sdh","awhid" };
	int resize2 = reduce<std::string>(sr, 10);
	std::cout << resize2 << std::endl;
	for (int i = 0; i < resize2; i++)
	{
		std::cout << sr[i] << ' ';
	}
	return 0;
}
//6.
#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <queue>
#include <algorithm>
class Customer
{
private:
	long arrive;        // arrival time for customer
	int processtime;    // processing time for customer
public:
	Customer() : arrive(0), processtime(0) {}
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};
void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}
typedef Customer Item;
using namespace std;
const int MIN_PER_HR = 60;
bool newcustomer(double x); // is there a new customer?
int main()
{
	std::srand(std::time(0));
	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: ";
	int qs;
	cin >> qs;
	queue<Item>line;
	cout << "Enter the number of simulation hours: ";
	int hours;
	cin >> hours;
	long cyclelimit = MIN_PER_HR * hours;
	cout << "Enter the average number of customers per hour: ";
	double perhour;         //  average # of arrival per hour
	cin >> perhour;
	double min_per_cust;    //  average time between arrivals
	min_per_cust = MIN_PER_HR / perhour;
	Item temp;              //  new customer data
	long turnaways = 0;     //  turned away by full queue
	long customers = 0;     //  joined the queue
	long served = 0;        //  served during the simulation
	long sum_line = 0;      //  cumulative line length
	int wait_time = 0;      //  time until autoteller is free
	long line_wait = 0;     //  cumulative time in line
	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust))  // have newcomer
		{
			if (line.size() == qs)
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle);    // cycle = time of arrival
				line.push(temp); // push() called deque<Item>::push_back()
			}
		}
		if (wait_time <= 0 && !line.empty())
		{
			line.pop();     // pop() called deque<Item>::pop_front()
			wait_time = temp.ptime(); // for wait_time minutes
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += line.size();
	}
	// reporting results
	if (customers > 0)
	{
		cout << "customers accepted: " << customers << endl;
		cout << "  customers served: " << served << endl;
		cout << "         turnaways: " << turnaways << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)sum_line / cyclelimit << endl;
		cout << " average wait time: "
			<< (double)line_wait / served << " minutes\n";
	}
	else
		cout << "No customers!\n";
	cout << "Done!\n";
	return 0;
}
//  x = average time, in minutes, between customers
//  return value is true if customer shows up this minute
bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}
//7.
#include<algorithm>
#include<iostream>
#include<vector>
#include<ctime>
#include<iterator>
using namespace std;
typedef vector<int> vint;
vint Lotto(int range, int sel)
{
	vint p(range);
	vint ret(sel);
	for (auto ps = p.begin(); ps != p.end(); ps++)
	{
		p[ps - p.begin()] = ps - p.begin() + 1;
	}
	for (int i = 0; i < sel; i++)
	{
		random_shuffle(p.begin(), p.end());
		srand(time(0));
		int pe = static_cast<int>(rand());
		while ((pe >= sel) || (pe < 0)) { pe = static_cast<int>(rand()); }
		ret[i] = p[pe];
	}
	return ret;
}
int main()
{
	srand(time(0));
	int range = static_cast<int>(rand());
	while (range <= 10)
	{
		range = static_cast<int>(rand());
	}
	cout << "Here is 6 numbers selected from range(1," << range << ") in random:" << endl;
	vint lotto = Lotto(range, 6);
	copy(lotto.begin(), lotto.end(), ostream_iterator<int, char>(cout, " "));
	return 0;
}
//8.
#include<iostream>
#include<list>
#include<algorithm>
#include<iterator>
#include<string>
using namespace std;
typedef list<string> lstring;
typedef istream_iterator<string, char> is;
typedef ostream_iterator<string, char> os;
typedef back_insert_iterator<lstring> bst;
int main()
{
	lstring l_mat;
	lstring l_pat;
	lstring l_union;
	string temp;
	cout << "Enter the names of Mat' friends:";
	while (cin >> temp)//Do not use copy()
	{
		l_mat.push_back(temp);
		if (cin.get() == '\n')
			break;
	}
	cout << "Next,enter the Pat's:";
	while (cin >> temp)
	{
		l_pat.push_back(temp);
		if (cin.get() == '\n')
			break;
	}
	l_mat.sort();
	l_pat.sort();
	l_union.merge(l_mat);
	l_union.merge(l_pat);
	l_union.unique();
	cout << "Here is the union:";
	copy(l_union.begin(), l_union.end(), os(cout, " "));
	return 0;
}
//9.
#include<algorithm>
#include<iostream>
#include<vector>
#include<list>
#include<ctime>
#include<iterator>
using namespace std;
typedef vector<int> vint;
typedef list<int> lint;
int main()
{
	vint vi0;
	vint vi;
	lint li;
	srand(time(0));
	for (int i = 0; i < 200000; i++)
	{
		int r = static_cast<int>(rand());
		vi0.push_back(r);
		vi.push_back(r);
		li.push_back(r);
	}

	clock_t start = clock();
	sort(vi.begin(), vi.end());
	clock_t end = clock();
	double sec1 = (end - start) / (static_cast<double>(CLOCKS_PER_SEC));

	clock_t a_start = clock();
	li.sort();
	clock_t a_end = clock();
	double sec2 = (a_end - a_start) / (static_cast<double>(CLOCKS_PER_SEC));

	copy(vi0.begin(), vi0.end(), li.begin());

	clock_t b_start = clock();
	copy(li.begin(), li.end(), vi.begin());
	sort(vi.begin(), vi.end());
	copy(vi.begin(), vi.end(), li.begin());
	clock_t b_end = clock();
	double sec3 = (b_end - b_start) / (static_cast<double>(CLOCKS_PER_SEC));

	cout << endl;
	cout << "Using list's sort directly costs time:" << sec2 << "s" << endl;
	cout << "Using STL's sort costs time:" << sec3 << "s" << endl;
	return 0;
}
//使用vector的sort算法比list快10倍
//c16p10:
// vect3.cpp -- using STL functions
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
struct Review {
	std::string title;
	int rating;
	double price;
};
typedef std::shared_ptr<Review> spr;
bool operator<(spr r1, spr r2)
{
	if (r1->title < r2->title)
		return true;
	else if (r1->title == r2->title && r1->rating < r2->rating)
		return true;
	else
		return false;
}
inline bool WorseThan(spr r1, spr r2) { return (r1->rating < r2->rating); }
inline bool BetterThan(spr r1, spr r2) { return !WorseThan(r1, r2); }
inline bool Cheaper(spr r1, spr r2) { return (r1->price < r2->price); }
inline bool Expensive(spr r1, spr r2) { return !Cheaper(r1, r2); }
bool FillReview(Review& rr)
{
	std::cout << "Enter book title (quit to quit): ";
	std::getline(std::cin, rr.title);
	if (rr.title == "quit")
		return false;
	std::cout << "Enter book rating: ";
	std::cin >> rr.rating;
	if (!std::cin)
		return false;
	while (std::cin.get() != '\n')
		continue;
	std::cout << "Enter book price: ";
	std::cin >> rr.price;
	if (!std::cin)
		return false;
	while (std::cin.get() != '\n')
		continue;
	return true;
}
inline void ShowReview(std::shared_ptr<Review>rr)
{
	std::cout << rr->rating << "\t" << rr->title << "\t" << rr->price << std::endl;
}
void menu()
{
	using std::cout;
	using std::endl;
	cout << "Choose what sequence you want to check:" << endl;
	cout << "A.Original" << endl;
	cout << "B.Alphabet" << endl;
	cout << "C.Rating(Up)" << endl;
	cout << "D.Rating(Down)" << endl;
	cout << "E.Price(Up)" << endl;
	cout << "F.Price(Down)" << endl;
	cout << "Q.Quit" << endl;
}
int main()
{
	using namespace std;
	vector<Review> tempbooks;
	Review temp;
	while (FillReview(temp))
	{
		tempbooks.push_back(temp);
	}
	vector<spr>books;
	for (auto pr = tempbooks.begin(); pr != tempbooks.end(); pr++)
	{
		spr temp(new Review);
		temp->price = (*pr).price;
		temp->rating = (*pr).rating;
		temp->title = (*pr).title;
		books.push_back(temp);
	}
	if (books.size() > 0)
	{
		cout << "Thank you. You entered the following "
			<< books.size() << " ratings.\n";
		while (1)
		{
			menu();
			unsigned char choice;
			while (!(cin >> choice))
			{
				cin.clear();
				while (cin.get() != '\n')
					continue;
				cerr << "Please try again:";
			}
			if (isalpha(choice))
				choice = toupper(choice);
			switch (choice)
			{
			case 'A':
				cout << "Rating\tBook\tPrice\n";
				for_each(books.begin(), books.end(), ShowReview); break;
			case 'B':
				sort(books.begin(), books.end());
				cout << "Sorted by title:\nRating\tBook\tPrice\n";
				for_each(books.begin(), books.end(), ShowReview); break;
			case 'C':
				sort(books.begin(), books.end(), WorseThan);
				cout << "Sorted by rating(up):\nRating\tBook\tPrice\n";
				for_each(books.begin(), books.end(), ShowReview); break;
			case 'D':
				sort(books.begin(), books.end(), BetterThan);
				cout << "Sorted by rating(down):\nRating\tBook\tPrice\n";
				for_each(books.begin(), books.end(), ShowReview); break;
			case 'E':
				sort(books.begin(), books.end(), Cheaper);
				cout << "Sorted by price(up):\nRating\tBook\tPrice\n";
				for_each(books.begin(), books.end(), ShowReview); break;
			case 'F':
				sort(books.begin(), books.end(), Expensive);
				cout << "Sorted by price(down):\nRating\tBook\tPrice\n";
				for_each(books.begin(), books.end(), ShowReview); break;
			case 'Q':goto flag;
			default:cout << "No matched."; break;
			}
		}
	}
	else
		cout << "No entries. ";
flag:cout << "Bye.\n";
	return 0;
}

