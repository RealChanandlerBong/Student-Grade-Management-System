#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "base.h"
#include "course.h"
#include "student.h"
#include "grade.h"
#include "performance.h"
#include"window.h"
#include "template.h"
using namespace std;
int main()
{
	vector<window>win(15);
	vector<course>cour(1);
	vector<student>stu(1);
	vector<performance>per(1);
	string choose = "0", temp;
	win[0] = window(choose);
	win[0].Display();
	win[1] = window("01");
	win[2] = window("02");
	win[3] = window("03");
	win[4] = window("011");
	win[5] = window("012");
	win[6] = window("013");
	win[7] = window("021");
	win[8] = window("022");
	win[9] = window("023");
	win[10] = window("031");
	win[11] = window("032");
	win[12] = window("033");
	win[13] = window("0131");
	win[14] = window("0132");
	bool flag = 0;//判断是否到达树叶
	while (!flag)
	{
		cin >> temp;
		while (cin.fail() || (temp != "1"&&temp != "2"&&temp != "3"&&temp != "4"))
		{
			std::cout << "Try again! " << endl;
			std::cin.clear();
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> temp;
		}
		choose = choose + temp;
		if (temp == "4")
			win[0].Display();
		else if (choose == "01")
			win[1].Display();
		else if (choose == "02")
			win[2].Display();
		else if (choose == "03")
			win[3].Display();
		else if (choose == "011")
		{
			win[4].Display();
			flag = 1;
		}
		else if (choose == "012")
		{
			win[5].Display();
			flag = 1;
		}
		else if (choose == "013")
		{
			win[6].Display();
		}
		else if (choose == "0131")
		{
			win[13].Display();
			flag = 1;
		}
		else if (choose == "0132")
		{
			win[14].Display();
			flag = 1;
		}
		else if (choose == "021")
		{
			win[7].Display();
			flag = 1;
		}
		else if (choose == "022")
		{
			win[8].Display();
			flag = 1;
		}
		else if (choose == "023")
		{
			win[9].Display();
			flag = 1;
		}
		else if (choose == "031")
		{
			win[10].Display();
			flag = 1;
		}
		else if (choose == "032")
		{
			win[11].Display();
			flag = 1;
		}
		else if (choose == "033")
		{
			win[12].Display();
			flag = 1;
		}
	}
	if (choose == "011")
	{
		string course_num, course_name, credit, teacher_name;
		std::cout << "请输入课程序号："; std::cin >> course_num;
		std::cout << "请输入课程名："; std::cin >> course_name;
		std::cout << "请输入学分："; std::cin >> credit;
		std::cout << "请输入教师姓名："; std::cin >> teacher_name;
		cour.push_back(course(course_num, course_name, credit, teacher_name));
	}
	else if (choose == "012")
	{
		std::string student_id, student_name;
		std::cout << "请输入学号："; std::cin >> student_id;
		std::cout << "请输入学生姓名："; std::cin >> student_name;
		stu.push_back(student(student_id, student_name));
	}
	else if (choose == "0131")
	{
		bool flag = 0;
		int i = 1;
		while (flag == 0)
		{
			std::string course_number;
			std::cout << "请输入课程序号："; std::cin >> course_number;
			i = Exsit(cour, course_number);
			if (i == 0)
				cout << "Sorry, cannot find course '" << course_number << "'. Please input again." << endl;
			else
				flag = 1;
		}
		std::string stu_id, stu_name, score;
		std::cout << "请输入学生学号：";
		std::cin >> stu_id;
		std::cout << "请输入学生姓名：";
		std::cin >> stu_name;
		std::cout << "请输入学生成绩：";
		std::cin >> score;
		per.push_back(performance(cour[i], stu_id, stu_name, score));
	}
	else if (choose == "0132")
	{
		string course_num, course_name, credit, teacher_name;
		string stu_id, stu_name, score;
		std::cout << "请输入课程序号："; std::cin >> course_num;
		std::cout << "请输入课程名："; std::cin >> course_name;
		std::cout << "请输入学分："; std::cin >> credit;
		std::cout << "请输入教师姓名："; std::cin >> teacher_name;
		std::cout << "请输入学生学号："; std::cin >> stu_id;
		std::cout << "请输入学生姓名："; std::cin >> stu_name;
		std::cout << "请输入学生成绩："; std::cin >> score;
		course *cp = new course(course_num, course_name, credit, teacher_name);
		cour.push_back(*cp);
		per.push_back(performance(*cp, stu_id, stu_name, score));
		delete cp;
	}
	else if (choose == "021")
	{
		std::string old_number, new_number, new_courseName, new_credit, new_teacherName;
		int i = 1;
		bool flag = 0;
		while (flag != 1)
		{
			std::cout << "请输入要修改的课程序号：";
			std::cin >> old_number;
			i = Exsit(cour, old_number);
			if (i == 0)
				cout << "Sorry, cannot find course '" << old_number << "'. Please input again." << endl;
			else
			{
				flag = 1;
				std::cout << "提示：你将要修改课程 '" << old_number << ": " << cour[i].Get_name() << "'的信息，是否确定？[Y/N]";
				char c;
				std::cin >> c;
				while ((c != 'y'&&c != 'Y'&&c != 'n'&&c != 'N') || cin.fail())
				{
					std::cout << "Try again! [Y/N]" << endl;
					std::cin.clear();
					std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
					std::cin >> c;
				}
				if (c == 'y' || c == 'Y')
					break;
				else
					flag = 0;
			}

		}
		std::cout << "请输入新的课程序号："; std::cin >> new_number;
		std::cout << "请输入新的课程名："; std::cin >> new_courseName;
		std::cout << "请输入新的学分："; std::cin >> new_credit;
		std::cout << "请输入新的开课教师："; std::cin >> new_teacherName;
		cour[i].Set_course(new_number, new_courseName, new_credit, new_teacherName);
	}
	else if (choose == "022")
	{
		std::string old_id, new_id, new_name;
		int i;
		bool flag = 0; //用于判断是否继续输入
		while (flag != 1)
		{
			std::cout << "请输入要修改的学生学号：";
			std::cin >> old_id;
			i = Exsit(stu, old_id);
			if (i == 0)
				cout << "Sorry, cannot find student '" << old_id << "'. Please input again." << endl;
			else
			{
				flag = 1;
				std::cout << "提示：你将要修改学生 '" << old_id << ": " << stu[i].Get_name() << "'的信息，确定？[Y/N]";
				char c;
				std::cin >> c;
				while ((c != 'y'&&c != 'Y'&&c != 'n'&&c != 'N') || cin.fail())
				{
					std::cout << "Try again! [Y/N]" << endl;
					std::cin.clear();
					std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
					std::cin >> c;
				}
				if (c == 'y' || c == 'Y')
					break;
				else
					flag = 0;
			}
		}
		std::cout << "请输入新的学号："; std::cin >> new_id;
		std::cout << "请输入新的学生姓名："; std::cin >> new_name;
		stu[i].Set_student(new_id, new_name);
	}
	else if (choose == "023")
	{
		int i;
		bool flag = 0;
		std::string course_number, student_id, new_score;
		while (flag == 0)
		{
			std::cout << "请输入课程序号：";
			std::cin >> course_number;
			i = Exsit(cour, course_number);
			if (i == 0)
				cout << "Sorry, cannot find course '" << course_number << "'. Please input again." << endl;
			else
				flag = 1;
		}
		flag = 0;
		while (flag == 0)
		{
			std::cout << "请输入学生学号：";
			std::cin >> student_id;
			i = Exsit(stu, student_id);
			if (i == 0)
				cout << "Sorry, cannot find student '" << student_id << "'. Please input again." << endl;
			else
				flag = 1;
		}
		flag = 0;
		while (flag == 0)
		{
			std::cout << "请输入新成绩：";
			std::cin >> new_score;



		}
		system("pause");
		return 0;
	}