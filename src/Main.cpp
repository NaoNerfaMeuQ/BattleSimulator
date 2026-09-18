#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Character.h"
#include "Team.h"
#include "Warrior.h"
#include "Mage.h"
 


int main()
{


	Team heroTeam;

	// Hero e Sword criados
	auto hero = std::make_unique<Character>("Hero", 100, 10);
	hero->equipWeapon(std::make_unique<Weapon>("Sword", 10));
	heroTeam.addCharacter(std::move(hero));

	//Warrior criado
	heroTeam.addCharacter(std::make_unique<Warrior>("Warrior", 100, 15));


	Team orkTeam;

	// Ork e Mace criados
	auto ork = std::make_unique<Character>("Ork", 100, 10);
	ork->equipWeapon(std::make_unique<Weapon>("Mace", 10));
	orkTeam.addCharacter(std::move(ork));

	// Wizard criado
	orkTeam.addCharacter(std::make_unique<Mage>("Wizard", 100, 5, 100));


	//srand gera uma seed aleatória e static_cast faz a conversão numérica de t_time (formato que retorna) para unsigned int
	//time(NULL) retornar o tempo exato do sistema desde 1970 - Unix epoch -
	srand(static_cast<unsigned int>(time(NULL)));

	while (heroTeam.isAlive() && orkTeam.isAlive())
	{
		// turno do jogador (heroTeam)
		std::cout << "\n=== Your turn ===" << std::endl;

		std::cout << "\nYour team:" << std::endl;
		heroTeam.printNumberedHealth();

		std::cout << "\nEnemy team:" << std::endl;
		orkTeam.printNumberedHealth();

		int attackerChoice;
		std::cout << "\nChoose your attacker (number): ";
		// Pega a escolha do jogador para atacante
		std::cin >> attackerChoice;

		int targetChoice;
		std::cout << "Choose your target (number): ";
		// Pega a escolha do jogador para quem atacar
		std::cin >> targetChoice;

		heroTeam.attackCharacter(attackerChoice, orkTeam, targetChoice);
		orkTeam.removeDead();


		//Verifica se o OrkTeam está morto, se estiver para de repetir o loop e não fica chamando turnos fantasmas
		if (!orkTeam.isAlive())
		{
			break;
		}

		// Turno do computador (orkTeam)
		std::cout << "\n=== Enemy turn ===" << std::endl;
		orkTeam.attackTeam(heroTeam);
		heroTeam.removeDead();
	}

	if (heroTeam.isAlive())
	{
		std::cout << "\nHero team wins!" << std::endl;
	}
	else
	{
		std::cout << "\nOrk team wins!" << std::endl;
	}

	return 0;
}
