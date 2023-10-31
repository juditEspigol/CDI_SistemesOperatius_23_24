#include <iostream>
#include <fstream>
#include <json/json.h>

#include "Character.h"
#include "Lance.h"
#include "Sword.h"

void CreateBaseCharacter();
void ReadBaseCharacter();

int main()
{
	//CreateBaseCharacter(); 
	ReadBaseCharacter(); 
}

void CreateBaseCharacter()
{
	Character* character = new Character(); 
	character->life = 5; 
	character->coin = 611; 
	character->name = "Chikito"; 

	Sword* sword = new Sword("Plateada"); 
	Lance* lance1 = new Lance("Pino"); 
	Lance* lance2 = new Lance("Roble"); 

	character->weapons->push_back(sword); 
	character->weapons->push_back(lance1); 
	character->weapons->push_back(lance2); 

	// No hacer values puntreos con jason
	Json::Value json; 
	/*json["Life"] = character->life; 
	json["Coin"] = character->coin; 
	json["Name"] = character->name; */
	json["Character"] = character->Encode(); 

	std::ofstream jsonWriteFile = std::ofstream("Character.json", std::ios::binary); 

	if (!jsonWriteFile.fail())
	{
		jsonWriteFile << json; 
		jsonWriteFile.close(); 
	}
}

void ReadBaseCharacter()
{
	//Character* character = new Character();

	std::ifstream jsonReadFile = std::ifstream("Character.json", std::ios::binary);

	if (!jsonReadFile.fail())
	{
		Json::Value json;
		jsonReadFile >> json; 
		jsonReadFile.close(); 

		/*character->life = json["Life"].asInt(); 
		character->coin = json["Coin"].asInt(); 
		character->name = json["Name"].asString(); */
		Character* character = Character::Decode(json["Character"]); 

	}
}
