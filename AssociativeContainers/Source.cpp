#include<iostream>
#include<set>
#include<map>
#include<string>
#include<list>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

//#define SET
//#define MAP

void main()
{
	setlocale(LC_ALL, "rus");
#ifdef SET
	std::multiset<int> set1 = { 50,25,75,16,32,64,80,16,64,50,25,88 };
	for (std::multiset<int>::iterator it = set1.begin(); it != set1.end(); it++)cout << *it << endl;
	cout << endl;
	cout << set1.size() << endl;
	cout << set1.max_size() << endl;
	//for (std::multiset<int>::reverse_iterator it = set1.rbegin(); it != set1.rend(); it++)cout << *it << endl;
	int value;
	//cout << "Введите значение: "; cin >> value;
	set1.insert({ 3,5,8,13,21,34,55,89 });
	for (int i : set1)cout << i << endl;
	cout << "Введите удаляемое значение: "; cin >> value;
	set1.erase(value);
	for (int i : set1)cout << i << endl;
#endif // SET

#ifdef MAP
	std::map<int, std::string> week =
	{
		pair<int, std::string>(0,"Sunday"),
		pair<int, std::string>(1,"Monday"),
		pair<int, std::string>(2,"Tewsday"),
		pair<int, std::string>(4,"Wensday"),
		pair<int, std::string>(5,"Thursday"),
		pair<int, std::string>(5,"Fridey"),
		pair<int, std::string>(6,"Sartuday"),
		pair<int, std::string>(1,"Sunday"),
		pair<int, std::string>(1,"Monday"),
	};
	for (std::multimap<int, std::string>::iterator it = week.begin(); it != week.end(); ++it)
	{
		cout << it->first << "\t" << it->second << endl;
	}
#endif // MAP

	std::map<std::string, std::list<std::string>> dictionary =
	{
		pair<std::string, std::list<std::string>>("buddy", std::list<std::string>{ "дружище","приятель" }),
		pair<std::string, std::list<std::string>>("keen", std::list<std::string>{"острый","чувствительный","проницательный"}),
		pair<std::string, std::list<std::string>>("wage", std::list<std::string>{"зарплата"}),
		pair<std::string, std::list<std::string>>("mutual", std::list<std::string>{"взаимный","обоюдный","соответственный"}),
		pair<std::string, std::list<std::string>>("space", std::list<std::string>{"космос","пространство"})
	};
	for (std::multimap<std::string, std::list<std::string>>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		cout << it->first<< ":\t";
		for(string it2 : it->second)cout << it2 << ",";
		cout << "\b;" << endl;
	}
}