#pragma once
#include<string>
#include<vector>
using namespace std;
template<typename T>
int Exist(const vector<T> &x, const string &str)
{
	int i = 0, n=x.size();
	bool flag = 0;
	string temp;
	for (i = 0; i < n; i++)
	{
		temp = x[i].Get_number();
		if (str == temp)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		return -1;
	else
		return i;
}

template<typename T>
void Sync(const vector<T> &x, const string &str)
{
	ofstream outf(str, ios::trunc);
	if (outf.fail())
	{
		cout << "Error: cannot open file '" << str << "'. Please try again." << endl;
	}
	else
	{
		int i = 0;
		for (i = 0; i < x.size(); i++)
		{
			outf << x[i].Get_info() << endl;
		}
		outf.close();
	}
}