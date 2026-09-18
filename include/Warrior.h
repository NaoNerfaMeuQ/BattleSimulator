#pragma once

#include "Character.h"
#include <iostream>

class Warrior : public Character
{
public:
	Warrior(std::string characterName, int startHealth, int startAttack);

	~Warrior();


	void performAttack(Character& target) override;


};
