#include "stdafx.h"
#include "LittleMonster.h"
#include <string>
#include <iostream>

using namespace std;

// LittleMonster Constructors
LittleMonster::LittleMonster()
{

}
LittleMonster::LittleMonster(string name) // On New
{
	m_name = name;
	m_hunger = 100;
	m_thirst = 100;
	m_happiness = 100;
	m_age = 0;
	m_health = 100;
}
LittleMonster::LittleMonster(string name, int hunger, int thirst, int happiness, int age, int health) // On Load
{
	m_name = name;
	m_hunger = hunger;
	m_thirst = thirst;
	m_happiness = happiness;
	m_age = age;
	m_health = health;
}



// LittleMonster Getters
string LittleMonster::getName()
{
	return m_name;
}
int LittleMonster::getHunger()
{
	return m_hunger;
}
int LittleMonster::getThirst()
{
	return m_thirst;
}
int LittleMonster::getHappiness()
{
	return m_happiness;
}
int LittleMonster::getAge()
{
	return m_age;
}
int LittleMonster::getHealth()
{
	return m_health;
}



// LittleMonster Setters
void LittleMonster::setName(string name)
{
	m_name = name;
}
void LittleMonster::setHunger(int hunger)
{
	m_hunger = hunger;
}
void LittleMonster::setThirst(int thirst)
{
	m_thirst = thirst;
}
void LittleMonster::setHappiness(int happiness)
{
	m_happiness = happiness;
}
void LittleMonster::setAge(int age)
{
	m_age = age;
}
void LittleMonster::setHealth(int health)
{
	m_health = health;
}



// LittleMonster Display
void LittleMonster::display()
{
	cout << "Name: " << m_name <<endl;
	cout << "Hunger: " << m_hunger << endl;
	cout << "Thirst: " << m_thirst << endl;
	cout << "Happiness: " << m_happiness << endl;
	cout << "Age: " << m_age << endl;
	cout << "Health: " << m_health << endl;
}

bool LittleMonster::dead()
{
	if (m_health <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}