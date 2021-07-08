#pragma once
#include "Skill.h"
class Lasso : public Skill {
public:
	Lasso() {
		name = "Lasso";
	}

	void DescribeMe() override;

	void Use(Hero* A, Hero* D) override;
};

