#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <string>
#include <windows.h>
#include "Human.h"
#include "Student.h"
#include "Professor.h"
#include "Function.h"
#include <fstream>
#include <algorithm>
#include "laba2-3-sem.h"

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool exit = false;
	int inp;
	Student* stud = new class Student[MAX_SIZE];
	Professor* prof = new class Professor[MAX_SIZE];
	stud->SetCount(1);
	prof->SetCount(0);


	Student *studs = new class Student[2];
	Human *hum = new class  Human[2];
	vector<Human*> ages;
	ages.push_back(&studs[0]);
	ages.push_back(&hum[0]);
	ages.push_back(&studs[1]);
	studs[1].setAge(22);
	ages.push_back(&hum[1]);
	hum[1].setAge(21);
	/*vector<Human*>::iterator  ir;
	for (ir = ages.begin(); ir != ages.end(); ++ir)
	{
		if (dynamic_cast<Student*>(*ir))
			(*ir)->Display();
	}*/
	for(int i = 0; i < ages.size(); ++i)
	{
		if (dynamic_cast<Student*>(ages[i]))
			ages[i]->Display();
	}
	_getch();
	system("cls");
	sort(ages.begin(), ages.end(), [](Human* hum, Human* hum1)
		{
			return  hum[0].getAge() < hum1[0].getAge();
		});
	for (int i = 0; i < ages.size(); ++i)
	{
		ages[i]->Display();
	}
	_getch();
	system("cls");
	auto res = find_if(ages.begin(), ages.end(), [](Human* hum) {
		return hum[0].getAge() >= 18;
		});
	if (res != ages.end())
	{
		cout << "Да, есть человек, чей возраст >= " + to_string(18) << endl;
	}
	else
	{
		cout << "Нет человека, чей возраст >= " + to_string(18) << endl;
	}
	_getch();
	do {
		print_choise();
		inp = write_num(9);
		if (inp == 9)
			exit = true;
		else
			act_choise(inp, stud, prof);

	} while (!exit);
	delete[] stud, prof;
	delete studs;
}
