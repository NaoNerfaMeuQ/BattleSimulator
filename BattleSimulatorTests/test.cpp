#include "pch.h"
#include "Character.h"
#include "Team.h"


// Define um teste - TEST (1° parâmetro é o nome do grupo - test suite - geralmente o nome da classe sendo testada
//2° Parâmetro é o nome do teste específico, descrevendo o que ele verifica, vira o corpo de fuma função, depois de "{" é o teste em si
TEST(CharacterTest, ConstructorSetsInitialValues) 
{

	Character hero("Hero", 100, 10);

	// Macro central do Google Test. Ele verifica se os dois valores são iguais, caso contrário, o teste falha e o framework mostra qual valor era esperado vs qual veio
	EXPECT_EQ(hero.getHealth(), 100);
	EXPECT_EQ(hero.getAttackPower(), 10);
	EXPECT_EQ(hero.getName(), "Hero");
 
}

TEST(TeamTest, AttackCharacterRejectsTargetIndexOutOfEnemyBounds)
{
	Team heroTeam;
	heroTeam.addCharacter(std::make_unique<Character>("Hero", 100, 10));
	heroTeam.addCharacter(std::make_unique<Character>("Warrior", 100, 10));

	Team enemyTeam;
	enemyTeam.addCharacter(std::make_unique<Character>("Ork", 100, 10));

	heroTeam.attackCharacter(2, enemyTeam, 2); //alvo 2 não existe no enemyTeam

	EXPECT_EQ(enemyTeam.getCharacterHealth(1), 100); //Ork não deveria ter sido atacado

}

TEST(WeaponTest, EquippedWeaponIncreasesAttackPower)
{
	Character hero("Hero", 100, 10);

	EXPECT_EQ(hero.getAttackPower(), 10);   // sem arma, ataque é só o base

	hero.equipWeapon(std::make_unique<Weapon>("Sword", 5));

	EXPECT_EQ(hero.getAttackPower(), 15);   // com arma, base + bônus
}