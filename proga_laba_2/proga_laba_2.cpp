#include "proga_laba_2.h";

int main()
{
	setlocale(LC_ALL, "russian");
	vector<string> s;
	int n = find_file(s);
	string* name = new string[n];
	long int* marks = new long int[n];
	string* t = new string[n];
	fill(s, name, marks, n);
	sort(name, marks, n);
	output(name, marks, 10);
}

