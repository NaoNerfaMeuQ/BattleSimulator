#include "Mage.h"
#include "Character.h"
#include "Team.h"
#include <iostream>
#include <cstdlib>

Mage::Mage(std::string characterName, int startHealth, int startAttack, int startMana)
	: Character(characterName, startHealth, startAttack)
{
	mana = startMana;
}

Mage::~Mage()
{
	std::cout << "Mage destroyed: " << getName() << std::endl;
}

int Mage::getMana()
{
	return mana;
}

void Mage::setMana(int newMana)
{
	mana = newMana;
}


void Mage::performAttack(Character& target)
{
	
	if (getMana() >= 10)
	{
		int critic;
		critic = rand() % 100;

		if (critic < 20)
		{
			target.setHealth(target.getHealth() - (getAttackPower() * 2));
			std::cout << target.getName() << " was attacked by: " << getName() << " and received a critic hit!" << std::endl;
			std::cout << target.getName() << " Health: " << target.getHealth() << std::endl;
			std::cout << "\n=============\n" << std::endl;
		}
		else
		{
			target.setHealth(target.getHealth() - getAttackPower());
			std::cout << target.getName() << " was attacked by: " << getName() << std::endl;
			std::cout << target.getName() << " Health: " << target.getHealth() << std::endl;
			std::cout << "\n=============\n" << std::endl;
		}
		setMana(getMana() - 10);
		
	}
	else
	{
		target.setHealth(target.getHealth() - (getAttackPower() / 2));
		std::cout << target.getName() << " was attacked by: " << getName() << std::endl;
		std::cout << target.getName() << " Health: " << target.getHealth() << std::endl;
		std::cout << "\n=============\n" << std::endl;
	}
	
	

}