#include "stdafx.h"
#include "Deffensive.h"


Deffensive::Deffensive(int c_health_points, std::string c_description, int c_resistance, int c_size)
{
	health_points = c_health_points;
	description = c_description;
	resistance = c_resistance;
	size = c_size;
}

int Deffensive::get_resistance()
{
	return resistance;
}

int Deffensive::get_size()
{
	return size;
}



Deffensive::Deffensive()
{
}

Deffensive::~Deffensive()
{
}
