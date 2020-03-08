#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
void from_file(string*, ifstream&, ifstream&, int, int);  //считывание из файла
void fill(string*, string*, long int*, int); //заполнение массивов считанными данными


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
	
	int n = n1 + n2;
	string* name = new string[n];
	long int* marks = new long int[n];
	fill(s, name, marks, n);
	
	}
	else cout << "Файл не открыт";
	
}

void from_file(string* s, ifstream& file1, ifstream& file2, int n1, int n2)
{
	for (int i = 0; i<n1; i++)
		getline(file1, s[i]);

	for (int i = n1; i < n1 + n2; i++)
		getline(file2, s[i]); 
	file1.close(); file2.close();
}

void fill(string* s, string* name, long int* marks, int n)
{
	
	for (int i = 0; i < n; i++)
	{
		size_t p1, p2 = 0;
		s[i].push_back(',');
		p1 = s[i].find(',', p2);
		name[i] = s[i].substr(p2, p1-p2);
		p2 = p1 + 1; p1 = s[i].find(',', p2);

		long int sum = 0;
		while(p1!= string ::npos)
		{	
			sum += stol(s[i].substr(p2, p1-p2),0,10);
			p2 = p1 + 1;
			p1 = s[i].find(',', p2);	
		}
		marks[i] = sum;
	}
}

