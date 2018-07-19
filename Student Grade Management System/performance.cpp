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
	std::cout << "�γ���ţ�" << course_number << endl
		<< "�γ�����" << course_name << endl
		<< "ѧ�֣�" << credit << endl
		<< "������ʦ��" << teacher_name << endl << endl
		<< "ѧ�ţ�" << student_id << endl
		<< "ѧ��������" << student_name << endl << endl
		<< "�γ̳ɼ���" << score << endl
		<< "�ȼ���" << grade << endl
		<< "���㣺" << gp << endl;
}

string performance::Get_number() const
{
	return (course_number + student_id);
}

string performance::Get_info() const
{
	return course::Get_info() + ',' + student::Get_info();
}
