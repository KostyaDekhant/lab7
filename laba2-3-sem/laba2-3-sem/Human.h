#pragma once
#include "FIO.h"
#include "pd.h"
#include <vector>
#include <algorithm>
//#include "Student.h"
//#include "Professor.h"

class Human
{
private:
	class FIO fio;
	class passport_data pd;
	int age;
public:
	class FIO getFIO();
	class passport_data getPD();
	virtual int getAge();
	virtual void Display();

	void setFIO(string first, string mid, string last);
	void setPD(string num, string ser);
	void setAge(int age);

	Human();
	Human(class FIO fio);
	Human(class FIO fio, class passport_data pd, int age);
	~Human();
};

//Human HumanInit(int inpage, struct FIO Fio, struct passport_data Pd);