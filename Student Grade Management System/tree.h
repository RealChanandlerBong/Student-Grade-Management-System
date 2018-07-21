#pragma once
#include<iostream>
#include<string>
#include"course.h"
#include"student.h"
#include"performance.h"
#include"window.h"
#include"template.h"
using namespace std;

inline void returnMenu(vector<course> &cour, vector <student> &stu, vector <performance> &per, std::string &choose);

void f_0(vector<course> &cour, vector <student> &stu, vector <performance> &per, std::string &choose);
void f_01(vector<course> &cour, vector <student> &stu, vector <performance> &per, std::string &choose);
void f_02(vector<course> &cour, vector <student> &stu, vector <performance> &per, std::string &choose);
void f_03(vector<course> &cour, vector <student> &stu, vector <performance> &per, std::string &choose);
void f_04(vector<course> &cour, vector <student> &stu, vector <performance> &per, std::string &choose);
void f_011(vector<course> &cour, vector <student> &stu, vector <performance> &per, std::string &choose);
void f_012(vector<course> &cour, vector <student> &stu, vector <performance> &per, std::string &choose);
void f_013(vector<course> &cour, vector <student> &stu, vector <performance> &per, std::string &choose);
void f_0131(vector<course> &cour, vector <student> &stu, vector <performance> &per, std::string &choose);
void f_0132(vector<course> &cour, vector <student> &stu, vector <performance> &per, std::string &choose);
void f_021(vector<course> &cour, vector <student> &stu, vector <performance> &per, std::string &choose);
void f_022(vector<course> &cour, vector <student> &stu, vector <performance> &per, std::string &choose);
void f_023(vector<course> &cour, vector <student> &stu, vector <performance> &per, std::string &choose);
void f_031(vector<course> &cour, vector <student> &stu, vector <performance> &per, std::string &choose);
void f_032(vector<course> &cour, vector <student> &stu, vector <performance> &per, std::string &choose);
void f_033(vector<course> &cour, vector <student> &stu, vector <performance> &per, std::string &choose);
void f_041(vector<course> &cour, vector <student> &stu, vector <performance> &per, std::string &choose);
void f_042(vector<course> &cour, vector <student> &stu, vector <performance> &per, std::string &choose);
void f_043(vector<course> &cour, vector <student> &stu, vector <performance> &per, std::string &choose);