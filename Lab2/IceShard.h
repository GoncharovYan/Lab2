#pragma once
#include "Skill.h"
class IceShard : public Skill {
public:
	IceShard() {
		name = "Ice Shards";
	}

	void DescribeMe() override;

	void Use(Hero* A, Hero* D) override;

};

