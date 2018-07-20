#pragma once
#include "course.h"
#include "student.h"
#include "grade.h"
#include "iostream"
#include "fstream"
#include "string"
using namespace std;
class performance :
	public course, public student
{
protected:
	string score, grade, gp;
public:
	performance();
	performance(const course &c, const student &stu, const string &s);
	performance(const course &c, const string &sid, const string &sn, const string & s);
	~performance();
	void Set(const string &score);
	void Set(const course &c, const string &score);
	void Set(const student &s, const string &score);
	void Display() const;
	string Get_number() const;
	string Get_info() const;
	friend int operator !=(const performance &p1, const performance &p2);
};
