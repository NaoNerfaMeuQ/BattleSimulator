#include "Character.h"
#include <iostream>

Character::Character(std::string characterName, int startHealth, int startAttack)
{
	name = characterName;
	health = startHealth;
	attackPower = startAttack;

	std::cout << "Character created: " << name << std::endl;

}

Character::~Character() {
	std::cout << "Character destroyed: " << name << std::endl;
}

// Chama diretamente o método 

void Character::performAttack(Character& target)
{
	target.setHealth(target.getHealth() - attackPower);
	std::cout << target.getName() << " was attacked by: " << name << std::endl;
	std::cout << target.getName() << " Health: " << target.getHealth() << std::endl;
	std::cout << "\n=============\n" << std::endl;
}	

//void attack(Character& attacker, Character& target)
//{
//	// target.health = target.health - attacker.attackPower; - sem getters e setters
//	target.setHealth(target.getHealth() - attacker.getAttackPower());
//	std::cout << target.getName() << " was attacked by: " << attacker.getName() << std::endl;
//	std::cout << target.getName() << " Health: " << target.getHealth() << std::endl;
//	std::cout << "\n=============\n" << std::endl;
//
//
//}

void characterHealthPrint(Character& target)
{
	std::cout << target.getName() << " health before: " << target.getHealth() << "\n" << std::endl;
}
