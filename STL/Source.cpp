#include<iostream>
#include<Windows.h>
#include<array>
#include<vector>
#include<deque>
#include<stack>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

bool Achtung(int size, unsigned short int position)
{
	if (position > size)
	{
		HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsoleHandle, 4);
		cout << "ERROR: " << "Going beyond the vector limit! " << endl;
		SetConsoleTextAttribute(hConsoleHandle, 7);
		return true;
	}
	else return false;
}
template<typename T>
void vec_print(vector<T>& vec)
{
	/*for (typename vector<T>::const_iterator it = vec.begin(); it != vec.end(); it++)cout << *it << endl;*/
	cout << "Pos\t" << "AllVal\t\t" << "Val" << endl;
	T* data = vec.data();
	for (int i = 0; i <= vec.capacity(); i++)
	{
		cout << i << ":\t" << *(data + i);
		if (i < vec.size())cout << "\t\t" << vec[i];
		cout << endl;
	}
}

template<typename T>
void vec_info(const vector<T>& vec)
{
	cout << "Size: " << vec.size() << endl;
	cout << "Capasity: " << vec.capacity() << endl;
	cout << "MaxSize: " << vec.max_size() << endl;
}

template<typename T>
void vec_insetr(vector<T>& vec, unsigned short int position, T value )
{
	if (Achtung(vec.size(), position))return;
	vec.insert(vec.begin() + position, value);
}

template<typename T>
void vec_insetr_count(vector<T>& vec, unsigned short int position, unsigned short int count, T value)
{
	if (Achtung(vec.size(), position))return;
	vec.insert(vec.begin() + position,count, value);
}

template<typename T>
void vec_erase(vector<T>& vec, unsigned short int position)
{
	if (Achtung(vec.size()-1, position))return;
	vec.erase(vec.begin() + position);
}

//#define STL_ARRAY
//#define STL_VECTOR
//#define STL_DEQUE

void main()
{
	setlocale(LC_ALL, "rus");
#ifdef STL_ARRAY
	array<int, 5> arr = { 3,5,8,13,21 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
#endif // STL_ARRAY

#ifdef STL_VECTOR
	vector<int> vec = { 0,1,1,2,3,5,8,13,21,34,55,89,144,232 };
	vec_info(vec);
	vec_print(vec);

	//int* data = vec.data();
	//try
	//{
	//	for (int i = 0; i < vec.capacity()-5; i++)
	//	{
	//		//cout << vec[i] << endl;
	//		cout << *(data + i) << endl;
	//		//cout << &vec.at(i)<< vec.at(i)<< endl;
	//	}cout << endl;
	//}
	//catch (const std::exception& e)
	//{
	//	cerr << e.what() << endl;
	//}
	unsigned short int position, count;
	int value;
	cout << "Enter the insertion position " << "(form 0 for " << vec.size() << "):"; cin >> position;
	cout << "Enter the value to insert: "; cin >> value;
	vec_insetr(vec, position, value);
	vec_info(vec);
	vec_print(vec);

	cout << "Enter the insertion position " << "(form 0 for " << vec.size() << "):"; cin >> position;
	cout << "Enter the value to insert: "; cin >> value;
	cout << "Âkeep the number of repetitions when inserting: "; cin >> count;
	vec_insetr_count(vec, position,count,value);
	vec_info(vec);
	vec_print(vec);

	cout << "Enter the deletion position " << "(form 0 for " << vec.size()-1 << "):" ; cin >> position;
	vec_erase(vec, position);
	vec_info(vec);
	vec_print(vec);

	vector<int> powers = { 1024,2048,4096,8191,16384 };
	//vec.insert(vec.begin() + 3, powers.begin(), powers.end());
	//vec_info(vec);
	//for (int i : vec)cout << i << endl;
	////vec_print(vec);
	//vec.insert(vec.begin() + 3, {256,384,512,768});
	//vec_info(vec);
	//for (int i : vec)cout << i << endl;
#endif // STL_VECTOR

#ifdef STL_DEQUE
	deque<int> dec = { 0,1,1,2,3,5,8,13,21,34,55,89,144,232 };
	cout << sizeof(dec) << endl;
	dec.push_back(34);
	for (int i = 0; i < dec.size(); i++)cout << dec[i] << endl;
	cout << endl;
	deque<int> dec2 = { 0,1,1 };
	for (int i = 0; i < dec.size(); i++)cout << dec[i] << endl;
	cout << endl;
	for (int i = 0; i < dec2.size(); i++)cout << dec2[i] << endl;
#endif // STL_DEQUE

	stack<int> stack;
	cout << sizeof(stack) << endl;
}