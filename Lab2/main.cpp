#include "Hero.h"

#include "HeroFactory.h"
#include "SkillFactory.h"
#include "KnightFactory.h"
#include "ArcherFactory.h"
#include "WizzardFactory.h"

#include <iostream>
#include <map>
#include <string>

Hero* HeroPick() {
	std::string name;
	std::string type;
	int n;
	std::cout << "Player , enter your name: ";
	std::cin >> name;
	std::cout << std::endl << name << ", choose your hero:\n1.Knight\n2.Archer\n3.Wizzard" << std::endl;
	std::cin >> n;
	switch (n) {
	case 1: type = "knight"; break;
	case 2: type = "archer"; break;
	case 3: type = "wizzard"; break;
	default: std::cout << "Incorrect enter" << std::endl;
	}
	HeroFactory HF(type, name);
	return HF.produce();
}
Hero* HeroUpgrade(Hero* player) {
	int n;
	if (player->getType() == "knight")	n = 1;
	else if (player->getType() == "archer")	n = 2;
	else if (player->getType() == "wizzard")	n = 3;

	switch (n) {
	case 1: {
		KnightFactory KF(player);
		return KF.produce();
	}
	case 2: {
		ArcherFactory AF(player);
		return AF.produce();
	}
	case 3: {
		WizzardFactory WF(player);
		return WF.produce();
	}
	}
}
void SkillsSelect(Hero* player) {
	SkillFactory SF(player);
	while (player->GetSkillsCount() < 3) {
		player->addSkill(SF.produce());
	}
}

int main() {
	Hero* player1(HeroPick());
	Hero* player2(HeroPick());
	
	std::cout << std::endl;

	player1 = HeroUpgrade(player1);
	player2 = HeroUpgrade(player2);

	std::cout << std::endl;

	SkillsSelect(player1);
	SkillsSelect(player2);

	int w1 = 0;
	int w2 = 0;
	int game = 1;
	
	int first;
	Hero* p1 = player1;
	Hero* p2 = player2;

	while (w1 != 2 && w2 != 2) {
		srand(time(NULL));
		first = rand() % 2;

		if (first == 0) {
			std::cout << p1->getName() << " starts first" << std::endl;
		}
		else {
			std::cout << p2->getName() << " starts first" << std::endl;
			p1 = player2;
			p2 = player1;
		}
		std::cout << "************************************************************************Game " << game << " ****" << std::endl << std::endl;
		int round = 1;
		while (p1->Alive() && p2->Alive()) {
			std::cout << "************************************************************************************" << std::endl;
			std::cout << "****Round " << round << " ************************************************************************" << std::endl;
			std::cout << "************************************************************************************" << std::endl;
			p1->info();
			p1->AttackHero(p2);
			p1->info();
			std::cout << "************************************************************************************" << std::endl;
			if (p2->Alive()) {
				p2->info();
				p2->AttackHero(p1);
				p2->info();
			}
			round++;
		}
		if (p1->Alive()) {
			std::cout << p1->getName() << " win" << std::endl;
			w1++;
		}
		else {
			std::cout << p2->getName() << " win" << std::endl;
			w1++;
		}
		p1->reset();
		p2->reset();
		game++;
	}

	return 0;
}