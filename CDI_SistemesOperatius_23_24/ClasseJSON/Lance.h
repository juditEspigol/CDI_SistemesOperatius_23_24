#pragma once
#include "Weapon.h"
#include <string>

class Lance : public Weapon
{
public:
	std::string woodType = ""; 

	Lance(std::string _woodType); 

	Json::Value Encode();
	static Lance* Decode(Json::Value json);
};

