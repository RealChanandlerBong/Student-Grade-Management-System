#include "student.h"



student::student()
{
}

student::student(const string &id, const string &name)
{
	student_id = id;
	student_name = name;
}

student::student(const student & s)
{
	student_id = s.student_id;
	student_name = s.student_name;
}

student::~student()
{

}

void student::Set_student(const string & name, const string & id)
{
	student_id = id;
	student_name = name;
}

void student::Display() const
{
	std::cout << "学号：" << student_id << endl
		<< "学生姓名：" << student_name << endl;
}

string student::Get_number() const
{
	return student_id;
}

string student::Get_name() const
{
	return student_name;
}

string student::Get_info() const
{
	return student_id + ',' + student_name;
}

student student::operator=(const student & s)
{
	return student(s);
}

int operator!=(const student & c1, const student & c2)
{
	if (c1.student_id == c2.student_name&&c1.student_id == c2.student_id)
		return 0;
	else
		return 1;
}

int operator==(const student & c1, const student & c2)
{
	if (c1.student_id == c2.student_name&&c1.student_id == c2.student_id)
		return 1;
	else
		return 0;
}
