#pragma once
#include<string>
using namespace std;
template<typename T>
int Exist(const vector<T> &x, const string &str)
{
	int i = 1;
	bool flag = 0;
	while (x[i] != x.back())
	{
		i++;
		if (str == x[i].Get_number())
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		return 0;
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
		int i = 1;
		while (x[i] != x.back())
		{
			i++;
			outf << x[i].Get_info() << endl;
		}
		outf.close();
	}
}