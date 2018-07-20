#include "performance.h"



performance::performance()
{
}

performance::performance(const course &c, const student &stu, const string &s) : course(c), student(stu)
{
	score = s;
	grade = Get_grade(score);
	gp = Get_gp(score);
}

performance::performance(const course &c, const string &sid, const string &sn, const string & s) :course(c), student(sid, sn)
{
	score = s;
	grade = Get_grade(score);
	gp = Get_gp(score);
}

performance::~performance()
{
}

void performance::Set(const string & score)
{
	this->score = score;
	grade = Get_grade(score);
	gp = Get_gp(score);
}

void performance::Set(const course & c, const string & score)
{
	course_number = c.course_number;
	course_name = c.course_name;
	credit = c.credit;
	teacher_name = c.teacher_name;
	this->score = score;
	grade = Get_grade(score);
	gp = Get_gp(score);
}

void performance::Set(const student & s, const string & score)
{
	student_name = s.Get_number();
	student_id = s.Get_name();
	this->score = score;
	grade = Get_grade(score);
	gp = Get_gp(score);
}

void performance::Display() const
{
	std::cout << "课程序号：" << course_number << endl
		<< "课程名：" << course_name << endl
		<< "学分：" << credit << endl
		<< "开课老师：" << teacher_name << endl << endl
		<< "学号：" << student_id << endl
		<< "学生姓名：" << student_name << endl << endl
		<< "课程成绩：" << score << endl
		<< "等级：" << grade << endl
		<< "绩点：" << gp << endl;
}

string performance::Get_number() const
{
	return (course_number + student_id);
}

string performance::Get_info() const
{
	return course::Get_info() + ',' + student::Get_info();
}

int operator !=(const performance & p1, const performance & p2)
{
	if (p1.Get_info() == p2.Get_info())
		return 0;
	else
		return 1;
}
