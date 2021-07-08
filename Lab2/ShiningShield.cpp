#include "ShiningShield.h"

void ShiningShield::DescribeMe() {
	std::cout << name << std::endl;
	std::cout << "Deals damage, equal to 75% hero's damage. Increased armor by 20 for one turn" << std::endl;
}

void ShiningShield::Use(Hero* A, Hero* D) {
	A->setStatus(SHININGSHIELD, ONE_TURN);
	int damage = A->getDamage() * 0.75;
	A->checkStatus(damage);
	D->decreaseHp(D->resist(damage));

	A->deathCheck(A, D);
}
