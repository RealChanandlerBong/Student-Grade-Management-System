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
	bool flag = 0;//�ж��Ƿ񵽴���Ҷ
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
		std::cout << "������γ���ţ�"; std::cin >> course_num;
		std::cout << "������γ�����"; std::cin >> course_name;
		std::cout << "������ѧ�֣�"; std::cin >> credit;
		std::cout << "�������ʦ������"; std::cin >> teacher_name;
		cour.push_back(course(course_num, course_name, credit, teacher_name));
	}
	else if (choose == "012")
	{
		std::string student_id, student_name;
		std::cout << "������ѧ�ţ�"; std::cin >> student_id;
		std::cout << "������ѧ��������"; std::cin >> student_name;
		stu.push_back(student(student_id, student_name));
	}
	else if (choose == "0131")
	{
		bool flag = 0;
		int i = 1;
		while (flag == 0)
		{
			std::string course_number;
			std::cout << "������γ���ţ�"; std::cin >> course_number;
			i = Exsit(cour, course_number);
			if (i == 0)
				cout << "Sorry, cannot find course '" << course_number << "'. Please input again." << endl;
			else
				flag = 1;
		}
		std::string stu_id, stu_name, score;
		std::cout << "������ѧ��ѧ�ţ�";
		std::cin >> stu_id;
		std::cout << "������ѧ��������";
		std::cin >> stu_name;
		std::cout << "������ѧ���ɼ���";
		std::cin >> score;
		per.push_back(performance(cour[i], stu_id, stu_name, score));
	}
	else if (choose == "0132")
	{
		string course_num, course_name, credit, teacher_name;
		string stu_id, stu_name, score;
		std::cout << "������γ���ţ�"; std::cin >> course_num;
		std::cout << "������γ�����"; std::cin >> course_name;
		std::cout << "������ѧ�֣�"; std::cin >> credit;
		std::cout << "�������ʦ������"; std::cin >> teacher_name;
		std::cout << "������ѧ��ѧ�ţ�"; std::cin >> stu_id;
		std::cout << "������ѧ��������"; std::cin >> stu_name;
		std::cout << "������ѧ���ɼ���"; std::cin >> score;
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
			std::cout << "������Ҫ�޸ĵĿγ���ţ�";
			std::cin >> old_number;
			i = Exsit(cour, old_number);
			if (i == 0)
				cout << "Sorry, cannot find course '" << old_number << "'. Please input again." << endl;
			else
			{
				flag = 1;
				std::cout << "��ʾ���㽫Ҫ�޸Ŀγ� '" << old_number << ": " << cour[i].Get_name() << "'����Ϣ���Ƿ�ȷ����[Y/N]";
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
		std::cout << "�������µĿγ���ţ�"; std::cin >> new_number;
		std::cout << "�������µĿγ�����"; std::cin >> new_courseName;
		std::cout << "�������µ�ѧ�֣�"; std::cin >> new_credit;
		std::cout << "�������µĿ��ν�ʦ��"; std::cin >> new_teacherName;
		cour[i].Set_course(new_number, new_courseName, new_credit, new_teacherName);
	}
	else if (choose == "022")
	{
		std::string old_id, new_id, new_name;
		int i;
		bool flag = 0; //�����ж��Ƿ��������
		while (flag != 1)
		{
			std::cout << "������Ҫ�޸ĵ�ѧ��ѧ�ţ�";
			std::cin >> old_id;
			i = Exsit(stu, old_id);
			if (i == 0)
				cout << "Sorry, cannot find student '" << old_id << "'. Please input again." << endl;
			else
			{
				flag = 1;
				std::cout << "��ʾ���㽫Ҫ�޸�ѧ�� '" << old_id << ": " << stu[i].Get_name() << "'����Ϣ��ȷ����[Y/N]";
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
		std::cout << "�������µ�ѧ�ţ�"; std::cin >> new_id;
		std::cout << "�������µ�ѧ��������"; std::cin >> new_name;
		stu[i].Set_student(new_id, new_name);
	}
	else if (choose == "023")
	{
		int i;
		bool flag = 0;
		std::string course_number, student_id, new_score;
		while (flag == 0)
		{
			std::cout << "������γ���ţ�";
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
			std::cout << "������ѧ��ѧ�ţ�";
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
			std::cout << "�������³ɼ���";
			std::cin >> new_score;



		}
		system("pause");
		return 0;
	}