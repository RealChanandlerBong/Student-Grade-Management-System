#pragma once
#include<string>
using namespace std;
template<typename T>
int Exsit(const vector<T> &x, const string &str)
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
}#pragma once
