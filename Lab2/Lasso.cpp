#include "Lasso.h"

void Lasso::DescribeMe() {
	std::cout << name << std::endl;
	std::cout << "Removes all armor from the enemy for one turn. Somehow while doing so, it does 20 damage to both." << std::endl;
}

void Lasso::Use(Hero* A, Hero* D) {
	D->setStatus(LASSO, ONE_TURN);
	A->decreaseHp(20);
	int damage = 20;
	A->checkStatus(damage);
	D->decreaseHp(D->resist(damage));

	A->deathCheck(A, D);
}
