#include "Shrapnel.h"

void Shrapnel::DescribeMe() {
	std::cout << name << std::endl;
	std::cout << "Deals damage equal to the enemy's armor for two turns." << std::endl;
}

void Shrapnel::Use(Hero* A, Hero* D) {
	D->setStatus(SHRAPNEL, TWO_TURN);
	int damage = 0;
	A->checkStatus(damage);
	D->decreaseHp(D->resist(damage));

	A->deathCheck(A, D);
}
