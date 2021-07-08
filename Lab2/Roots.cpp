#include "Roots.h"

void Roots::DescribeMe() {
	std::cout << name << std::endl;
	std::cout << "Deals 30 damage. The opponent's next attack deals only half of his damage" << std::endl;
}

void Roots::Use(Hero* A, Hero* D) {
	D->setStatus(ROOTS, ONE_TURN);
	int damage = 30;
	A->checkStatus(damage);
	D->decreaseHp(D->resist(damage));

	A->deathCheck(A, D);
}