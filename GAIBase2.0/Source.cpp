#include<iostream>
#include<string>
#include<map>
#include<list>
#include<string.h>
#include<Windows.h>
#include<time.h> 
#pragma warning(disable : 4996)
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class NumberInfo
{
	bool Active;
	time_t rawtime;
	struct tm* timeinfo;
	string Crime;

public:
	NumberInfo(string Crime, int year, int mon, int day, bool Active = true)
	{
		time(&rawtime);
		this->timeinfo = localtime(&rawtime);
		this->timeinfo->tm_year = year;
		this->timeinfo->tm_mon = mon;
		this->timeinfo->tm_mday = day;
		this->Crime = Crime;
	}
	~NumberInfo(){}

	void print()
	{
		char time[20];
		strftime(time,20,"%m/%d/%y:", timeinfo);
		cout << time << " " << Crime << endl;
	}
};

void fill_map(map <string, list<NumberInfo>>& base, unsigned short int elements)
{
	for (unsigned short int i = 0; i < elements; i++)
	{
		string number(6, 0);
		for (int i = 0; i < 6; i++)
		{
			if (i == 0 || i > 3)
			{
				number[i] = char(192 + rand() % 31);
				string key = "ЪЙЦГШЩЗФЫПЛДЖЭЯЧЬБЮ";
				for (int k = 0; k < key.size(); k++) { if (number.compare(i, 1, key, k, 1) == 0) { i--; break; } }
			}
			else if (i > 0 && i < 4) number[i] = char(48 + rand() % 9);
		}
		list<NumberInfo> Crimes;
		for (int i = 1; i < 9; i++)
		{
			int year = 1900 + rand()%120;
			int mon = 1 + rand() % 12; 
			int day = 1+rand()%30;
			unsigned short int NumbOfCrime = rand() % 4;
			switch (NumbOfCrime)
			{
				case 1:Crimes.push_back(NumberInfo("Проезд на запрещающий цвет светофора",year, mon, day)); break;
				case 2:Crimes.push_back(NumberInfo("Пересечение сплошной", year, mon, day)); break;
				case 3:Crimes.push_back(NumberInfo("Остановка в запрещенном месте", year, mon, day)); break;
				case 4:Crimes.push_back(NumberInfo("Нарушение правил применения ремней безопасности", year, mon, day)); break;
				case 5:Crimes.push_back(NumberInfo("Нарушение правил маневрирования", year, mon, day)); break;
				default:break;
			}
		}
		base.insert(pair<string, list<NumberInfo>>(number,Crimes));
	}
}

void print_all_map(map <string, list<NumberInfo>>& base)
{
	for (map<string, list<NumberInfo>>::iterator it = base.begin(); it != base.end(); ++it)
	{
		cout << it->first << endl;
		for (NumberInfo i : it->second)i.print();
	}
	cout << endl;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	map <string, list<NumberInfo>>Base;
	int number = 0;
	cout << "Сколько элементов хотите вставить?: "; cin >> number;
	fill_map(Base, number);
	print_all_map(Base);
}