//P791-6:
#include<iostream>
#include<iomanip>
int main()
{
	int f;
	std::cin >> f;
	std::cout.setf(std::ios_base::showbase);
	std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
	std::cout << std::setw(15) << std::dec << f << " " << std::oct << f << " " << std::hex << f << std::endl;
	return 0;
}
//7.
#include<iostream>
#include<iomanip>
int main()
{
	char name[50];
	std::cout << "Enter your name:";
	std::cin.getline(name, 50, '\n');
	double wages;
	std::cout << "Enter your hourly wages:";
	std::cin >> wages;
	double hours;
	std::cout << "Enter number of hours worked:";
	std::cin >> hours;
	std::cout.setf(std::ios_base::showpoint);
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	std::cout.setf(std::ios_base::right, std::ios_base::adjustfield);
	std::cout << "First format:" << std::endl;
	std::cout << std::setw(30) << name << ":$" << std::setprecision(2) << std::setw(10)
		<< wages << ":" << std::setprecision(1) << std::setw(5) << hours << std::endl;
	std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
	std::cout << "Second format:" << std::endl;
	std::cout << std::setw(30) << name << ":$" << std::setprecision(2) << std::setw(10)
		<< wages << ":" << std::setprecision(1) << std::setw(5) << hours << std::endl;
	return 0;
}
//P792-794
//1. 
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char buffer[500];
	cin.get(buffer, 500, '$');
	int num = strlen(buffer);
	cout << num << endl;
	//char ch = cin.peek();
	//cout << ch << endl;
	return 0;
}
//2. 
#include<iostream>
#include<fstream>
using namespace std;
int main(int args, char* argv[])
{
	fstream FILE(argv[1], ios_base::out | ios_base::app);
	if (!FILE.is_open())
	{
		cerr << "Cannot open the file." << endl;
		exit(EXIT_FAILURE);
	}
	char buffer[500];
	cin.getline(buffer, 500, EOF);
	FILE << buffer << endl;
	FILE.close();
	return 0;
}
//3. 
#include<iostream>
#include<fstream>
using namespace std;
int main(int args, char* argv[])
{
	fstream FILE_IN(argv[1], ios_base::in);
	fstream FILE_OUT(argv[1], ios_base::out | ios_base::app);
	if (!FILE_IN.is_open())
	{
		cerr << "Cannot open the file_in." << endl;
		exit(EXIT_FAILURE);
	}
	if (!FILE_OUT.is_open())
	{
		cerr << "Cannot open the file_out." << endl;
		exit(EXIT_FAILURE);
	}
	char buffer[500];
	FILE_IN.getline(buffer, 500, EOF);
	FILE_OUT.write(buffer, strlen(buffer));
	FILE_IN.close();
	FILE_OUT.close();
	return 0;
}
//4.
#include<iostream>
#include<fstream>
using namespace std;
int main(int args, char* argv[])
{
	fstream FILE_IN1(argv[1], ios_base::in);
	fstream FILE_IN2(argv[2], ios_base::in);
	fstream FILE_OUT(argv[1], ios_base::out | ios_base::app);
	if (!FILE_IN1.is_open())
	{
		cerr << "Cannot open the file_in1." << endl;
		exit(EXIT_FAILURE);
	}
	if (!FILE_IN2.is_open())
	{
		cerr << "Cannot open the file_in2." << endl;
		exit(EXIT_FAILURE);
	}
	if (!FILE_OUT.is_open())
	{
		cerr << "Cannot open the file_out." << endl;
		exit(EXIT_FAILURE);
	}
	char buffer[500];
	FILE_IN1.seekg(0);
	FILE_IN2.seekg(0);
	while ((FILE_IN1.peek() != EOF) || (FILE_IN2.peek() != EOF))
	{
		FILE_IN1.getline(buffer, 500, '\n');
		FILE_OUT.write(buffer, strlen(buffer));
		FILE_IN1.seekg(strlen(buffer) + 1, ios_base::cur);
		for (int i = 0; i < 500; i++)
		{
			buffer[i] = 0;
		}
		FILE_IN2.getline(buffer, 500, '\n');
		FILE_OUT.write(buffer, strlen(buffer));
		FILE_IN2.seekg(strlen(buffer) + 1, ios_base::cur);
		for (int i = 0; i < 500; i++)
		{
			buffer[i] = 0;
		}
	}
	if (FILE_IN1.peek() == EOF)
	{
		while (FILE_IN2.peek() != EOF)
		{
			FILE_IN2.getline(buffer, 500, '\n');
			FILE_OUT.write(buffer, strlen(buffer));
			FILE_IN2.seekg(strlen(buffer) + 1, ios_base::cur);
			for (int i = 0; i < 500; i++)
			{
				buffer[i] = 0;
			}
		}
	}
	else if (FILE_IN2.peek == EOF)
	{
		while (FILE_IN1.peek() != EOF)
		{
			FILE_IN1.getline(buffer, 500, '\n');
			FILE_OUT.write(buffer, strlen(buffer));
			FILE_IN1.seekg(strlen(buffer) + 1, ios_base::cur);
			for (int i = 0; i < 500; i++)
			{
				buffer[i] = 0;
			}
		}
	}
	FILE_IN1.close();
	FILE_IN2.close();
	FILE_OUT.close();
	return 0;
}
//5.
#include<iostream>
#include<fstream>
#include<list>
#include<algorithm>
using namespace std;
int main()
{
	list<char*>lstr1;
	list<char*>lstr2;
	list<char*>lstr3;
	ifstream fin1("mat.dat", ios_base::in);
	ifstream fin2("pat.dat", ios_base::in);
	ofstream fout("matpat.dat", ios_base::out | ios_base::app);
	fin1.seekg(0);
	fin2.seekg(0);
	char buffer[50];
	while (fin1.peek() != EOF)
	{
		fin1.getline(buffer, 50, '\n');
		lstr1.push_back(buffer);
		fin1.seekg(strlen(buffer), ios_base::cur);
		for (int i = 0; i < 50; i++)
		{
			buffer[i] = 0;
		}
	}
	while (fin2.peek() != EOF)
	{
		fin2.getline(buffer, 50, '\n');
		lstr2.push_back(buffer);
		fin2.seekg(strlen(buffer), ios_base::cur);
		for (int i = 0; i < 50; i++)
		{
			buffer[i] = 0;
		}
	}
	lstr1.sort();
	lstr2.sort();
	lstr3.merge(lstr1, lstr2);
	lstr3.sort();
	lstr3.unique();
	for (list<char*>::iterator ptr = lstr3.begin(); ptr != lstr3.end(); ptr++)
	{
		fout << *ptr << endl;
	}
	fin1.close();
	fin2.close();
	fout.close();
	return 0;
}
//6.
//emp.h
#pragma once
#include<iostream>
#include<string>
using namespace std;
enum classkind { Zero, Employee, Manager, Fink, Highfink };
class abstr_emp {
private:
	string fname;
	string lname;
	string job;
public:
	abstr_emp();
	abstr_emp(const char* fn, const char* ln, const char* j);
	abstr_emp(const abstr_emp& e);
	virtual void ShowAll()const;
	virtual void SetAll();
	virtual void setall(ifstream& fin);
	virtual void writeall(ofstream& fout);
	friend ostream& operator<<(ostream& os, const abstr_emp& e);
	virtual ~abstr_emp() {};//经过验证这里不能是纯虚函数
};
class employee :public abstr_emp {
public:
	employee();
	employee(const char* fn, const char* ln, const char* j);
	employee(const employee& e);
	~employee() {}
	virtual void ShowAll()const;
	virtual void SetAll();
	virtual void setall(ifstream& fin);
	virtual void writeall(ofstream& fout);
};
class manager :virtual public abstr_emp {
private:
	int inchargeof;
protected:
	int InChargeOf()const { return inchargeof; }
	int& InChargeOf() { return inchargeof; }
public:
	manager();
	manager(const char* fn, const char* ln, const char* j, int ico = 0);
	manager(const abstr_emp& e, int ico);
	manager(const manager& m);
	virtual ~manager() {}
	virtual void ShowAll()const;
	virtual void SetAll();
	virtual void setall(ifstream& fin);
	virtual void writeall(ofstream& fout);
};
class fink :virtual public abstr_emp {
private:
	string reportsto;
protected:
	const string ReportsTo()const { return reportsto; }
	string& ReportsTo() { return reportsto; }
public:
	fink();
	fink(const char* fn, const char* ln, const char* j, const char* rpo);
	fink(const abstr_emp& e, const char* rpo);
	fink(const fink& e);
	virtual ~fink() {}
	virtual void ShowAll()const;
	virtual void SetAll();
	virtual void setall(ifstream& fin);
	virtual void writeall(ofstream& fout);
};
class highfink :public manager, public fink {
public:
	highfink();
	highfink(const char* fn, const char* ln, const char* j, const char* rpo, int ico);
	highfink(const abstr_emp& e, const char* rpo, int ico);
	highfink(const fink& f, int ico);
	highfink(const manager& m, const char* rpo);
	highfink(const highfink& h);
	virtual void ShowAll()const;
	virtual void SetAll();
	virtual void setall(ifstream& fin);
	virtual void writeall(ofstream& fout);
};
//emp.cpp
#include<iostream>
//#include"emp.h"
#include<fstream>
using namespace std;
abstr_emp::abstr_emp()
{
	fname = "null";
	lname = "null";
	job = "seeking......";
}
abstr_emp::abstr_emp(const char* fn, const char* ln, const char* j)
	:fname(fn), lname(ln), job(j) {}
abstr_emp::abstr_emp(const abstr_emp& e) : fname(e.fname), lname(e.lname), job(e.job) {}
void abstr_emp::ShowAll()const
{
	cout << "First name:" << fname << endl;
	cout << "Last name:" << lname << endl;
	cout << "Job:" << job << endl;
}
void abstr_emp::SetAll()
{
	cout << "Enter first name:";
	getline(cin, fname);
	cout << "Enter last name:";
	getline(cin, lname);
	cout << "Enter the job:";
	getline(cin, job);
}
void abstr_emp::setall(ifstream& fin)
{
	getline(fin, lname);
	getline(fin, lname);
	getline(fin, lname);
}
void abstr_emp::writeall(ofstream& fout)
{
	fout << fname << endl << lname << endl << job << endl;
}
ostream& operator<<(ostream& os, const abstr_emp& e)
{
	os << e.fname << " " << e.lname << " " << e.job << endl;
	return os;
}
employee::employee() :abstr_emp() {}
employee::employee(const char* fn, const char* ln, const char* j) : abstr_emp(fn, ln, j) {}
employee::employee(const employee& e) : abstr_emp(e) {}
void employee::ShowAll()const
{
	abstr_emp::ShowAll();
}
void employee::SetAll()
{
	abstr_emp::SetAll();
}
void employee::setall(std::ifstream& fin)
{
	abstr_emp::setall(fin);
}
void employee::writeall(std::ofstream& fout)
{
	fout << Employee << endl;
	abstr_emp::writeall(fout);
}
manager::manager() :abstr_emp(), inchargeof(0) {}
manager::manager(const char* fn, const char* ln, const char* j, int ico) : abstr_emp(fn, ln, j), inchargeof(ico) {}
manager::manager(const abstr_emp& e, int ico) : abstr_emp(e), inchargeof(ico) {}
manager::manager(const manager& m) : abstr_emp(m), inchargeof(m.inchargeof) {}
void manager::ShowAll()const
{
	abstr_emp::ShowAll();
	cout << "InChargeOf:" << InChargeOf() << endl;
}
void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "Inchargeof:";
	while (!(cin >> inchargeof))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cerr << "Invalid.Please try again:";
	}
}
void manager::setall(std::ifstream& fin)
{
	abstr_emp::setall(fin);
	fin >> inchargeof;
	fin.ignore();//==fin.ignore(1,EOF)
}
void manager::writeall(std::ofstream& fout)
{
	fout << Manager << endl;
	abstr_emp::writeall(fout);
	fout << inchargeof << endl;
}
fink::fink() :abstr_emp(), reportsto("Nothing......") {}
fink::fink(const char* fn, const char* ln, const char* j, const char* rpo)
	: abstr_emp(fn, ln, j), reportsto(rpo) {}
fink::fink(const abstr_emp& e, const char* rpo) : abstr_emp(e), reportsto(rpo) {}
fink::fink(const fink& e) : abstr_emp(e), reportsto(e.reportsto) {}
void fink::ShowAll()const
{
	abstr_emp::ShowAll();
	cout << "Reports to:" << ReportsTo() << endl;
}
void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Reports to:";
	getline(cin, reportsto);
}
void fink::setall(std::ifstream& fin)
{
	abstr_emp::setall(fin);
	fin >> reportsto;
	fin.ignore();//==fin.ignore(1,EOF)
}
void fink::writeall(std::ofstream& fout)
{
	fout << Fink << endl;
	abstr_emp::writeall(fout);
	fout << reportsto << endl;
}
highfink::highfink() :manager(), fink(), abstr_emp() {}
highfink::highfink(const char* fn, const char* ln, const char* j, const char* rpo, int ico)
	: manager(fn, ln, j, ico), fink(fn, ln, j, rpo), abstr_emp(fn, ln, j) {}
highfink::highfink(const abstr_emp& e, const char* rpo, int ico)
	: manager(e, ico), fink(e, rpo), abstr_emp(e) {}
highfink::highfink(const fink& f, int ico) : fink(f), manager(f, ico), abstr_emp(f) {}
highfink::highfink(const manager& m, const char* rpo) : manager(m), fink(m, rpo), abstr_emp(m) {}
highfink::highfink(const highfink& h) : manager(h), fink(h), abstr_emp(h) {}
void highfink::ShowAll()const
{
	abstr_emp::ShowAll();
	cout << "InChargeOf:" << InChargeOf() << endl;
	cout << "Reports to:" << ReportsTo() << endl;
}
void highfink::SetAll()
{
	abstr_emp::SetAll();
	int ico;
	cout << "Inchargeof:";
	while (!(cin >> ico))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cerr << "Invalid.Please try again:";
	}
	manager::InChargeOf() = ico;
	cout << "Reports to:";
	string rpt;
	getline(cin, rpt);
	ReportsTo() = rpt;
}
void highfink::setall(std::ifstream& fin)
{
	abstr_emp::setall(fin);
	fin >> manager::InChargeOf();
	fin.ignore();//==fin.ignore(1,EOF)
	fin >> fink::ReportsTo();
	fin.ignore();
}
void highfink::writeall(std::ofstream& fout)
{
	fout << Highfink << endl;
	abstr_emp::writeall(fout);
	fout << manager::InChargeOf() << endl;
	fout << fink::ReportsTo() << endl;
}
//pe17-6.cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
//#include "emp.h"
const int MAX = 10;
const char* file = "staff.txt";
int main()
{
	using namespace std;
	abstr_emp* pc[MAX];
	//打开文件并读取
	ifstream fin;
	int classtype;
	int i = 0;
	char ch;
	fin.open(file);
	if (fin.is_open())
	{
		std::cout << "Here are the current contents of the " << file << " file:\n";
		while ((fin >> classtype).get(ch))
		{
			switch (classtype)
			{
			case Employee: pc[i] = new employee; break;
			case Manager: pc[i] = new manager; break;
			case Fink: pc[i] = new fink; break;
			case Highfink: pc[i] = new highfink; break;
			default: cerr << "Warning: Type error!\n"; break;
			}
			pc[i]->setall(fin);
			pc[i]->ShowAll();
			i++;
		}
		fin.close();
	}
	//添加新内容
	ofstream fout(file, ios::out | ios::app);  //打开写入，只追加
	if (!fout.is_open())
	{
		cerr << "Can't open " << file << " file for output.\n";
		exit(EXIT_FAILURE);
	}
	int index = 0;
	std::cout << "\nPlease enter the class type of your input:\n";
	std::cout << "1)Employee\t2)Manager\t3)Fink\t\t4)Highfink\tq)Quit\n";
	while (cin >> classtype && index < MAX)
	{
		cin.ignore(); //==cin.ignore(1, EOF);
		switch (classtype)
		{
		case Employee:
			pc[index] = new employee;
			pc[index]->SetAll();
			break;
		case Manager:
			pc[index] = new manager;
			pc[index]->SetAll();
			break;
		case Fink:
			pc[index] = new fink;
			pc[index]->SetAll();
			break;
		case Highfink:
			pc[index] = new highfink;
			pc[index]->SetAll();
			break;
		default:
			cerr << "Warning: Type error!\n";
			break;
		}
		index++;
		std::cout << "\nPlease enter the class type of your input:\n";
		std::cout << "1)Employee\t2)Manager\t3)Fink\t\t4)Highfink\tq)Quit\n";
	}
	std::cout << "Input over.\nThank You!\n";
	std::cout << "Begin to write into the file...\n";
	std::cout << "Writing...\n";
	for (i = 0; i < index; i++)
		pc[i]->writeall(fout);
	fout.close();
	std::cout << "Write over.\n";
	//显示所有数据	
	fin.clear();
	fin.open(file);
	if (fin.is_open())
	{
		std::cout << "Here are the current contents of the " << file << " file:\n";
		while ((fin >> classtype).get(ch))
		{
			switch (classtype)
			{
			case Employee: pc[i] = new employee; break;
			case Manager: pc[i] = new manager; break;
			case Fink: pc[i] = new fink; break;
			case Highfink: pc[i] = new highfink; break;
			default: cerr << "Warning: Type error!\n"; break;
			}
			pc[i]->setall(fin);
			pc[i]->ShowAll();
			i++;
		}
		fin.close();
	}
	return 0;
}
//7.
//pe17-7.cpp
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
void ShowStr(const string& s)
{
	cout << s << endl;
}
class Store {
private:
	ofstream& os;
public:
	Store(ofstream& fout) :os(fout) {}
	~Store() {}
	void operator()(const string& s);
};
void Store::operator()(const string& s)
{
	uint32_t len = s.size();
	os.write((char*)& len, sizeof(size_t));
	os.write(s.data(), len);
}
void GetStrs(ifstream& is, vector<string>vstr)
{
	size_t len;
	string temp;
	while (is.read((char*)(&len), sizeof(size_t)) && len > 0)
	{
		char ch;
		temp = "";
		for (int i = 0; i < len; i++)
			if (is.read(&ch, 1))
				temp.push_back(ch);
			else break;
		if (is) //if(!is.eof())
			vstr.push_back(temp);
	}
}
int main()
{
	vector<string>vostr;
	string temp;
	cout << "Enter strings(Empty line to quit):\n";
	while (getline(cin, temp) && temp[0] != '\0')
		vostr.push_back(temp);
	cout << "Here is your input.\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);
	ofstream fout("string.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();
	vector<string>vistr;
	ifstream fin("strings.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cerr << "Could not open file for input.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	endl(cout);
	cout << "Here are the strings read from the file:" << endl;
	for_each(vistr.begin(), vistr.end(), ShowStr);
	return 0;
}
