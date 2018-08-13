#pragma once

#include "stdafx.h"
#include <string>

using namespace std;

class LittleMonster
{
private:
	string m_name;
	int m_hunger;
	int m_thirst;
	int m_happiness;
	int m_age;
	int m_health;

protected:

public:
	// Constructors
	LittleMonster();
	LittleMonster(string name);
	LittleMonster(string name, int hunger, int thirst, int happiness, int age, int health);

	// Getters
	string getName();
	int getHunger();
	int getThirst();
	int getHappiness();
	int getAge();
	int getHealth();

	// Setters
	void setName(string name);
	void setHunger(int hunger);
	void setThirst(int hunger);
	void setHappiness(int happiness);
	void setAge(int age);
	void setHealth(int health);

	// Display
	void display();

	// Functions
	bool dead();
};