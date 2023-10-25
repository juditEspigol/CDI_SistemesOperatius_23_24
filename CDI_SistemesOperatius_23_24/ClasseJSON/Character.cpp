#include "Character.h"

Json::Value Character::Encode()
{
	Json::Value json; 
	json["Life"] = life;
	json["Coin"] = coin;
	json["Name"] = name;

	Json::Value weaponsArray = Json::Value(Json::arrayValue); 
	for (Weapon* weapon : *weapons)
	{
		weaponsArray.append(weapon->Encode()); // push_back == append
	}
	json["Weapon"] = weaponsArray; 

	return json;
}

Character* Character::Decode(Json::Value json)
{
	Character* character = new Character();

	character->life = json["Life"].asInt();
	character->coin = json["Coin"].asInt();
	character->name = json["Name"].asString();

	Json::Value weaponsArray = json["Weapon"];
	for (Json::Value weaponJson : weaponsArray)
	{
		Weapon* weapon = Weapon::Decode(weaponJson); 
		character->weapons->push_back(weapon); 
	}

	return character;
}
