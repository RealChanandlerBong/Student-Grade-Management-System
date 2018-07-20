#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "base.h"
#include"template.h"
using namespace std;
class course : virtual public base
{
private:
	string course_number, course_name, credit, teacher_name;
public:
	course();
	course(const string &number, const string &name1, const string &c, const string &name2);
	course(const course &c);
	virtual ~course();
	void Set_course(const string &number, const string &name1, const string &c, const string &name2);
	void Display() const;
	string Get_number() const;
	string Get_name() const;
	string Get_info() const;
	friend int operator != (const course &c1, const course &c2);
	friend int operator == (const course &c1, const course &c2);
	course operator = (const course &c);
	friend class performance;
};