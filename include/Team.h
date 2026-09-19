#pragma once
#include <vector>
#include "Character.h"
#include "Warrior.h"
#include <memory>

class Team
{
private:
	

	std::vector<std::unique_ptr<Character>> characters; //Vector é um array que podemos mudar os valores Array[x] = { x, x ,x}
	/**
	 * O uso de std::unique_ptr estabelece a propriedade EXCLUSIVA do recurso.
	 * - Evita vazamentos de memória (memory leaks) deletando o objeto no destrutor (RAII).
	 * - Cópia proibida (impede duplicidade do ponteiro).
	 * - Transferência de posse permitida apenas via semântica de movimento (std::move).
	 * - Custo zero de performance em relação a um ponteiro bruto (raw pointer).
	 */
public:
	
	void addCharacter(std::unique_ptr<Character> character);


	bool isAlive();

	void attackTeam(Team& enemyTeam); 

	void removeDead();

	void printAllHealth();

	void printNumberedHealth();

	void attackCharacter(int attackerIndex, Team& enemyTeam, int targetIndex);

	int getCharacterHealth(int index);
};
