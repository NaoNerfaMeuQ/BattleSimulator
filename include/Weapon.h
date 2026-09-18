#pragma once
#include <memory>

#include <string>

class Weapon
{

private:
	std::string name;
	int attackBonus;

public:
	Weapon(std::string weaponName, int bonus);

	std::string getName();
	int getAttackBonus();





};

