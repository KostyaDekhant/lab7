#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100
#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Student.h"
#include "Function.h"
#include <fstream>


int Student::count_stud = 0;

Student::Student()
{
	Human initHuman;
	this->setFIO(initHuman.getFIO().getFirst(), initHuman.getFIO().getMid(), initHuman.getFIO().getLast());
	this->setAge(initHuman.getAge());
	this->scholarship = 10000;
	this->group = "��11";
	count_stud++;
}
Student::Student(int scholarship)
{
	Human initHuman;
	this->setFIO(initHuman.getFIO().getFirst(), initHuman.getFIO().getMid(), initHuman.getFIO().getLast());
	this->setPD("1203","344894");
	this->setAge(initHuman.getAge());
	this->scholarship = 10000;
	this->group = "��11";
	count_stud++;
}
Student::Student(class Human human, int scholarship, string group)
{
	this->setFIO(human.getFIO().getFirst(), human.getFIO().getMid(), human.getFIO().getLast());
	this->setPD("1203", "344894");
	this->setAge(human.getAge());
	this->scholarship = scholarship;
	this->group = group;
	count_stud++;
}
Student::~Student()
{

}

void Student::addRating(int rt)
{
	this->rating.push_back(rt);
}


void operator<<(ostream&, Student st)
{
	cout << "---------------------------------" << endl;
	cout << "���: " + st.getFIO().getLast() + " " + st.getFIO().getFirst() + " " + st.getFIO().getMid() << endl;
	cout << "���������� ������: " + st.getPD().getNum() + " " + st.getPD().getSer() << endl;
	cout << "�������: " + to_string(st.getAge()) << endl;
	cout << "������� ������: " + st.group << endl;
	cout << "���������: " + to_string(st.scholarship) << endl;
	cout << "---------------------------------\n\n" << endl;

}

int Student::getAge()
{
	return this->Human::getAge() + 1;
}


void Student::FileRead(Student* stud)
{	
	ifstream file;
	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		file.open("Students.txt");
		file >> count_stud;
		for (int i = 0; i < count_stud; i++)
		{
			string first, mid, last, ser, num, group;
			int age, sholar, rt[100];
			file >> last >> first >> mid;
			file >> age;
			file >> num >> ser;
			file >> sholar;
			file >> group;
			if (group[group.length() - 1] == '*')
			{
				stud[i].rating.reserve(100);
				group = group.substr(0, group.length() - 1);
				int size_of_rt;
				file >> size_of_rt;
				int num_of_rt = 0;
				for (int j = 0; j < size_of_rt; j++)
				{
					file >> num_of_rt;
					stud[i].rating.push_back(num_of_rt);
				}
			}
			stud[i].setFIO(first, mid, last);
			stud[i].setAge(age);
			stud[i].setPD(num, ser);
			stud[i].scholarship = sholar;
			stud[i].group = group;
		}
		file.close();
	}
	catch (std::ifstream::failure e) {
		cout << "������ ��� ������ ��� �������� �����!" << endl;
		_getch();
	}
}

void Student::FileWrite(Student *stud)
{
	ofstream file;
	file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
	try
	{
		file.open("Students.txt");
		file << count_stud << endl;
		for (int i = 0; i < count_stud; i++)
		{
			file << stud[i].getFIO().getLast() << endl;
			file << stud[i].getFIO().getFirst() << endl;
			file << stud[i].getFIO().getMid() << endl;
			file << stud[i].getAge() << endl;
			file << stud[i].getPD().getNum() << endl;
			file << stud[i].getPD().getSer() << endl;
			file << stud[i].scholarship << endl;
			int count_rating = stud[i].rating.size();
			if (count_rating > 0)
			{
				file << stud[i].group + "*" << endl;
				file << count_rating << endl;
				for (int j = 0; j < count_rating; j++)
				{
					file << stud[i].rating[j] << endl;
				}
			}
			else
				file << stud[i].group << endl;
		}
		file.close();
	}
	catch (std::ofstream::failure e) {
		cout << "������ ��� ���������� �����!"<< endl;
		_getch();
	}
}

Student Student::operator + (Student stud)
{
	return Student(this->scholarship + stud.scholarship);
}

Student& Student::operator ++ ()
{
	this->setAge((this->getAge()) + 1);
	return *this;
}

Student Student::operator ++ (int)
{
	Student stud = *this;
	++* this;
	return stud;
}

void Student::operator=(Human human)
{
	this->setFIO(human.getFIO().getFirst(), human.getFIO().getMid(), human.getFIO().getLast());
	this->setPD(human.getPD().getNum(), human.getPD().getSer());
	this->setAge(human.getAge());
}


void InputStud(Student& stud)
{
	system("cls");
	string first, mid, last, num, ser;
	cout << "������� ������� ��������: ";
	last = write_str(29);
	cout << "������� ��� ��������: ";
	first = write_str(29);
	cout << "������� �������� ��������: ";
	mid = write_str(29);
	stud.setFIO(first, mid, last);
	cout << "������� �������: ";
	stud.setAge(write_num(125));
	cout << "������� ����� ��������: ";
	num = write_pd(4);
	cout << "������� ����� ��������: ";
	ser = write_pd(6);
	stud.setPD(num, ser);
	cout << "������� ������ ���������: ";
	stud.scholarship = write_num(100000);
	cout << "������� ����� ������: ";
	cin >> stud.group;
	cout << "������� ���-�� ������: ";
	int num_of_ratings = write_num(100);
	for (int i = 0; i < num_of_ratings; i++)
	{
		cout << to_string(i+1) + ": ";
		stud.addRating(write_num(100));
	}
	sort(stud.rating.begin(), stud.rating.end());
	stud.count_stud++;
}
void Student::OutputStud(int i)
{
	cout << to_string(i + 1) + "-� �������: " << endl;
	cout << "---------------------------------" << endl;
	cout << "���: " + this->getFIO().getLast() + " " + this->getFIO().getFirst() + " " + this->getFIO().getMid() << endl;
	cout << "���������� ������: " + this->getPD().getNum() + " " + this->getPD().getSer() << endl;
	cout << "�������: " + to_string(this->getAge()) << endl;
	cout << "������� ������: " + this->group << endl;
	cout << "���������: " + to_string(this->scholarship) << endl;
	int size_of_rt = this->rating.size();
	if (size_of_rt > 0)
	{
		cout << "������:";
		for (int i = 0; i < size_of_rt; i++)
		{
			cout << " " + to_string(this->rating[i]);
			if (i != size_of_rt - 1)
			{
				cout << ",";
			}
		}
		cout << endl;
		cout << "���� ������ (>75): ";
		int count_of_5 = 0;
		auto res = find_if(this->rating.begin(), this->rating.end(), [](int a) {
			return a >= 75;
			});
		if (res != this->rating.end())
		{
			cout << "��" << endl;
		}
		else
		{
			cout << "���" << endl;
		}
	}
	cout << "\n---------------------------------\n\n" << endl;
}

void Student::ChangeInfo()
{
	int inp;
	inp = write_num(6);
	if (inp == 6)
		return;
	else if (inp == 1)
	{
		string first, mid, last;
		cout << "������� ������� ��������: ";
		last = write_str(29);
		cout << "������� ��� ��������: ";
		first = write_str(29);
		cout << "������� �������� ��������: ";
		mid = write_str(29);
		this->setFIO(first, mid, last);
	}
	else if (inp == 2)
	{
		string num, ser;
		cout << "������� ����� ��������: ";
		num = write_pd(4);
		cout << "������� ����� ��������: ";
		ser = write_pd(6);
		this->setPD(num, ser);
	}
	else if (inp == 3)
	{
		cout << "������� �������: ";
		this->setAge(write_num(125));
	}
	else if (inp == 4)
	{
		cout << "������� ����� ������: ";
		cin >> this->group;
	}
	else if (inp == 5)
	{
		cout << "������� ������ ���������: ";
		this->scholarship = write_num(100000);
	}
}

void Student::stud_analysis(int* stud_sum_age, int* stud_sum_scholarship,
				   int *count_students, int* max_scholarship, int* min_scholarship)
{
	system("cls");
	if (!*count_students)
	{
		*max_scholarship = this->scholarship;
		*min_scholarship = this->scholarship;
	}
	else if (this->scholarship > *max_scholarship)
	{
		*max_scholarship = this->scholarship;
	}
	else if (this->scholarship < *min_scholarship)
	{
		*min_scholarship = this->scholarship;
	}
	*stud_sum_scholarship += this->scholarship;
	*count_students += 1;
	*stud_sum_age += this->getAge();
}

int Student::GetCount()
{
	return count_stud;
}

void Student::SetCount(int count)
{
	count_stud = count;
}
