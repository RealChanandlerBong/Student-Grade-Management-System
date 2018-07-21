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
#include"tree.h"
using namespace std;
int main()
{
	/*vector<window>win(18);*/
	vector<course>cour;
	vector<student>stu;
	vector<performance>per;
	string choose = "0"; //choose需要初始化【重要】
	//bool flag = 0;//判断是否到达树叶
	//while (flag==0)
	//{
	//	cin >> temp;
	//	while (cin.fail() || (temp != "1"&&temp != "2"&&temp != "3"&&temp != "4"))
	//	{
	//		std::cout << "Try again! " << endl;
	//		std::cin.clear();
	//		std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//		cin >> temp;
	//	}
	//	choose = choose + temp;
	//	if (temp == "4")
	//		win[0].Display();
	//	else if (choose == "01")
	//		win[1].Display();
	//	else if (choose == "02")
	//		win[2].Display();
	//	else if (choose == "03")
	//		win[3].Display();
	//	else if (choose == "011")
	//	{
	//		win[4].Display();
	//		flag = 1;
	//	}
	//	else if (choose == "012")
	//	{
	//		win[5].Display();
	//		flag = 1;
	//	}
	//	else if (choose == "013")
	//	{
	//		win[6].Display();
	//	}
	//	else if (choose == "0131")
	//	{
	//		win[13].Display();
	//		flag = 1;
	//	}
	//	else if (choose == "0132")
	//	{
	//		win[14].Display();
	//		flag = 1;
	//	}
	//	else if (choose == "021")
	//	{
	//		win[7].Display();
	//		flag = 1;
	//	}
	//	else if (choose == "022")
	//	{
	//		win[8].Display();
	//		flag = 1;
	//	}
	//	else if (choose == "023")
	//	{
	//		win[9].Display();
	//		flag = 1;
	//	}
	//	else if (choose == "031")
	//	{
	//		win[10].Display();
	//		flag = 1;
	//	}
	//	else if (choose == "032")
	//	{
	//		win[11].Display();
	//		flag = 1;
	//	}
	//	else if (choose == "033")
	//	{
	//		win[12].Display();
	//		flag = 1;
	//	}
	//}
	f_0(cour, stu, per, choose);
	system("pause");
	return 0;
}

