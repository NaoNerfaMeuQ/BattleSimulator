#include "Weapon.h"
#include "Character.h"

Weapon::Weapon(std::string weaponName, int bonus)
{
	name = weaponName;
	attackBonus = bonus;
}

std::string Weapon::getName()
{
	return name;
}

int Weapon::getAttackBonus()
{
	return attackBonus;
}

void Character::equipWeapon(std::unique_ptr<Weapon> weapon)
{
	equippedWeapon = std::move(weapon);
}

//void Team::addCharacter(std::unique_ptr<Character> character)
//{
//	characters.push_back(std::move(character));
//}