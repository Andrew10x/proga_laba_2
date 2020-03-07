#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
void from_file(string*, ifstream&, ifstream&, int, int);  //считывание из файла


int main()
{
	setlocale(LC_ALL, "russian");
	ifstream file1("eurovision1.csv");
	ifstream file2("eurovision2.csv");

	if (file1.is_open() && file2.is_open())
	{int n1, n2;   //колличество элементов в файле
	(file1 >> n1).get(); (file2 >> n2).get();
	string* s = new string[n1+n2];
	from_file(s, file1, file2, n1, n2);
	}
	else cout << "Файл не открыт";
	
}

void from_file(string* s, ifstream& file1, ifstream& file2, int n1, int n2)
{
	for (int i = 0; i<n1; i++)
		getline(file1, s[i]);

	for (int i = n1; i < n1 + n2; i++)
		getline(file2, s[i]); 
}

