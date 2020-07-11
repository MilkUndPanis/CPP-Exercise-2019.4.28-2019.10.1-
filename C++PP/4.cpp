#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
#include<array>
//1
using namespace std;
struct Personal_Info {
	string first_name;
	string last_name;
	char grade;
	double age;
};
int main()
{
	Personal_Info info;
	cout << "What is your first name? ";
	getline(cin, info.first_name);
	cout << "What is your last name? ";
	getline(cin, info.last_name);
	cout << "What letter grade do you deserve? ";
	info.grade = cin.get();
	if (islower(info.grade))
		info.grade = toupper(info.grade);
	cout << "What is your age? ";
	cin >> info.age;
	if (info.grade == 'D')
		info.grade = 'F';
	else info.grade += 1;
	cout << "Name:" << info.last_name << ',' << info.first_name << endl;
	cout << "Grade: " << info.grade << endl;
	cout << "Age: " << info.age << endl;
	return 0;
}
//2
using namespace std;
const int Strsize = 20;
int main()
{
	string name;
	string dessert;
	cout << "Enter your name:" << endl;
	getline(cin, name);
	cout << "Enter your favourite dessert" << endl;
	getline(cin, dessert);
	cout << "I have some delicious " << dessert << " for you," << name << endl;
	return 0;
}
//3
using namespace std;
int main()
{
	char firstname[40];
	char lastname[40];
	const char* connect = ",";
	cout << "Enter your first name:";
	cin.getline(firstname, 40);
	cout << "Enter your last name:";
	cin.getline(lastname, 40);
	strcat(firstname, connect);
	strcat(firstname, lastname);
	cout << "Here's the information in a single string:" << firstname << endl;
	return 0;
}
//4
using namespace std;
int main()
{
	string firstname;
	string lastname;
	string connect = ",";
	string complex;
	cout << "Enter your first name:";
	getline(cin, firstname);
	cout << "Enter your last name:";
	getline(cin, lastname);
	complex = firstname + connect + lastname;
	cout << "Here's the information in a single string:" << complex << endl;
	return 0;
}
//5
using namespace std;
struct Candybar {
	string Branch;
	double weight;
	int calories;
};
int main()
{
	Candybar snack = { "Mocha Munch",2.3,350 };
	cout << "The branch of candy: " << snack.Branch << endl;
	cout << "The weight of candy: " << snack.weight << endl;
	cout << "The contained calories of candy: " << snack.calories << endl;
	return 0;
}
//6
using namespace std;
struct Candybar {
	string Branch;
	double weight;
	int calories;
}snack[3] =
{ {"Mocha Munch",2.3,350},
{"Mocha Munch",2.3,350},
{"Mocha Munch",2.3,350} };
int main()
{
	for (int i = 0; i < 3; i++)
	{
		cout << "The branch of candy"
			<< i + 1 << ": " << snack[i].Branch << endl;
		cout << "The weight of candy"
			<< i + 1 << ": " << snack[i].weight << endl;
		cout << "The contained calories of candy"
			<< i + 1 << ": " << snack[i].calories << endl;
	}
	return 0;
}
//7
using namespace std;
struct Pizza {
	string Cooperation;
	double Diameter;
	double Weight;
};
int main()
{
	Pizza pizza;
	while (1)
	{
		cout << "Please enter the productor of pizza:";
		getline(cin, pizza.Cooperation);
		cout << "Please enter the diameter of pizza:";
		cin >> pizza.Diameter;
		cout << "Last,please enter the weight of pizza(Unit:kilogram):";
		cin >> pizza.Weight;
		cout << "Here is the detail information of pizza:" << endl;
		cout << "Productor: " << pizza.Cooperation << endl;
		cout << "Diameter: " << pizza.Diameter << endl;
		cout << "Weight: " << pizza.Weight << endl;
	}
	return 0;
}
//8
using namespace std;
struct Pizza {
	string Cooperation;
	double Diameter;
	double Weight;
};
int main()
{
	char ch;
	cout << "Press any key to begin;Press q to quit:";
	while ((ch = cin.get()) != 'q')
	{
		Pizza* ptr = new Pizza;
		cout << "Please enter the diameter of pizza.";
		cin.get();
		cin >> ptr->Diameter;
		cout << "Please enter the productor of pizza:";
		cin.get();
		getline(cin, ptr->Cooperation);
		cout << "Last,please enter the weight of pizza(Unit:kilogram):";
		cin >> ptr->Weight;
		cout << "Here is the detail information of pizza:" << endl;
		cout << "Productor: " << ptr->Cooperation << endl;
		cout << "Diameter: " << ptr->Diameter << endl;
		cout << "Weight: " << ptr->Weight << endl;
		delete ptr;
		cin.get();
		cout << "Press any key to begin;Press q to quit:";
	}
	cout << "The end." << endl;
	return 0;
}
//9
using namespace std;
struct Candybar {
	string Branch;
	double weight;
	int calories;
};
int main()
{
	int candynum;
	cout << "Enter the number of candy you want to deal with:";
	cin >> candynum;
	cin.get();/*Deal with the '\n'*/
	Candybar* ps = new Candybar[candynum];
	for (int i = 0; i < candynum; i++)
	{
		cout << "Provide the branch of candy " << i + 1 << " :";
		getline(cin, ps[i].Branch);
		cout << "Provide the weight of candy " << i + 1 << " :";
		cin >> ps[i].weight;
		cin.get();/*Deal with the '\n'*/
		cout << "Provide the calories of candy " << i + 1 << " :";
		cin >> ps[i].calories;
		cin.get();/*Deal with the '\n'*/
	}
	for (int i = 0; i < candynum; i++)
	{
		cout << "The branch of candy"
			<< i + 1 << ": " << ps[i].Branch << endl;
		cout << "The weight of candy"
			<< i + 1 << ": " << ps[i].weight << endl;
		cout << "The contained calories of candy"
			<< i + 1 << ": " << ps[i].calories << endl;
	}
	delete[]ps;
	return 0;
}
//10
using namespace std;
const int race = 3;
int main()
{
	array <double, race>score;
	cout << "Please provide scores of three constant 40-yard race:" << endl;
	for (int i = 0; i < race; i++)
	{
		cout << "Number " << i + 1 << ":";
		cin >> score[i];
	}
	double sum = 0;
	for (int i = 0; i < race; i++)
	{
		sum += score[i];
	}
	double av = (sum) / race;
	cout << "The scores of three races is:" << endl;
	for (int i = 0; i < race; i++)
	{
		cout << "Number " << i + 1 << ":";
		cout << score[i] << endl;
	}
	cout << "The average of three scores is:" << av << endl;
	return 0;
}

