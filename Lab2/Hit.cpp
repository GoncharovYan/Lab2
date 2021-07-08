#include "Hit.h"

void Hit::DescribeMe() {
	std::cout << name << std::endl;
	std::cout << "Deals damage equal to the hero's damage" << std::endl;
}

void Hit::Use(Hero* A, Hero* D) {
	int damage = A->getDamage();
	A->checkStatus(damage);
	D->decreaseHp(D->resist(damage));

	A->deathCheck(A, D);
}
