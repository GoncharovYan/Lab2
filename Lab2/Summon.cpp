#include "Summon.h"

void Summon::DescribeMe() {
	std::cout << name << std::endl;
	std::cout << "Converts received damage into additional armor for two turns." << std::endl;
}

void Summon::Use(Hero* A, Hero* D) {
	D->setStatus(SUMMON, TWO_TURN);
	int damage = 0;
	A->checkStatus(damage);
	D->decreaseHp(D->resist(damage));

	A->deathCheck(A, D);
}
