#pragma once
#include "Archer.h"

class Crossbowman : public Archer {
public:
	Crossbowman(std::string m_type, std::string m_name)
		: Archer(m_type, m_name) 
	{
		s_hp = hp = 175;
		s_dmg = dmg = 35;
		s_def = def = 10;
	}
};

