#include <iostream>
#include "Warrior.h"
#include "Character.h"
#include "Team.h"

Warrior::Warrior(std::string characterName, int startHealth, int startAttack)
	: Character(characterName, startHealth, startAttack)
{

}

//Character::~Character() {
//	std::cout << "Character destroyed: " << name << std::endl;
//}

Warrior::~Warrior() {
	std::cout << "Warrior destroyed: " << getName() << std::endl;

}

void Warrior::performAttack(Character& target)
{
	target.setHealth(target.getHealth() - getAttackPower());
	std::cout << target.getName() << " was attacked by: " << getName() << std::endl;
	std::cout << target.getName() << " Health: " << target.getHealth() << std::endl;
	std::cout << "\n=============\n" << std::endl;


}



	/*void Character::performAttack(Character & target)
	{
		target.setHealth(target.getHealth() - attackPower);
		std::cout << target.getName() << " was attacked by: " << name << std::endl;
		std::cout << target.getName() << " Health: " << target.getHealth() << std::endl;
		std::cout << "\n=============\n" << std::endl;
	}*/
