#include "PowerfulHit.h"

void PowerfulHit::DescribeMe() {
	std::cout << name << std::endl;
	std::cout << "Deals damage equal to 150% of hero's damage" << std::endl;
}

void PowerfulHit::Use(Hero* A, Hero* D) {
	int damage = A->getDamage() * 1.5;
	A->checkStatus(damage);
	D->decreaseHp(D->resist(damage));

	A->deathCheck(A, D);
}
