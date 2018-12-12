#pragma once
#include <string>

class Base_class
{
public:
	int health_points;
	std::string description;
	Base_class();
	~Base_class();
	virtual std::string get_battle_cry();
	virtual int get_dmg();
	virtual int get_resistance();
	virtual int get_size();
};

