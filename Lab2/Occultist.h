#pragma once
#include "Wizzard.h"

class Occultist : public Wizzard {
public:
	Occultist(std::string m_type, std::string m_name)
		: Wizzard(m_type, m_name)
	{
		s_hp = hp = 125;
		s_dmg = dmg = 40;
		s_def = def = 5;
	}
};

