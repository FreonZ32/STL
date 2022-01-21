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

void fill_map(map <string, list<string>>& base, unsigned short int elements)
{
	for (unsigned short int i = 0; i < elements; i++)
	{
		string number(6, 0);
		for (int i = 0; i < 6; i++)
		{
			if (i == 0 || i > 3)number[i] = char(192 + rand() % 31);
			if (i > 0 && i < 4) number[i] = char(48 + rand() % 9);
		}
		list<string> contravention;
		for (int i = 1 + rand() % 8; i > 0; i--)
		{
			stringstream kmphss; string kmph; kmphss << (100 + rand() % 120); kmphss >> kmph;
			string c1 = { "���������� �������� (���������� 100��/�) " };
			c1.append(kmph); c1.append("��/�");
			int k = rand() % 9;
			switch (k)
			{
			case 0:contravention.push_back(c1); break;
			case 1:contravention.push_back("������ �� ����������� ���� ���������"); break;
			case 2:contravention.push_back("����������� ��������"); break;
			case 3:contravention.push_back("����� � ���������� ������� ��� �������. �� ������ �����, ������� \"�� �� �������\"."); break;
			case 4:contravention.push_back("��������� � ����������� �����"); break;
			case 5:contravention.push_back("��������� ������ ���������� ������ ������������"); break;
			case 6:contravention.push_back("��������� ������ ��������������"); break;
			case 7:contravention.push_back("���������� �� ���������� � ������"); break;
			case 8:contravention.push_back("��� ���������� � ��������� ��������� �� ������, ������� �������"); break;
			default:break;
			}
		}
		for (list<string>::iterator it = contravention.begin(); it != contravention.end(); ++it)
		{
			string rData = randData(); it->insert(0, rData);
		}
		base.insert(pair<string, list<string>>(number, contravention));
	}
}

void insert_new(map <string, list<string>>& base, string num, string contravention)
{
	cout << num << endl;
	map<string, list<string>>::iterator it = base.find(num);
	if (it != base.end())
	{it->second.push_back(contravention);}
	else 
	{
		list<string> second;
		second.emplace_front(contravention);
		base.emplace(num, second);
	}
}

void print_all_map(map <string, list<string>>& base)
{
	for (map<string,list<string>>::iterator it = base.begin(); it != base.end(); ++it)
	{
		cout << it->first << endl;
		for (string it2 : it->second)cout << "  " << it2 << ";" << endl;
	}
	cout << endl;
}

void print_info_number(map <string, list<string>>& base, string& number)
{
	map<string, list<string>>::iterator it = base.find(number);
	if (it != base.end())
	{
		cout << it->first << ":\t";
		for (string it2 : it->second)cout << it2 << ",";
		cout << "\b;" << endl;
	}
	else cout << "������� ������ �� ������� � ����! " << endl;
	cout << endl;
}

#define GAI

void main()
{
	setlocale(LC_ALL,"Russian");
#ifdef GAI
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	map <string, list<string>>Base;
	int number = 0;
	cout << "������� ��������� ������ ��������?: "; cin >> number;
	fill_map(Base, number);
	print_all_map(Base);
	string num;
	cout << "����� ����� ������ �����������?: "; cin >> num;
	print_info_number(Base, num);
	cout << "������� �����: "; cin >> num;
	string contravention;
	cin.get();	//�atch Enter after num cin;
	cout << "������� �������������� � ������� (����: ��������������): "; getline(cin, contravention);
	insert_new(Base, num, contravention);
	print_all_map(Base);
#endif // GAI


}