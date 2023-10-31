#include "Lance.h"

Lance::Lance(std::string _woodType)
{
	type = LANCE;
	range = 2; 
	this->woodType = _woodType; 
}

Json::Value Lance::Encode()
{
	Json::Value json = Weapon::Encode();

	json["WoodType"] = woodType;

	return json;
}

Lance* Lance::Decode(Json::Value json)
{
	std::string woodType = json["WoodType"].asString(); 

	Lance* lance = new Lance(woodType); 

	return lance;
}
