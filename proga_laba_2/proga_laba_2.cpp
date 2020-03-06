#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;


int main()
{
	ifstream file1("eurovision1.csv");
	ifstream file2("eurovision2.csv");
	int n1, n2;  //колличество элементов в файле
	file1 >> n1; file2 >> n2;
	string* s1 = new string[n1];
	string* s2 = new string[n2];
}

