#include "stdafx.h"
#include "Offensive.h"
#include <iostream>
#include <time.h>


Offensive::Offensive()
{
}

Offensive::Offensive(int c_healthpoints, std::string c_description, int c_dmg, std::string c_battle_cry)
{
	health_points = c_healthpoints;
	description = c_description;
	dmg = c_dmg;
	battle_cry = c_battle_cry;
}
 
int Offensive::get_dmg()
{
	return dmg;
}

std::string Offensive::get_battle_cry()
{
	return battle_cry;
}

int roll_dX(int sides)
{
	int num = (0 + (rand() % (int)(sides + 1)));
	return num;
}

int Offensive::encounter(std::shared_ptr<Base_class> enemy)
{
	int number_of_rounds = 1;
	if(enemy->get_dmg())
	{

		std::cout << this->get_battle_cry() << std::endl;
		std::cout << enemy->get_battle_cry() << std::endl;
		while(this->health_points>0 && enemy->health_points>0)
		{
			std::cout << "Round " << number_of_rounds << std::endl;
			int hero_roll = roll_dX(10);
			std::cout << "Hero strikes for " << this->get_dmg() + hero_roll << std::endl;
			enemy->health_points -= this->get_dmg() + hero_roll;
			if (enemy->health_points <= 0)
				break;
			int enemy_roll = roll_dX(10);
			std::cout << enemy->description << " hits for " << enemy->get_dmg() + enemy_roll << std::endl;
			this->health_points -= enemy->get_dmg() + enemy_roll;
			if (this->health_points <= 0)
				break;
			std::cout << "Hero is left with " << this->health_points << " hp" << std::endl;
			std::cout << enemy->description << " has " << enemy->health_points << " hp" << std::endl;
			number_of_rounds++;

		}
		if(this->health_points>0)
		{
			std::cout << "Hero is victorius!" << std::endl;
		}else
		{
			std::cout << "Hero has been slain" << std::endl;
		}
		std::cout << "########################" << std::endl;
	}else
	{
		std::cout << "Hero encounters an obstacle!" << std::endl;
		while (enemy->health_points>0)
		{
			std::cout << "Round " << number_of_rounds << std::endl;
			int hero_roll = roll_dX(10);
			int hero_dmg = hero_roll + this->get_dmg() - enemy->get_resistance();
			if (hero_dmg <= 0)
				hero_dmg = 0;
			std::cout << "Hero strikes for " << hero_dmg << std::endl;
			enemy->health_points -= hero_dmg;
			if (this->health_points <= 0)
				break;
			number_of_rounds++;
			if(number_of_rounds%4 == 0)
			{
				std::cout << "Hero is trying to force his way through the obstacle" << std::endl;
				if(hero_dmg >= enemy->get_size()*2)
				{
					std::cout << "And he succeeded" << std::endl;
					break;
				}else
				{
					std::cout << "But he was unsuccessful" << std::endl;
				}

			}
		}
		std::cout << "########################" << std::endl;
	}
	return number_of_rounds;

}


Offensive::~Offensive()
{
}
