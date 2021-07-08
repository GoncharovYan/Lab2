#include "PowerfulShot.h"

void PowerfulShot::DescribeMe() {
	std::cout << name << std::endl;
	std::cout << "Shoots at the enemy, knocking him down half of the armor. Next attack will deal 150% damage" << std::endl;
}

void PowerfulShot::Use(Hero* A, Hero* D) {
	D->setStatus(POWERFULSHOT_DEBUFF, ONE_TURN);
	A->setStatus(POWERFULSHOT_BUFF, ONE_TURN);
	int damage = A->getDamage();
	A->checkStatus(damage);
	D->decreaseHp(D->resist(damage));

	A->deathCheck(A, D);
}
