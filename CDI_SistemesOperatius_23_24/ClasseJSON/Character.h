#pragma once
#include <string>
#include <iostream>
#include <json/json.h>
#include "Weapon.h"

class Character
{
public:
	int life = 0;
	int coin = 0;
	std::string name = ""; 

	std::vector<Weapon*>* weapons = new std::vector<Weapon*>(); 

	void PrintCharacter()
	{
		std::cout << "Life: " << life << std::endl;
		std::cout << "Coin: " << coin << std::endl;
		std::cout << "Name: " << name << std::endl;
	}

	Json::Value Encode(); 
	static Character* Decode(Json::Value json);
};

