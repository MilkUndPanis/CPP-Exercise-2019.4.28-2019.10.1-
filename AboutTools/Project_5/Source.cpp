#include<iostream>
#include<string>
#include<chrono>
using namespace std;
using namespace chrono;
constexpr double wait_time = 0.5;
void Delay()
{
	auto start = high_resolution_clock::now();
	while ((double)(duration_cast<seconds>(high_resolution_clock::now() - start)).count() < wait_time);
}
int main()
{
	wcout << R"(����ǵ�������)" << endl;
	string str_base = R"(��������ǵ�������������)";
	string p1 = R"(������)";
	string p2 = R"(������)";
	for (int i = 0; i < 10e4; i++)
	{
		if (i % 2)
			str_base += p1;
		else str_base += p2;
		cout << str_base << endl;
		Delay();
	}
	cout << str_base << endl;
	return 0;
}