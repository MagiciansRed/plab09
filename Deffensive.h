#pragma once
#include "Base_class.h"
class Deffensive :
	public Base_class
{
public:
	int resistance;
	int size;
	Deffensive();
	Deffensive(int, std::string, int, int);
	~Deffensive();
	virtual int get_resistance();
	virtual int get_size();
};

