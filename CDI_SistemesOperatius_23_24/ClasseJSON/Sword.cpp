#include "Sword.h"

Sword::Sword(std::string _color)
{
	type = SWORD; 
	damage = 2; 
	this->color = _color; 
}

Json::Value Sword::Encode()
{
	Json::Value json = Weapon::Encode();

	json["Color"] = color;

	return json;
}

Sword* Sword::Decode(Json::Value json)
{
	std::string color = json["Color"].asString(); 

	Sword* sword = new Sword(color);

	return sword;
}
