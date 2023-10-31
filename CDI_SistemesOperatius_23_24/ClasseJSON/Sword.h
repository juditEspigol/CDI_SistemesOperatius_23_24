#pragma once
#include "Weapon.h"
#include <string>

class Sword : public Weapon
{
public:
	std::string color = ""; 

	Sword(std::string _color); 

	virtual Json::Value Encode() override;
	static Sword* Decode(Json::Value json);
};

