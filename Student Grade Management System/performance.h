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
	//static int count_performance;
public:
	performance();
	performance(const course &c, const student &stu, const string &s);
	performance(const course &c, const string &sid, const string &sn, const string & s);
	~performance();
	//void Set(const string &course_name, const string stu_id, const string &score);
	void Display() const;
	string Get_number() const;
	string Get_info() const;
};

