#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <vector>
using namespace std;
int find_file(vector <string>&); //нахождение файла
int from_file1(string, vector<string>&, int); //считывание из файла
void fill(vector<string>&, string*, long int*, int); //заполнение массивов считанными данными
void sort(string*, long int*, int); //сортировка по убыванию
void output(string*, long int*, int); //вывод в файл
