#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <vector>
using namespace std;

int from_file1(string, vector<string>&, int);

int find_file(vector<string>& s)
{

	WIN32_FIND_DATAA findData;
	HANDLE hfind;
	string a;
	cout << "¬ведите путь: ";
	cin >> a;
	string b = a + "\\*.csv";

	hfind = FindFirstFileA(b.c_str(), &findData);
	int n0 = 0;
	if (hfind == INVALID_HANDLE_VALUE) cout << "ќшибка!" << endl;
	else
	{
		do
		{
			string fname = findData.cFileName;
			n0 = from_file1(a + "\\" + fname, s, n0);
		} while (FindNextFileA(hfind, &findData));
	}
	FindClose(hfind);
	return n0;
}

int from_file1(string fname, vector<string>& s, int n0)
{
	ifstream file(fname);
	int n; (file >> n).get();
	s.resize(n0 + n);
	for (int i = n0; i < n + n0; i++)
		getline(file, s[i]);
	file.close();
	return n0 + n;
}

void fill(vector <string>& s, string* name, long int* marks, int n)
{
	for (int i = 0; i < n; i++)
	{
		size_t p1, p2 = 0;
		s[i].push_back(',');
		p1 = s[i].find(',', p2);
		name[i] = s[i].substr(p2, p1 - p2);
		p2 = p1 + 1; p1 = s[i].find(',', p2);

		long int sum = 0;
		while (p1 != string::npos)
		{
			sum += stol(s[i].substr(p2, p1 - p2), 0, 10);
			p2 = p1 + 1;
			p1 = s[i].find(',', p2);
		}
		marks[i] = sum;
	}
}

void sort(string* name, long int* marks, int n)
{
	int max; string s;
	for (int i = 0; i < n - 1; i++)
	{
		max = marks[i]; s = name[i];
		for (int j = i + 1; j < n; j++)
		{
			if (max < marks[j])
			{
				max = marks[j]; marks[j] = marks[i]; marks[i] = max;
				s = name[j]; name[j] = name[i]; name[i] = s;
			}
		}
	}
}

void output(string* name, long int* marks, int n)
{
	string p;
	cout << "¬ведите путь дл€ сохранени€ результата: ";
	cin >> p;
	p += "\\results.csv";
	cout << p;
	ofstream file(p);
	for (int i = 0; i < n; i++)
	{
		file << name[i] << ',' << marks[i] << endl;
	}
	file.close();
}