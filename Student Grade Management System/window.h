#pragma once
#include "iostream"
#include "string"
using namespace std;
class window
{
protected:
	string welcome;
	string menu[4];
public:
	window();
	window(string choose);
	~window();
	void Display();
};

