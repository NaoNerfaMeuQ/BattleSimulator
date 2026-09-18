#pragma once
#include <iostream>
#include "Character.h"


class Mage : public Character
{

private:
	int mana;

public:
	Mage(std::string characterName, int startHealth, int startAttack, int startMana);

	~Mage();

	int getMana();
	void setMana(int newMana);
	

	void performAttack(Character& target) override;


};

