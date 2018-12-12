#pragma once
#include "Base_class.h"
#include <memory>

class Offensive :
	public Base_class
{
public:
	int dmg;
	std::string battle_cry;
	Offensive(int,std::string,int,std::string);
	Offensive();
	~Offensive();
	virtual std::string get_battle_cry();
	virtual int get_dmg();
	virtual int encounter(std::shared_ptr<Base_class>);
};

