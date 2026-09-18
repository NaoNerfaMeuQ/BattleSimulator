#include "Team.h"
#include "Character.h"
#include <algorithm>
#include <iostream>
#include <vector>

// Função para adicionar novo personagem dentro de um vector de Character
void Team::addCharacter(std::unique_ptr<Character> character) {
  characters.push_back(std::move(character));
}

// void Team::addCharacter(std::string name, int health, int attackPower)
//{
//	characters.push_back(std::make_unique<Character>(name, health,
//attackPower));
// }

bool Team::isAlive() {
  for (const auto &member : characters) {
    if (member->getHealth() > 0) {
      return true;
    }
  }
  return false;
}

// void Team::attackTeam(Team& enemyTeam)
//{
//	 //todo std::vector tem um método .size() que retorna quantos elementos
//ele tem guardados agora - .lenght() de Arraylist em java -
//	 //characters.size() retorna quantos personagens existem no momento
//(depois de qualquer removeDead() já ter rodado, por exemplo).
//
//	 //size_t é um tipo, igual int, bool, double. A duferenla é que .size*(
//não retorna int - ele retorna size_t | size_t tamanho = characters.size();
//igual int x = 5; ( size_t recebe o .size() )
//	 //como .size() não retorna uma quantidade da lista negativa, size_t
//seria igual um unsigned int, mas o unsigned int tem 32 bits (4 bytes) e o
//size_t tem 64 bits (8 bytes)
//
//	size_t maxSize = std::max(characters.size(),
//enemyTeam.characters.size()); // std::max pega dois valores e retorna o maior
//entre eles
//
//	for (size_t i = 0; i < maxSize; i++)
//	{
//		if (i < characters.size() && i < enemyTeam.characters.size())
//		{
//			if (characters[i]->health > 0 &&
//enemyTeam.characters[i]->health > 0)
//			{
//				attack(*characters[i],
//*enemyTeam.characters[i]);
//			}
//		}
//	}
// }

// void Team::attackTeam(Team& enemyTeam)
//{
//
//	//Por que checar os dois tamanhos e não só um? Porque os times podem ter
//números diferentes de personagens (Se heroTeam = 3 e orkTeam = 2, vai acabar
//crashando) 	for (int i = 0; i < characters.size() && i <
//enemyTeam.characters.size(); i++)
//	{
//		if (characters[i]->health > 0 && enemyTeam.characters[i]->health
//> 0)
//		{
//			attack(*characters[i], *enemyTeam.characters[i]);
//		}
//
//	}
// }

// Percorre TODOS os personagens automaticamente, ele decide quem ataca quem,
// sem intervenção do jogador
void Team::attackTeam(Team &enemyTeam) {
  // Compara o maior valor entre os dois parametros
  size_t maxSize = std::max(characters.size(), enemyTeam.characters.size());

  for (size_t i = 0; i < maxSize; i++) {
    if (i >= characters.size() || characters[i]->getHealth() <= 0) {
      continue;
    }

    Character *target = nullptr;

    if (i < enemyTeam.characters.size() &&
        enemyTeam.characters[i]->getHealth() > 0) {
      target = enemyTeam.characters[i].get();
    } else {
      for (const auto &member : enemyTeam.characters) {
        if (member->getHealth() > 0) {
          target = member.get();
          break;
        }
      }
    }

    if (target != nullptr) {
      characters[i]->performAttack(*target);
    }
  }
}

void Team::removeDead() {
  characters.erase(std::remove_if(characters.begin(), characters.end(),
                                  [](const std::unique_ptr<Character> &member) {
                                    return member->getHealth() <= 0;
                                  }),
                   characters.end());
}

void Team::printAllHealth() {
  for (const auto &member : characters) {
    characterHealthPrint(*member);
  }
}

void Team::printNumberedHealth() {

  int index = 1;
  for (const auto &member : characters) {
    if (member->getHealth() > 0) {
      std::cout << index << ") " << member->getName() << " - "
                << member->getHealth() << " HP" << std::endl;
      index++;
    }
  }
}

// Diferente do attackTeam(), não precisamos de for pois quem escolhe é o
// jogador return não tem valor pois só sai da função sem retornar nada - proteção se a validação falhar -
void Team::attackCharacter(int attackerIndex, Team &enemyTeam, int targetIndex) 
{
  int realAttackerIndex = attackerIndex - 1;
  int realTargetIndex = targetIndex - 1;

  // 1. Valida se os índices estão dento dos limites dos dois vectors
  if (realAttackerIndex < 0 || realAttackerIndex >= characters.size()) 
  {
    std::cout << "Invalid attacker choice" << std::endl;
    return;
  }

  if (realTargetIndex < 0 || realTargetIndex >= enemyTeam.characters.size()) 
  {
    std::cout << "Invalid target choice" << std::endl;
    return;
  }

  // 2. Valida se os personagens escolhidos estão vivos

  if (characters[realAttackerIndex]->getHealth() <= 0) 
  {
    std::cout << "That character is dead and cannot attack." << std::endl;
    return;
  }

  if (enemyTeam.characters[realTargetIndex]->getHealth() <= 0) 
  {
    std::cout << "That target is already dead." << std::endl;
    return;
  }

  // Caso tudo validado: ataca diretamente os dois personagens escolhidos
  characters[realAttackerIndex]->performAttack(*enemyTeam.characters[realTargetIndex]);
}
