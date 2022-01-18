#include<iostream>
#include<Windows.h>
#include<array>
#include<vector>
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
		SetConsoleTextAttribute(hConsoleHandle, 15);
		return true;
	}
	else return false;
}
template<typename T>
void vec_print(vector<T>& vec)
{
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
void vec_info(vector<T>& vec)
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
void vec_erase(vector<T>& vec, unsigned short int position)
{
	if (Achtung(vec.size()-1, position))return;
	vec.erase(vec.begin() + position);
}

//#define STL_ARRAY
#define STL_VECTOR

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
	vector<double> vec = { 0,1,1,2,3,5,8,13,21,34,55,89,144,232 };
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
	unsigned short int position;
	double value;
	cout << "Enter the insertion position " << "(form 0 for " << vec.size() << "):"; cin >> position;
	cout << "Enter the value to insert: "; cin >> value;
	vec_insetr(vec, position, value);
	vec_info(vec);
	vec_print(vec);
	cout << "Enter the deletion position " << "(form 0 for " << vec.size()-1 << "):" ; cin >> position;
	vec_erase(vec, position);
	vec_info(vec);
	vec_print(vec);
#endif // STL_VECTOR

}