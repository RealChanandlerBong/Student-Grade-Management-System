#pragma once
#include "iostream"
#include "fstream"
#include "string"
#include "base.h"
using namespace std;
class course : virtual public base
{
protected:
	string course_number, course_name, credit, teacher_name;
	//static int count_course;
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
	//int Get_count() const;
};