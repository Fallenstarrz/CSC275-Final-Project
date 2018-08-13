#include "stdafx.h"
#include "item.h"
#include <string>
#include "LittleMonster.h"

using namespace std;

// Base Item: Used to increase Health
Item::Item()
{

}
Item::Item(string name, int multiplier)
{

}
void Item::getInfo()
{

}
int Item::useItem(int multiplier, LittleMonster& newFriend)
{
	int numToAdd = multiplier * 10;
	int hunger = newFriend.getHunger();
	int thirst = newFriend.getThirst();
	int happiness = newFriend.getHappiness();
	newFriend.setHunger(hunger + numToAdd);
	newFriend.setThirst(thirst + numToAdd);
	newFriend.setHappiness(happiness + numToAdd);
	return 0;
}

// Food Item: Used to increase Hunger
Food::Food()
{

}
Food::Food(string name, int multiplier)
{

}
void Food::getInfo()
{

}
int Food::useItem(int multiplier, LittleMonster& newFriend)
{
	int numToAdd = multiplier * 10;
	int hunger = newFriend.getHunger();
	newFriend.setHunger(hunger + numToAdd);
	return 0;
}

// Drink Item: Used to increase Thirst
Drink::Drink()
{

}
Drink::Drink(string name, int multiplier)
{

}
void Drink::getInfo()
{

}
int Drink::useItem(int multiplier, LittleMonster& newFriend)
{
	int numToAdd = multiplier * 10;
	int thirst = newFriend.getThirst();
	newFriend.setThirst(thirst + numToAdd);
	return 0;
}

// Toy Item: Used to increase Happiness
Toy::Toy()
{

}
Toy::Toy(string name, int multiplier)
{

}
void Toy::getInfo()
{

}
int Toy::useItem(int multiplier, LittleMonster& newFriend)
{
	int numToAdd = multiplier * 10;
	int happiness = newFriend.getHappiness();
	newFriend.setHappiness(happiness + numToAdd);
	return 0;
}