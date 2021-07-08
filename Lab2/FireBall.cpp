#include "FireBall.h"

void FireBall::DescribeMe() {
	std::cout << name << std::endl;
	std::cout << "Deals 40 damage. Reduces enemy defense by half." << std::endl;
}

void FireBall::Use(Hero* A, Hero* D) {
	D->setStatus(FIREBALL, ONE_TURN);
	int damage = 40;
	A->checkStatus(damage);
	D->decreaseHp(D->resist(damage));

	A->deathCheck(A, D);
}
