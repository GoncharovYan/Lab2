#pragma once
#include "Skill.h"
class Curse : public Skill {
public:
	Curse() {
		name = "Curse";
	}

	void DescribeMe() override;

	void Use(Hero* A, Hero* D) override;
};

