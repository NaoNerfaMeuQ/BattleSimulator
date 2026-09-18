#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Character.h"
#include "Team.h"
#include "Warrior.h"
#include "Mage.h"
 


int main()
{

	Team heroTeam;
	heroTeam.addCharacter(std::make_unique<Warrior>("Hero", 100, 10));
	heroTeam.addCharacter(std::make_unique<Warrior>("Warrior", 100, 10));
	heroTeam.addCharacter(std::make_unique<Mage>("Mage", 100, 10, 10));

	std::cout << "\n===============\n" << std::endl;

	Team orkTeam;
	orkTeam.addCharacter(std::make_unique<Warrior>("Ork", 100, 10));
	orkTeam.addCharacter(std::make_unique<Warrior>("Globin", 100, 10));


	std::cout << "\n===============\n" << std::endl;


	srand(static_cast<unsigned int>(time(NULL)));

	heroTeam.printAllHealth();
	orkTeam.printAllHealth();

	std::cout << "\n===============\n" << std::endl;



	bool heroTurn = true;
	while (heroTeam.isAlive() && orkTeam.isAlive())
	{

		if (heroTurn)
		{
			heroTeam.attackTeam(orkTeam);
			//std::cout << "Ork was attacked! Health: " << orkTeam.characters[0]->health << std::endl;
			orkTeam.removeDead();
		}
		else
		{
			orkTeam.attackTeam(heroTeam);
			//std::cout << "Hero was attacked! Health: " << heroTeam.characters[0]->health << std::endl;
			heroTeam.removeDead();
		}
		heroTurn = !heroTurn;
	}

	if (heroTeam.isAlive())
	{
		std::cout << "Hero team wins!" << std::endl;
	}
	else
	{
		std::cout << "Ork team wins!" << std::endl;

	}




	return 0;
}
