#pragma once
#include "json/json.h"
#include "Weapon.h"

static class WeaponBuilder
{
public: 
	static Weapon* CreateWepaonFromJson(Json::Value json); 
};

