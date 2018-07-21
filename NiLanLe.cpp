//送给你一个字符串判断是否是数字的函数
//在必要的时候加上
#include<string>
using namespace std;

bool NiLanle(const string &a)
{
	for (int i = 0;i < a.size();i++)
		if (a[i]<'0' || a[i]>'9')
			return false;
		else
			return true;
}
