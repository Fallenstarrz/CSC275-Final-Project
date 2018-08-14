#pragma once

#include "stdafx.h"
#include <string>
#include "LittleMonster.h"

using namespace std;

// Parent Class for Items
class Item
{
private:
protected:
	string m_name;
	int m_multiplier;
public:
	Item();
	Item(string name, int multiplier);

	virtual void getInfo();
	virtual int useItem(int multiplier, LittleMonster& monster);
};

// Class for Food Items
class Food:Item
{
private:
protected:
public:
	Food();
	Food(string name, int multiplier);

	void getInfo();
	int useItem(int multiplier, LittleMonster& monster);
};

// Class for Drink Items
class Drink:Item
{
private:
protected:
public:
	Drink();
	Drink(string name, int multiplier);

	void getInfo();
	int useItem(int multiplier, LittleMonster& monster);
};

// Class for Toy Items
class Toy:Item
{
private:
protected:
public:
	Toy();
	Toy(string name, int multiplier);

	void getInfo();
	int useItem(int multiplier, LittleMonster& monster);
};