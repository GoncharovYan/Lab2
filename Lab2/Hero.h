#pragma once

#include <vector>
#include <string>
#include <iostream>

class Skill;

enum Abilities {
	FIREBALL,
	ICESHARDS,
	ROOTS,
	CURSE,
	LASSO,
	POWERFULSHOT_BUFF,
	POWERFULSHOT_DEBUFF,
	SHININGSHIELD,
	SHRAPNEL,
	SUMMON
};

enum EffectTime {
	ONE_TURN = 1,
	TWO_TURN = 2
};

class Hero {
protected:
	int hp, s_hp; //s_ - standart value to reset
	int dmg, s_dmg;
	int def, s_def;
	bool isAlive = true;
	std::vector<Skill*> skills;
	std::vector<int> status = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	std::string type;
	std::string name;

public:
	Hero(std::string m_type, std::string m_name)
		: type(m_type), name(m_name)
	{}
	void deathCheck(Hero* A, Hero* B);
	bool Alive() { return isAlive; }
	int getDamage() { return dmg; }
	int getArmor() { return def; }
	void resetArmor() { def = s_def; }
	int getHp() { return hp; }

	std::string getName() { return name; }
	std::string getType() { return type; }
	int GetSkillsCount() { return skills.size(); }

	void addSkill(Skill* sk) { skills.push_back(sk); }
	
	Skill* SkillSelect();
	void AttackHero(Hero* enemy);

	void reset();

	virtual void AboutSkills();
	void info();

	int resist(int damage) { return damage - (damage * (def / 100.0)); }

	void setStatus(int number, int time) { status[number] += time; }
	void checkStatus(int &damage);
	void specialSummonCheck(int damage, Hero* D);
	void decreaseHp(int count) { hp -= count; }
	void increaseHp(int count) { hp += count; }
	void increaseArmor(int count) { def += count; }
	void decreaseArmor(int count) { def += count; }
	void increaseDamage(int count) { dmg += count; }
	void decreaseDamage(int count) { dmg -= count; }

};

