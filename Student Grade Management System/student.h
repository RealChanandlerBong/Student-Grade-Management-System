#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "base.h"
#include "template.h"
using namespace std;
class student :
	virtual public base
{
protected:
	string student_name;
	string student_id;
public:
	student();
	student(const string &id, const string &name);
	student(const student &s);
	virtual ~student();
	void Set_student(const string &name, const string &id);
	void Display() const;
	string Get_number() const;
	string Get_name() const;
	string Get_info() const;
	friend int operator != (const student &c1, const student &c2);
};
