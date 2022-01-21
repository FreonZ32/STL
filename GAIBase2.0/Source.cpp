#include<iostream>
#include<list>
#include<string>
#include<sstream>
#include<map>
#include<iterator>
#include<Windows.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class NumberInfo
{
	bool Active;
	string Data;
	string Crime;
public:
	NumberInfo(string Data, string Crime, bool Active = true)
	{
		this->Data = Data;
		this->Data = Crime;
	}
	~NumberInfo() {}

	void print()
	{
		cout << "������: ";
		if (Active)cout << "�������;"; else cout << "��������";
		cout << " " << Data << ":" << Crime;
	}
};

string randData()
{
	string data;
	string month, year;
	stringstream dayss; dayss << (rand() % 30); dayss >> data;
	stringstream monthss; monthss << (rand() % 12); monthss >> month;
	stringstream yearss; yearss << (2000 + rand() % 22); yearss >> year;
	data.append("."); data.append(month); data.append("."); data.append(year); data.append(": ");
	return data;
}

void fill_map(map <string, list<NumberInfo>>& base, unsigned short int elements)
{
	for (unsigned short int i = 0; i < elements; i++)
	{
		string number(6, 0);
		for (int i = 0; i < 6; i++)
		{
			if (i == 0 || i > 3)number[i] = char(192 + rand() % 31);
			if (number[i] == '�' || number[i] == '�' || number[i] == '�' || number[i] == '�' || number[i] == '�' || number[i] == '�' || number[i] == '�' ||
				number[i] == '�' || number[i] == '�' || number[i] == '�' || number[i] == '�' || number[i] == '�' || number[i] == '�' || number[i] == '�' || number[i] == '�' ||
				number[i] == '�' || number[i] == '�' || number[i] == '�' || number[i] == '�') {
				i--;
			}
			else if (i > 0 && i < 4) number[i] = char(48 + rand() % 9);
		}
		list<NumberInfo> contravention;
		for (int i = 1 + rand() % 8; i > 0; i--)
		{
			stringstream kmphss; string kmph; kmphss << (100 + rand() % 120); kmphss >> kmph;
			string c1 = { "���������� �������� (���������� 100��/�) " };
			c1.append(kmph); c1.append("��/�");
			int k = rand() % 9;
			string dat = randData();
			switch (k)
			{
			case 0:contravention.push_back(NumberInfo(dat,c1)); break;
			case 1:contravention.push_back(NumberInfo(dat,"������ �� ����������� ���� ���������")); break;
			case 2:contravention.push_back(NumberInfo(dat,"����������� ��������")); break;
			case 3:contravention.push_back(NumberInfo(dat,"����� � ���������� ������� ��� �������. �� ������ �����, ������� \"�� �� �������\".")); break;
			case 4:contravention.push_back(NumberInfo(dat,"��������� � ����������� �����")); break;
			case 5:contravention.push_back(NumberInfo(dat,"��������� ������ ���������� ������ ������������")); break;
			case 6:contravention.push_back(NumberInfo(dat,"��������� ������ ��������������")); break;
			case 7:contravention.push_back(NumberInfo(dat,"���������� �� ���������� � ������")); break;
			case 8:contravention.push_back(NumberInfo(dat, "��� ���������� � ��������� ��������� �� ������, ������� �������")); break;
			default:break;
			}
		}
		base.insert(pair<string, list<NumberInfo>>(number, contravention));
	}
}

void print_all_map(map <string, list<NumberInfo>>& base)
{
	for (map<string, list<NumberInfo>>::iterator it = base.begin(); it != base.end(); ++it)
	{
		cout << it->first << endl;
		for (NumberInfo i : it->second) 
		{
			i.print(); cout << endl;
		}
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
	cout << "������� ��������� ������ ��������?: "; cin >> number;
	fill_map(Base, number);
	print_all_map(Base);
}