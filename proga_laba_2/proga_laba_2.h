#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <vector>
using namespace std;
int find_file(vector <string>&); //���������� �����
int from_file1(string, vector<string>&, int); //���������� �� �����
void fill(vector<string>&, string*, long int*, int); //���������� �������� ���������� �������
void sort(string*, long int*, int); //���������� �� ��������
void output(string*, long int*, int); //����� � ����
