#pragma once

#include "Hero.h"

class Skill {
protected:
	std::string name;
public:
	virtual void DescribeMe() { std::cout << name << std::endl; }

	virtual void Use(Hero* A, Hero* D) = 0;
};

