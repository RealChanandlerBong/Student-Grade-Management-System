#include "performance.h"



performance::performance()
{
}

performance::performance(const course &c, const student &stu, const string &s) : course(c), student(stu)
{
	score = s;
	grade = Get_grade(score);
	gp = Get_gp(score);
	ofstream *ofp3 = new ofstream("performance.txt", ios::app);
	*ofp3 << course_number << ',' << course_name << ',' << credit << ',' << teacher_name << ','
		<< student_id << ',' << student_name << ',' << score << ',' << grade << ',' << gp << endl;
	ofp3->close();
	delete ofp3;
}

performance::performance(const course &c, const string &sid, const string &sn, const string & s) :course(c), student(sid, sn)
{
	score = s;
	grade = Get_grade(score);
	gp = Get_gp(score);
	ofstream *ofp3 = new ofstream("performance.txt", ios::app);
	*ofp3 << course_number << ',' << course_name << ',' << credit << ',' << teacher_name << ','
		<< student_id << ',' << student_name << ',' << score << ',' << grade << ',' << gp << endl;
	ofp3->close();
	delete ofp3;
}

performance::~performance()
{
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
