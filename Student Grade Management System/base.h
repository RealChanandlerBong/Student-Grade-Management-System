#pragma once
#include<string>
using namespace std;
class base
{
public:
	base();
	~base();
	virtual void Display() const = 0;
	virtual string Get_number() const = 0;
	virtual string Get_info() const = 0;
};

