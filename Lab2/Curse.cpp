#include "Curse.h"

void Curse::DescribeMe() {
	std::cout << name << std::endl;
	std::cout << "Deals damage equal to the hero's damage. Heals the hero for half of the damage dealt. The curse lasts 2 turns." << std::endl;
}

void Curse::Use(Hero* A, Hero* D) {
	A->setStatus(CURSE, TWO_TURN);
	int damage = A->getDamage();
	A->checkStatus(damage);
	D->decreaseHp(D->resist(damage));

	A->deathCheck(A, D);
}
