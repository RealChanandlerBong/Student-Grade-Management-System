#include "student.h"



student::student()
{
}

student::student(const string &id, const string &name)
{
	student_id = id;
	student_name = name;
	ifstream *ofp = new ifstream("student.txt", ios::in);
	if (ofp->fail())
	{
		std::cout << "ERROR: Cannot open file 'student.txt'." << endl;
	}
	else
	{
		string temp; bool flag = 1;
		while (!ofp->eof())
		{
			std::getline(*ofp, temp, ',');
			if (temp == student_id)
			{
				flag = 0;
				break;
			}
			std::getline(*ofp, temp);
		}
		ofp->close();
		delete ofp;
		if (flag == 1)
		{
			ofstream *ofp2 = new ofstream("student.txt", ios::app);
			if (ofp2->fail())
			{
				std::cout << "ERROR: Cannot open file 'student.txt'. " << endl;
			}
			else
			{
				*ofp2 << student_id << ',' << student_name << endl;
				//count_student++;
				ofp2->close();
				delete ofp2;
			}
		}
	}
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
	ifstream *ofp = new ifstream("student.txt");
	ofstream *ofp1 = new ofstream("temp.txt", ios::trunc);
	if (ofp->fail() || ofp1->fail())
	{
		std::cout << "ERROR: Cannot open file." << endl;
	}
	else
	{
		string temp1, temp2;
		while (!ofp->eof())
		{
			std::getline(*ofp, temp1, ',');
			if (temp1 == student_id)
			{
				temp2 = temp1;
				std::getline(*ofp, temp1);
				temp2 = temp2 + ',' + temp1;
				break;
			}
			else
				std::getline(*ofp, temp1);
		}//temp2读出了原来的课程信息
		ofp->seekg(0);
		while (!ofp->eof())
		{
			std::getline(*ofp, temp1);
			if (temp1 != temp2)
				*ofp1 << temp1 << endl;
		}
		ofp->close(); delete ofp;
		ofp1->close(); delete ofp1;
		ofstream *ofp2 = new ofstream("course.txt", ios::trunc);
		ifstream *ofp3 = new ifstream("temp.txt");
		if (ofp->fail() || ofp1->fail())
		{
			std::cout << "ERROR: Cannot open file." << endl;
		}
		else
		{
			while (!ofp3->eof())
			{
				getline(*ofp3, temp1);
				*ofp2 << temp1 << endl;
			}
			*ofp2 << student_id << "," << student_name << endl;
			ofp2->close(); delete ofp2;
			ofp3->close(); delete ofp3;
		}
	}
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

//int student::Get_count() const
//{
//	return count_student;
//}

int operator!=(const student & c1, const student & c2)
{
	if (c1.student_id == c2.student_name&&c1.student_id == c2.student_id)
		return 0;
	else
		return 1;
}
