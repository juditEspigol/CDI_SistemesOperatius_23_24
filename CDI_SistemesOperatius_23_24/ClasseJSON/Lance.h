#pragma once
#include "Weapon.h"
#include <string>

class Lance : public Weapon
{
public:
	std::string woodType = ""; 

	Lance(std::string _woodType); 

	virtual Json::Value Encode() override;
	static Lance* Decode(Json::Value json);
};

