#include<iostream>
#include<random>
#include<cassert>
#include<csetjmp>
#include<cstdarg>
#include<algorithm>
#include<new>
#include<memory>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<iterator>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<chrono>
#include<type_traits>
#include<initializer_list>
#include<functional>
using namespace std;
using namespace std::chrono;
constexpr double wait_time = 0.1;
static const char* p = R"(Raw String\nNumber 
One)";
static const char* o = R"(Raw String Number Two)";
void Delay(const double t=wait_time)
{
	auto start = high_resolution_clock::now();
	while ((double)(duration_cast<seconds>(high_resolution_clock::now() - start)).count() < t);
}
void thr1()
{
	wcout << R"(明天记得提醒我)" << endl;
	Delay();
	string str_base = R"(那你明天记得提醒我提醒你)";
	string p1 = R"(提醒你)";
	string p2 = R"(提醒我)";
	for (int i = 0; i < 10e4; i++)
	{
		if (i % 2)
			str_base += p1;
		else str_base += p2;
		cout << str_base << endl;
		Delay();
	}
}
vector<int>v;
template<typename T>
using Iterator= typename T::iterator;
template<typename C,typename V>
vector<typename C::iterator>find_all(C& c, V v)
{
	vector<typename C::iterator>vc;
	for (auto p = c.begin(); p != c.end(); p++)
		if (*p == v)
			vc.push_back(p);
	return vc;
}
void f()
{
	srand(time(0));
	for (int i = 0; i < 30; i++)
	{
		int r = rand();
		v.push_back(r);
	}
	copy(v.begin(), v.end(), ostream_iterator<int, char>(cout, " "));
	cout << endl;
}
void g()
{
	srand(time(0));
	vector<vector<int>::iterator> res = find_all<vector<int>, int>(v, rand());
	cout << res.size() << endl;
	for (auto p : res)
		cout << *p << endl;
}
void thr2()
{
	auto t_0 = high_resolution_clock::now();
	thread t1{ f };
	t1.join();
	mutex m;
	unique_lock<mutex>lck(m);
	condition_variable mc;
	mc.notify_one();
	g();
	auto t_1 = high_resolution_clock::now();
	cout << (double)(duration_cast<milliseconds>(t_1 - t_0).count()) << "ms" << endl;
	cout.setf(ios_base::boolalpha);
	cout << is_arithmetic<int>() << endl;
	cout << is_class<char>::value << endl;
	initializer_list<double>p{ 3.5,3.8,8.1 };
	vector<double>dp(p);
	cout << dp.size() << endl;
	Delay(1);
}
typedef int(CF)(const void*, const void*);
using CFT=int(const void*, const void*);
void prin(int v, ...)
{
	va_list ap;
	va_start(ap, v);
	for (int i=0;i<v;i++)
	{
		char* temp = va_arg(ap, char*);
		cout << temp << " ";
	}
	cout << endl;
	va_end(ap);
}
void REPORT()
{
	cout << "Environment Report:" << endl;
	Delay(1);
	cout << "File:"<<__FILE__ << endl;
	Delay(1);
	cout << "Line:"<<__LINE__ << endl;
	Delay(1);
	cout << "C++ Standard Version:" << __cplusplus<< endl;
	Delay(1);
	cout << "Time:" << __DATE__ <<' '<< __TIME__ << endl;
	Delay(1);
	cout << "Function:" << __func__ << endl;
	Delay(1);
	cout << "Hosted?" << ((__STDC_HOSTED__) ? "Yes" : "No") << endl;
	Delay(1);
}
int main()
{
	srand(time(0));
	auto dic = bind(uniform_int_distribution<>{ 1, rand() }, default_random_engine{});
	int x = dic();
	cout << "Line:" << __LINE__ <<":"<< x << endl;

	if (rand()&1)
	{
		auto exce = []() { cout << "Fuck you."; };
		terminate_handler thl = set_terminate(exce);
		cout << "Line:" << __LINE__ << ":"; terminate();
		set_terminate(thl);
	}

	REPORT();

	endl(cout);
	Delay(1);
	cout << "Line:" << __LINE__ << ":";
	Delay(1);
	cout << "A Print_Screen Test:" << endl;
	Delay(1);
	endl(cout);
	for (int i = 0; i < 100; i++)
	{
		if (i & 1)
			cout << o << endl;
		else
			cout << p << endl;
		endl(cout);
		Delay(1);
	}
	cout << "Test Over." << endl;
	Delay(1);
	endl(cout);

	cout << "Line:" << __LINE__ << ":"; prin(3, "2ewq", "qwes", "wqdw");
	Delay(1);

	auto ptr = Delay;
	auto qtr = &Delay;
	(*ptr)(1);//对函数取地址后，默认参数不保留
	(qtr)(1);

	char buffer[7] = "wdasdw";
	FILE* fp = tmpfile();
	fwrite(buffer, sizeof(char), 7, fp);
	fclose(fp);
	Delay(1);

	cout<< "Line:" << __LINE__ << ":" <<round(3.6) << endl;
	Delay(1);

	bind(Delay, 0.3, std::placeholders::_1);
	Delay(1);

	auto s = [=](int x) {return x + 5; };
	Delay(1);
	function<void(const double)>f = s;
	Delay(1);

	int* p_ar = new(nothrow) int[5]{};
	operator delete[](p_ar, nothrow);
	Delay(1);

	unique_ptr<int[]>p{ new int[5] };
	Delay(1);

	int a = -176;
	int b = 56;
	int c = (int)(a >> 5) & 1;
	cout <<"Line:"<<__LINE__<<":"<< (a & b) + ((a ^ b) >> 1) << R"(and)"<< c << endl;
	Delay(1);

	cin.putback('d');
	cout << "Line:" << __LINE__ << ":";
	cout << (char)(cin.get()) << endl;
	Delay(1);

	vector<int>v{ 1,9,7,3,6,2,5,4,8 };
	sort(v.begin(), v.end());//<
	cout << "Line:" << __LINE__ << ":";
	cout.put('<');
	copy(v.begin(), v.end(), ostream_iterator<int, char>(cout, ","));
	cout.put('>') << endl;
	Delay(1);

	cout << "Line:" << __LINE__ << ":";
	char space[400];
	cout << "Enter:";
	cin.read(space, 400);//istream(cin.read(char*,sz))/ifstream(fstream f.read(char*,sz))->space
	cout << "Line:" << __LINE__ << ":";
	cout.write(space,strlen(space));//space->ostream(cout.write(char*,sz))/ofstream(fstream f.write(char*,sz))
	endl(cout);
	Delay(1);

	cout << "Line:" << __LINE__ << ":";
	assert(1 == 2);
	Delay(1);
}
