#include "Sword.h"

Sword::Sword(std::string _color)
{
	type = SWORD; 
	damage = 2; 
	this->color = _color; 
}

Sword* Sword::Decode(Json::Value json)
{
	return nullptr;
}
