#include<iostream>
#include<iterator>
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

void ErrorCout(string what)
{
	HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleHandle, 4);
	cout << "ERROR: Wrong " << what << "!" << endl;
	SetConsoleTextAttribute(hConsoleHandle, 7);
}

bool DataCrimrOut(int year, int month, int day)
{
	time_t rawtime; struct tm* timeinfo; time(&rawtime); timeinfo = localtime(&rawtime);
	if (year <= timeinfo->tm_year+1900-20)return false;
	else return true;
}
class TimeData
{
	unsigned short int year;
	unsigned short int month;
	unsigned short int day;
public:
	void set_year(int year)
	{
		if(year < 1900||year > 3000)
		{ErrorCout("year"); this->year = 1900;}
		this->year = unsigned short int(year);
	}
	void set_month(int month)
	{
		if (month > 12 || month == 0)
		{ErrorCout("month"); this->month = 1;}
		this->month = unsigned short int(month);
	}
	void set_day(int day)
	{
		if (day > 31 || day == 0)
		{ErrorCout("day"); this->day = 1;}
		this->day = unsigned short int(day);
	}
	unsigned short int get_year()const { return year; }
	unsigned short int get_month()const { return month; }
	unsigned short int get_day()const { return day; }

	TimeData(int year  = 1900,int month = 1,int day = 1)
	{
		time_t rawtime;struct tm* timeinfo;time(&rawtime);timeinfo = localtime(&rawtime);
		set_year(year);
		set_month(month);
		set_day(day);
		cout << "sssss";
	}
	TimeData(const TimeData& other)
	{
		*this = other;
	}
	~TimeData(){}
	TimeData& operator=(const TimeData& other)
	{
		if (this == &other)return *this;
		this->~TimeData();
		this->year = other.year;
		this->month = other.month;
		this->day = other.day;
		return*this;
	}
	void print()const
	{
		cout << year << "." << month << "." << day << ":";
	}
};
ostream& operator<<(ostream& os, const TimeData& obj)
	{
		return os << obj.get_year() << "."<< obj.get_month()<<"."<<obj.get_day() << ":";
	}

class NumberInfo
{
	bool Active;
	TimeData Time;
	string Crime;
public:
	NumberInfo(string Crime, int year, int month, int day, bool Active = true)
	{
		this->Active = Active;
		this->Time = TimeData(year, month, day);
		this->Crime = Crime;
	}
	~NumberInfo(){}

	void print()const
	{
		HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		if (Active)
		{SetConsoleTextAttribute(hConsoleHandle, 2); cout << "  " << Time << "\t" << Crime << endl; }
		else
		{SetConsoleTextAttribute(hConsoleHandle, 8); cout << "  " << Time << "\t" << Crime << endl; }
		SetConsoleTextAttribute(hConsoleHandle, 7);
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
			int year = 1990 + rand()%32;
			int mon = 1 + rand() % 12; 
			int day = 1+rand()%30;
			unsigned short int NumbOfCrime = rand() % 4;
			switch (NumbOfCrime)
			{
				case 1:Crimes.push_back(NumberInfo("Проезд на запрещающий цвет светофора",year, mon, day,DataCrimrOut(year, mon, day))); break;
				case 2:Crimes.push_back(NumberInfo("Пересечение сплошной", year, mon, day, DataCrimrOut(year, mon, day))); break;
				case 3:Crimes.push_back(NumberInfo("Остановка в запрещенном месте", year, mon, day, DataCrimrOut(year, mon, day))); break;
				case 4:Crimes.push_back(NumberInfo("Нарушение правил применения ремней безопасности", year, mon, day, DataCrimrOut(year, mon, day))); break;
				case 5:Crimes.push_back(NumberInfo("Нарушение правил маневрирования", year, mon, day, DataCrimrOut(year, mon, day))); break;
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
	/*SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	map <string, list<NumberInfo>>Base;
	int number = 0;
	cout << "Сколько элементов хотите вставить?: "; cin >> number;
	fill_map(Base, number);
	print_all_map(Base);*/

}