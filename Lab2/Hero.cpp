#include "Hero.h"
#include "Skill.h"

Skill* Hero::SkillSelect()
{
	int select = 0;
	std::cout << name << " choose a skill to use:" << std::endl;
	for (int i = 0; i < GetSkillsCount(); i++) {
		std::cout << i + 1 << ". ";	skills[i]->DescribeMe();
	}
	while (true) {
		std::cin >> select;
		switch (select) {
		case 1:	return skills[0];
		case 2:	return skills[1];
		case 3:	return skills[2];
		default:std::cout << "Incorrect enter" << std::endl;
		}
	}
}

void Hero::deathCheck(Hero* A, Hero* B) {
	if (A->getHp() <= 0)	A->isAlive = false;
	if (B->getHp() <= 0)	B->isAlive = false;
}

void Hero::AttackHero(Hero* enemy) {
	Skill* ability = SkillSelect();
	ability->Use(this, enemy);
}

void Hero::reset() {
	hp = s_hp;
	dmg = s_dmg;
	def = s_def;
	status = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	isAlive = true;
}

void Hero::AboutSkills() {
	int k = 0;
	while (k < GetSkillsCount()) {
		skills[k]->DescribeMe();
		k++;
	}
}

void Hero::checkStatus(int& damage)
{
	for (int i = 0; i < status.size(); i++) {
		if (status[i] > 0) {
			switch (i) {
			case FIREBALL:
				decreaseArmor(getArmor() / 2);
				
				status[FIREBALL]--;
				if (status[FIREBALL] == 0)	status[FIREBALL] = -1;
				break;

			case ICESHARDS:
				decreaseHp(damage / 2);
				status[ICESHARDS]--;
				break;

			case ROOTS:
				damage /= 2;
				status[ROOTS]--;
				break;

			case CURSE:
				damage += getDamage() / 2;
				increaseHp(getDamage() / 2);
				status[CURSE]--;
				break;

			case LASSO:
				decreaseArmor(getArmor());
				status[LASSO]--;
				if (status[LASSO] == 0)	status[LASSO] = -1;
				break;

			case POWERFULSHOT_BUFF:
				damage *= 1.5;
				status[POWERFULSHOT_BUFF]--;
				break;

			case POWERFULSHOT_DEBUFF:
				decreaseArmor(getArmor() / 2);
				status[POWERFULSHOT_DEBUFF]--;
				if (status[POWERFULSHOT_DEBUFF] == 0)	status[POWERFULSHOT_DEBUFF] = -1;
				break;

			case SHININGSHIELD:
				increaseArmor(20);
				status[SHININGSHIELD]--;
				if (status[SHININGSHIELD] == 0)	status[SHININGSHIELD] = -1;
				break;

			case SHRAPNEL:
				decreaseHp(getArmor());
				status[SHRAPNEL]--;
				break;
			}
		}
		if (status[i] == -1) {
			switch (i) {
			case FIREBALL:
				if ((status[LASSO] == 0) && (status[POWERFULSHOT_DEBUFF] == 0) && (status[SHININGSHIELD] == 0)) {
					resetArmor();
					status[FIREBALL] = 0;
				}
				break;

			case LASSO:
				if ((status[FIREBALL] == 0) && (status[POWERFULSHOT_DEBUFF] == 0) && (status[SHININGSHIELD] == 0)) {
					resetArmor();
					status[LASSO] = 0;
				}
				break;

			case POWERFULSHOT_DEBUFF:
				if ((status[LASSO] == 0) && (status[FIREBALL] == 0) && (status[SHININGSHIELD] == 0)) {
					resetArmor();
					status[POWERFULSHOT_DEBUFF] = 0;
				}
				break;

			case SHININGSHIELD:
				if ((status[LASSO] == 0) && (status[POWERFULSHOT_DEBUFF] == 0) && (status[FIREBALL] == 0)) {
					resetArmor();
					status[SHININGSHIELD] = 0;
				}
				break;
			}
		}
	}
}

void Hero::info() {
	std::cout << name << " :\tHealth: " << hp << "/" << s_hp << "\tArmor: " << def << "/" << s_def << "\tDamage: " << dmg << "/" << s_dmg << std::endl;
	std::cout << "Status: \t";
	for (int i = 0; i < status.size(); i++) {
		if (status[i] > 0) {
			switch (i) {
			case FIREBALL:std::cout << "FIREBALL "; break;
			case ICESHARDS:std::cout << "ICESHARDS "; break;
			case ROOTS:std::cout << "ROOTS "; break;
			case CURSE:std::cout << "CURSE "; break;
			case LASSO:std::cout << "LASSO "; break;
			case POWERFULSHOT_BUFF:std::cout << "POWERFULSHOT_BUFF "; break;
			case POWERFULSHOT_DEBUFF:std::cout << "POWERFULSHOT_DEBUFF "; break;
			case SHININGSHIELD:std::cout << "SHININGSHIELD "; break;
			case SHRAPNEL: std::cout << "SRAPNEL "; break;
			}
		}
	}
	std::cout << std::endl;
}

void Hero::specialSummonCheck(int damage, Hero* D) {
	if (status[SUMMON] > 0) {
		D->increaseArmor(damage);
		status[SUMMON]--;
		if (status[SUMMON] == 0)	status[SUMMON] = -1;
	}
	if (status[SUMMON] == -1)
		D->resetArmor();
}
