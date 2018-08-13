#pragma once

#include "stdafx.h"
#include <string>

using namespace std;

class Item
{
private:
	string m_name;
	int m_multiplier;
protected:
public:
	Item();
	Item(string name, int multiplier);

	void getInfo();
	int useItem(int multiplier);
};

class Food:Item
{
private:
protected:
public:
	Food();
	Food(string name, int multiplier);

	void getInfo();
	int useItem(int multiplier);
};

class Drink:Item
{
private:
protected:
public:
	Drink();
	Drink(string name, int multiplier);

	void getInfo();
	int useItem(int multiplier);
};

class Toy:Item
{
private:
protected:
public:
	Toy();
	Toy(string name, int multiplier);

	void getInfo();
	int useItem(int multiplier);
};