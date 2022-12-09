#define MAX_SIZE 100
#include "Human.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>

Human::Human()
{
	FIO initFIO;
	this->fio = initFIO;
	passport_data initpassport_data;
	this->pd = initpassport_data;
	this->age = 19;
}

Human::Human(class FIO fio)
{
	this->fio = fio;
	passport_data initpassport_data;
	this->pd = initpassport_data;
	this->age = 50;
}
Human::Human(class FIO fio, class passport_data pd, int age)
{
	this->fio = fio;
	this->pd = pd;
	this->age = age;
}
Human::~Human()
{

}

class FIO Human::getFIO()
{
	fio.getFirst();
	fio.getMid();
	fio.getLast();
	return fio;
}
class passport_data Human::getPD()
{
	pd.getNum();
	pd.getSer();
	return pd;
}
int Human::getAge()
{
	return age;
}

void Human::Display()
{
	cout << "---------------------------------" << endl;
	cout << "ФИО: " + this->getFIO().getLast() + " " + this->getFIO().getFirst() + " " + this->getFIO().getMid() << endl;
	cout << "Паспортные данные: " + this->getPD().getNum() + " " + this->getPD().getSer() << endl;
	cout << "Возраст: " + to_string(this->getAge()) << endl;
	cout << "---------------------------------\n\n" << endl;
}


void Human::setFIO(string first, string mid, string last)
{
	fio.setFirst(first);
	fio.setMid(mid);
	fio.setLast(last);
}
void Human::setPD(string num, string ser)
{
	pd.setNum(num);
	pd.setSer(ser);
}
void Human::setAge(int age)
{
	this->age = age;
}