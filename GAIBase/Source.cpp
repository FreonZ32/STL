#include<iostream>
#include<list>
#include<string>
#include<sstream>
#include<map>
#include<iterator>
#include<Windows.h>
#include<fstream>
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

int HMstr(const string& name) //Return number of strings on file
{
	int size = 0;
	ifstream fin(name);
	if (fin.is_open())
	{
		string str;
		while (getline(fin, str)) size++;
		fin.close();
	}
	else cerr << "File no found!" << endl;
	return size;
}

void fill_map(map <string, list<string>>& base, unsigned short int elements)
{
	for (unsigned short int i = 0; i < elements; i++)
	{
		string number(6, 0);
		for (int i = 0; i < 6; i++)
		{
			if (i == 0 || i > 3)number[i] = char(192 + rand() % 31);
			if (number[i] == 'Ъ' || number[i] == 'Й' || number[i] == 'Ц' || number[i] == 'Г' || number[i] == 'Ш' || number[i] == 'Щ' || number[i] == 'З'||
				number[i] == 'Ф'|| number[i] == 'Ы'|| number[i] == 'П'|| number[i] == 'Л'|| number[i] == 'Д'|| number[i] == 'Ж'|| number[i] == 'Э'|| number[i] == 'Я'||
				number[i] == 'Ч'|| number[i] == 'Ь'|| number[i] == 'Б'|| number[i] == 'Ю') { i--;}
			else if (i > 0 && i < 4) number[i] = char(48 + rand() % 9);
		}
		list<string> contravention;
		for (int i = 1 + rand() % 8; i > 0; i--)
		{
			stringstream kmphss; string kmph; kmphss << (100 + rand() % 120); kmphss >> kmph;
			string c1 = { "Превышение скорости (допустимая 100км/ч) " };
			c1.append(kmph); c1.append("км/ч");
			int k = rand() % 9;
			switch (k)
			{
			case 0:contravention.push_back(c1); break;
			case 1:contravention.push_back("Проезд на запрещающий цвет светофора"); break;
			case 2:contravention.push_back("Пересечение сплошной"); break;
			case 3:contravention.push_back("Украл у сотрудника свисток при осмотре. На вопрос зачем, ответил \"Це по приколу\"."); break;
			case 4:contravention.push_back("Остановка в запрещенном месте"); break;
			case 5:contravention.push_back("Нарушение правил применения ремней безопасности"); break;
			case 6:contravention.push_back("Нарушение правил маневрирования"); break;
			case 7:contravention.push_back("Набросился на инспектора с ложкой"); break;
			case 8:contravention.push_back("Был остановлен в нетрезвом состоянии на телеге, пытался сбежать"); break;
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
		for (string i : it->second)cout << "  " << i << ";" << endl;
	}
	cout << endl;
}

void print_to_file(map <string, list<string>>& base)
{
	ofstream WriteToFile("File.txt");
	for (map<string, list<string>>::iterator it = base.begin(); it != base.end(); ++it)
	{
		WriteToFile << it->first << endl;
		for (string i : it->second)WriteToFile << "  " << i << ";" << endl;
	}
	WriteToFile.close();
}

map <string, list<string>> read_from_file(map <string, list<string>>& base)
{
	ifstream ReadFromFile("File.txt");
	int size = HMstr("File.txt");
	string str, Number, Contravention;
	if (ReadFromFile.is_open())
	{
		for (int i = 0; i < size; i++)
		{
			string buffer;
			getline(ReadFromFile, str, '\n');
			int charNum = 256 + int(str[0]);
			if (charNum >= 192 && charNum <= 223) 
			{
				Number = str; 
				buffer = str;
			}
			else if(charNum == 288)
			{
				charNum = str.size();
				str.resize(charNum-1);
				Contravention = str;
			}
			if(i&&buffer!=Number)insert_new(base, Number, Contravention);
		}
	}
	ReadFromFile.close();
	return base;
}

void clear_file()
{
	ofstream ReadTheFile;
	ReadTheFile.open("File.txt", std::ofstream::out | std::ofstream::trunc);
	ReadTheFile.close();
}

void print_info_number(map <string, list<string>>& base, string& number)
{
	map<string, list<string>>::iterator it = base.find(number);
	if (it != base.end())
	{
		cout << it->first << endl;
		for (string i : it->second)cout << "  " << i << ";" << endl;
	}
	else cout << "Данного номера не найдено в базе! " << endl;
	cout << endl;
}

void find_crime_by_smth(map <string, list<string>>& base, string& str, string what)
{
	string rep;
	for (map<string, list<string>>::iterator it = base.begin(); it != base.end(); ++it)
	{
		for (string i : it->second)
		{
			if (what == "Data")
			{
				if (i.compare(0, i.find_first_of(":"), str) == 0)
				{
					if(!it->first.compare(rep) == 0)
					{rep = it->first; cout << it->first << endl;}
					cout << "  " << i << ";" << endl;
				}
			}
			if (what == "Crime")
			{
				if (i.compare(i.find_first_of(":") + 2, i.size(), str) == 0)
				{
					if (!it->first.compare(rep) == 0)
					{rep = it->first; cout << it->first << endl;}
					cout << "  " << i << ";" << endl;
				}
			}
		}
	}
}


//#define GAI_CR_AND_FUNC
//#define WRITE_TO_FILE
#define READ_FILE

void main()
{
	setlocale(LC_ALL,"Russian");
#ifdef  GAI_CR_AND_FUNC
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	map <string, list<string>>Base;
	int number = 0;
	cout << "Сколько элементов хотите вставить?: "; cin >> number;
	fill_map(Base, number);
	print_all_map(Base);
	string num;
	cout << "Какой номер хотите распечатать?: "; cin >> num;
	print_info_number(Base, num);
	cout << "Введите номер: "; cin >> num;
	string contravention;
	cin.get();	//Сatch Enter after num cin;
	//cin.ignore();
	//fflush(stdin);
	cout << "Введите правонарушение в формате (дата: Правонарушение): "; getline(cin, contravention);
	insert_new(Base, num, contravention);
	print_all_map(Base);

	string smth;
	//cin.get();
	cout << "Введите дату по которой будет проведен поиск(в формате дд.мм.гггг): "; getline(cin, smth);
	find_crime_by_smth(Base,smth,"Data");
	//cin.get();
	cout << "Введите нарушение по которому будет проведен поиск: "; getline(cin, smth);
	find_crime_by_smth(Base, smth,"Crime");
#endif //  GAI_CR_AND_FUNC

#ifdef WRITE_TO_FILE
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	map <string, list<string>>Base;
	int number = 0;
	cout << "Сколько элементов хотите вставить?: "; cin >> number;
	fill_map(Base, number);
	print_all_map(Base);
	print_to_file(Base);
	system("start notepad File.txt");
#endif // WRITE_TO_FILE


#ifdef READ_FILE
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("start notepad File.txt");
	map <string, list<string>>Base;
	read_from_file(Base);
	print_all_map(Base);
#endif // READ_FILE

}