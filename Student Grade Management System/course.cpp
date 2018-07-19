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
	ifstream *ofp = new ifstream("course.txt", ios::in);
	if (ofp->fail())
	{
		std::cout << "ERROR: Cannot open file 'course.txt'." << endl;
		exit(0);
	}
	else
	{
		string temp; bool flag = 1;
		while (!ofp->eof())
		{
			std::getline(*ofp, temp, ',');
			if (temp == number)
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
			ofstream *ofp1 = new ofstream("course.txt", ios::app);
			if (ofp1->fail())
			{
				std::cout << "ERROR: Cannot open file 'course.txt'. " << endl;
				exit(0);
			}
			else
			{
				*ofp1 << course_number << ',' << course_name << ',' << credit << ',' << teacher_name << endl;
				//count_course++;
				ofp1->close();
				delete ofp1;
			}
		}

	}
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
	ifstream *ofp = new ifstream("course.txt");
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
			if (temp1 == course_number)
			{
				temp2 = temp1;
				std::getline(*ofp, temp1);
				temp2 = temp2 + ',' + temp1;
				break;
			}
			else
			{
				std::getline(*ofp, temp1);
			}
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
			*ofp2 << course_number << "," << course_name << "," << credit << "," << teacher_name << endl;
			ofp2->close(); delete ofp2;
			ofp3->close(); delete ofp3;
		}
	}
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

int operator!=(const course & c1, const course & c2)
{
	if (c1.course_number == c2.course_number&&c1.course_name == c2.course_name
		&&c1.credit == c2.credit&&c1.teacher_name == c2.teacher_name)
		return 0;
	else
		return 1;
}
