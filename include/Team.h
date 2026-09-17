#pragma once
#include <vector>
#include "Character.h"
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
	void addCharacter(std::string name, int health, int attackPower);

	/**void Team::addCharacter(std::string name, int health, int attackPower)
	* {
	* characters.push_back(std::make_unique<Character>(name, health, attackPower));
	* }
	* 
	* push_back é o método do vector que adiciona um elemento no final da lista. 
	* O nome já descreve a ação: "empurra pro final" (push = empurrar, back = final/traseira).
	*/

	bool isAlive();

	void attackTeam(Team& enemyTeam); 

	void removeDead();

	void printAllHealth();

};
