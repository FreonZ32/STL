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
	NumberInfo(string Data, string Crime, bool Active = true) :Data(Data), Crime(Crime)
	{
		this->Data = Data;
		this->Data = Crime;
	}
	~NumberInfo() {}
};