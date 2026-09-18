#pragma once
#include <string>

class Character
{
private:
	std::string name;
	int health;
	int attackPower;

public:

	Character(std::string characterName, int startHealth, int startAttack);
	virtual ~Character();


	void setName(std::string newName)
	{
		name = newName;
	}

	std::string getName()
	{
		return name;
	}

	void setHealth(int newHealth)
	{
		health = newHealth;
	}

	int getHealth()
	{
		return health;
	}

	void setAttackPower(int newAttackPower)
	{
		attackPower = newAttackPower;
	}

	int getAttackPower()
	{
		return attackPower;
	}


	// Por qual motivo não tem mais 2 parâmetros? Agora o atacante não é mais um parâmetro, é o próprio objeto que chama o método
	// Antes era attacker.attackPower, agora só escreve attackPower direto
	virtual void performAttack(Character& target);



};

// void attack(Character& attacker, Character& target); - colocar dentro da classe para tornar uma fuñção virtual e muda de nome para performAttack

void characterHealthPrint(Character& printhealth);


