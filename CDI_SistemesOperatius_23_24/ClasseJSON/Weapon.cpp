#include "Weapon.h"

Json::Value Weapon::Encode()
{
	Json::Value json = Json::Value(); 

	json["Damage"] = damage; 
	json["Range"] = range; 
	json["Type"] = type; 


	return json;
}
