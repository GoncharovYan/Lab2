#pragma once
#include "Skill.h"
class Shrapnel : public Skill {
public:
	Shrapnel() {
		name = "Shrapnel";
	}

	void DescribeMe() override;

	void Use(Hero* A, Hero* D) override;
};

