#include "stdafx.h"
#include "Base_class.h"
#include <iostream>
#include "Offensive.h"
#include <list>
#include <memory>
#include <ctime>
#include "Deffensive.h"

void scenario_one();
void scenario_two();

int main()
{
	std::srand(std::time(NULL));
	std::shared_ptr<Offensive> jason = std::make_unique<Offensive>(25, "Json", 5, "Lets do it");
	std::shared_ptr<Offensive> json = std::make_unique<Offensive>(100, "Json", 3, "You aksed for it!");
	scenario_one();
	getchar();
    return 0;
}

void scenario_one()
{
	std::shared_ptr<Offensive> jason = std::make_unique<Offensive>(25, "Json", 8, "Lets do this!");
	std::list<std::shared_ptr<Base_class>> journey;
	std::shared_ptr<Offensive> goblin0 = std::make_unique<Offensive>(20, "Goblin", 2, "You're done!");
	std::shared_ptr<Offensive> goblin1 = std::make_unique<Offensive>(20, "Goblin", 2, "You're done!");
	std::shared_ptr<Offensive> goblin2 = std::make_unique<Offensive>(20, "Goblin", 2, "You're done!");
	std::shared_ptr<Offensive> goblin3 = std::make_unique<Offensive>(20, "Goblin", 2, "You're done!");
	std::shared_ptr<Offensive> goblin4 = std::make_unique<Offensive>(20, "Goblin", 2, "You're done!");
	std::shared_ptr<Deffensive> wall0 = std::make_unique<Deffensive>(199, "Wall", 2,8);
	journey.push_back(goblin0);
	journey.push_back(goblin1);
	journey.push_back(wall0);
	//journey.push_back(goblin2);
	//journey.push_back(goblin3);
	//journey.push_back(goblin4);
	int a = 0;
	int b = 1;
	for (auto element : journey)
	{
		std::cout << "Battle number " << b << std::endl;
		int tottal_number = jason->encounter(element);
		a += tottal_number;
		b++;
		if (jason->health_points <= 0)
			break;
	}
	if (jason->health_points <= 0)
		std::cout << "Hero coudn't make it" << std::endl;
	else
		std::cout << "Hero won all the battles!" << std::endl;

	std::cout << "Tottal number of rounds " << a << std::endl;
}
