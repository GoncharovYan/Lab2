#pragma once
#include "Skill.h"
class ShiningShield : public Skill {
public:
	ShiningShield() {
		name = "Shining Shield";
	}

	void DescribeMe() override;

	void Use(Hero* A, Hero* D) override;
};

