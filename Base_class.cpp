#include "stdafx.h"
#include "Base_class.h"


Base_class::Base_class()
{
	health_points = 0;
	description = "";
}
int Base_class::get_dmg()
{
	return 0;
}

std::string Base_class::get_battle_cry()
{
	return "";
}

int Base_class::get_resistance()
{
	return 0;
}

int Base_class::get_size()
{
	return 0;
}


Base_class::~Base_class()
{
}
