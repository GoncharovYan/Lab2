#include "IceShard.h"

void IceShard::DescribeMe() {
	std::cout << name << std::endl;
	std::cout << "Deals 35 damage. Half of the enemy's damage will be returned to him" << std::endl;
}

void IceShard::Use(Hero* A, Hero* D) { 
	D->setStatus(ICESHARDS, ONE_TURN);
	int damage = 35;
	A->checkStatus(damage);
	D->decreaseHp(D->resist(damage));

	A->deathCheck(A, D);
}
