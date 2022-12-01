#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Student.h"
#include "Professor.h"
#include "Function.h"

int write_num(int size) 
{
	int inp = 0;
	do {
		while (scanf("%d", &inp) != 1) {
			while (getchar() != '\n');
			cout << "������. ������� �����: ";
		}
		if (inp < 1 || inp > size)
			cout << "������� ������������ �����, ������� ��� ���: ";
	} while (inp < 1 || inp > size);
	while (getchar() != '\n');
	return inp;
}

string write_str(int size)
{
	bool correct;
	//char word[30];
	string word;
	do {
		correct = true;
		cin >> word;
		int word_len = word.length();
		if (word_len > size) {
			cout << "������ ������� �������!\n������� ��� ���: ";
			continue;
		}
		for (int i = 0; i < word_len; i++)
		{
			if (!isalpha((unsigned char)word[i]))
			{
				correct = false;
				cout << "������ ������ �������� ������ �� ����!\n������� ��� ���: ";
				break;
			}
		}
	} while (!correct);
	return word;
}

string write_pd(int size)
{
	bool correct;
	string word;
	do {
		correct = true;
		cin >> word;
		int word_len = word.length();
		if (word_len != size){
			cout << "������ �� ������������ ����������!\n������� ��� ���: ";
			correct = false;
		}
		else
			for (int i = 0; i < word_len; i++)
			{
				if (!isdigit(word[i]))
				{
					correct = false;
					while (getchar() != '\n');
					cout << "������ ������ �������� ������ �� ����!\n������� ��� ���: ";
					break;
				}
			}
	} while (!correct);
	return word;
}

void print_choise()
{
	system("cls");
	cout << "�������� ��������:" << endl;
	cout << "1. ������ ������ � ��������" << endl;
	cout << "2. ������ ������ � �������������" << endl;
	cout << "3. ������� ������ � ���������" << endl;
	cout << "4. ������� ������ � ��������������" << endl;
	cout << "5. ������ ���������� � ���������" << endl;
	cout << "6. ������ ���������� � ��������������" << endl;
	cout << "7. �������� ������ � ���������" << endl;
	cout << "8. �������� ������ � ������������" << endl;
	cout << "9. ��������� ������." << endl;
}

void stud_info(int sum_ages, int count_st, int sum_scholarship, int max_scholarship, int min_scholarship)
{
	cout << "���������� � ���������: \n" << endl;;
	cout << "---------------------------------" << endl;
	cout << "������� ������� ��������: " + to_string(sum_ages / count_st) << endl;
	cout << "������� ��������� ��������: " + to_string(sum_scholarship / count_st) << endl;
	cout << "������������ ��������� ��������: " + to_string(max_scholarship) << endl;
	cout << "����������� ��������� ��������: " + to_string(min_scholarship) << endl;
	cout << "---------------------------------" << endl;
}

void prof_info(int sum_ages, int count_pr, int sum_wage, int max_wage, int min_wage, int sum_exp)
{
	cout << "���������� � ���������: \n" << endl;;
	cout << "---------------------------------" << endl;
	cout << "������� ������� �������������: " + to_string(sum_ages / count_pr) << endl;
	cout << "������� �������� �������������: " + to_string(sum_wage / count_pr) << endl;
	cout << "������� ���� �������������: " +  to_string(sum_exp / count_pr) << endl;
	cout << "������������ ��������: " + to_string(max_wage) << endl;
	cout << "����������� ��������: " + to_string(min_wage) << endl;
	cout << "---------------------------------" << endl;
}

void act_choise(int inp, class Student *stud, class Professor *prof)
{
	int age = 0, scholar = 0, wg = 0, exp = 0; string num = "" ,ser = "", first = "", mid = "",
		last = "", gr = "",  sub = "";
	if (inp == 1)
	{
		InputStud(stud[stud->GetCount()]);
	}
	else if (inp == 2)
	{
		prof[prof->GetCount()].InputProf();
	}
	else if (inp == 3)
	{
		system("cls");
		if (stud->GetCount())
		{
			for (int i = 0; i < stud->GetCount(); i++)
			{
				stud[i].OutputStud(i);
			}
		}
		else
		{
			cout << "������ �� �������" << endl;
		}
		cout << "������� ����� �������, ����� ����������" << endl;
		_getch();
	}
	else if (inp == 4)
	{
		system("cls");
		if (prof->GetCount())
		{
			for (int i = 0; i < prof->GetCount(); i++)
			{
				prof[i].OutputProf(i);
			}
		}
		else
		{
			cout << "������ �� �������" << endl;
		}
		cout << "������� ����� �������, ����� ����������" << endl;
		_getch();
	}
	else if (inp == 5)
	{
		int stud_sum_age = 0, stud_sum_scholarship = 0,
			count_students = 0, max_scholarship = 0, min_scholarship = 0;
		if (stud->GetCount())
		{
			for (int i = 0; i < stud->GetCount(); i++)
			{
				stud[i].stud_analysis(&stud_sum_age, &stud_sum_scholarship,
				&count_students, &max_scholarship, &min_scholarship);
			}
			stud_info(stud_sum_age, count_students, 
				stud_sum_scholarship, max_scholarship, min_scholarship);
		}
		else
		{
			system("cls");
			cout << "������ �� �������" << endl;
		}
		cout << "������� ����� �������, ����� ����������";
		_getch();
	}
	else if (inp == 6)
	{
		int prof_sum_age = 0, prof_sum_wage = 0,
			count_professors = 0, max_wage = 0, min_wage = 0, sum_experience = 0;
		if (prof->GetCount())
		{
			for (int i = 0; i < prof->GetCount(); i++)
			{
				prof[i].prof_analysis(&prof_sum_age, &prof_sum_wage,
					&count_professors, &max_wage, &min_wage, &sum_experience);
			}
			prof_info(prof_sum_age, count_professors,
				prof_sum_wage, max_wage, min_wage, sum_experience);
		}
		else
		{
			system("cls");
			cout << "������ �� �������" << endl;
		}
		cout << "������� ����� �������, ����� ����������";
		_getch();
	}
	else if (inp == 7)
	{
		if (stud->GetCount())
		{
			int stud_num = 0;
			print_change_choise(stud, &stud_num);
			stud[stud_num-1].ChangeInfo();
		}
		else
		{
			cout << "������ �� �������" << endl;
			cout << "������� ����� �������, ����� ����������" << endl;
			_getch();
		}
	}
	else if (inp == 8)
	{
		if (prof->GetCount())
		{
			int prof_num = 0;
			print_change_choise_prof(prof, &prof_num);
			prof[prof_num - 1].ChangeInfo();
		}
		else
		{
			cout << "������ �� �������" << endl;
			cout << "������� ����� �������, ����� ����������" << endl;
			_getch();
		}
	}
}

void print_change_choise(class Student stud[], int *stud_num)
{
	system("cls");
	for (int i = 0; i < stud->GetCount(); i++)
	{
		stud[i].OutputStud(i);
	}
	cout << "�������� ����� ��������: ";
	*stud_num = write_num(stud->GetCount());
	system("cls");
	cout << "��������, ��� ����� ��������: " << endl;
	cout << "1. ���" << endl;
	cout << "2. ���������� ������" << endl;
	cout << "3. �������" << endl;
	cout << "4. ������" << endl;
	cout << "5. ������ ���������\n" << endl;
	cout << "6. ��������� �������" << endl;
}

void print_change_choise_prof(class Professor prof[], int *prof_num)
{
	system("cls");
	for (int i = 0; i < prof->GetCount(); i++)
	{
		prof[i].OutputProf(i);
	}
	cout << "�������� ����� ������������� : " << endl;
	*prof_num = write_num(prof->GetCount());
	system("cls");
	cout << "��������, ��� ����� ��������: " << endl;
	cout << "1. ���" << endl;
	cout << "2. ���������� ������" << endl;
	cout << "3. �������" << endl;
	cout << "4. �������" << endl;
	cout << "5. ������ ��������" << endl;
	cout << "6. ���� �������������\n" << endl;
	cout << "7. ��������� �������" << endl;
}

