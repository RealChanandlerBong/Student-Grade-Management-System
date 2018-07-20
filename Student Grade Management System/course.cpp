#include "course.h"



course::~course()
{
}

course::course()
{
}

course::course(const string &number, const string &name1, const string &c, const string &name2)
{
	course_number = number;
	course_name = name1;
	teacher_name = name2;
	credit = c;
}

course::course(const course &c)
{
	course_number = c.course_number;
	course_name = c.course_name;
	teacher_name = c.teacher_name;
	credit = c.credit;
}

void course::Set_course(const string &number, const string &name1, const string &c, const string &name2)
{
	course_number = number;
	course_name = name1;
	teacher_name = name2;
	credit = c;
}

void course::Display() const
{
	std::cout << "课程序号：" << course_number << endl
		<< "课程名：" << course_name << endl
		<< "学分：" << credit << endl
		<< "开课老师：" << teacher_name << endl;
}

string course::Get_number() const
{
	return course_number;
}

string course::Get_name() const
{
	return course_name;
}

string course::Get_info() const
{
	return course_number + ',' + course_name + ',' + credit + ',' + teacher_name;
}

course course::operator=(const course & c)
{
	return course(c);
}

int operator!=(const course & c1, const course & c2)
{
	if (c1.Get_info()==c2.Get_info())
		return 0;
	else
		return 1;
}

int operator==(const course & c1, const course & c2)
{
	if (c1.Get_info() == c2.Get_info())
		return 1;
	else
		return 0;
}

