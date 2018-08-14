#include "stdafx.h"
#include <iostream>
#include <string>
#include "LittleMonster.h"
#include "Item.h"
#include "GameFunctions.h"

using namespace std;

// Display menu for user
void menu()
{
	cout << "1: Give Food\n";
	cout << "2: Give Drink\n";
	cout << "3: Play With\n";
	cout << "4: Next Day\n";
	cout << "5: Exit\n";
}

// Process user input
void choice(LittleMonster& monster, int randNum)
{
	int selection;
	string choice;
	cout << "Please make a selection as an int" << endl;
	cin >> choice;
	// Exception block to catch invalid inputs
	try
	{
		selection = stoi(choice);
		// Switch on menu option
		switch (selection)
		{
		case 1:
		{
			Food foodItem("apple", 2);
			foodItem.useItem(2, monster);
			system("cls");
			monster.display();
			cout << endl;
			menu();
			break;
		}
		case 2:
		{
			Drink drinkItem("water", 2);
			drinkItem.useItem(2, monster);
			system("cls");
			monster.display();
			cout << endl;
			menu();
			break;
		}
		case 3:
		{
			Toy toyItem("car", 2);
			toyItem.useItem(2, monster);
			system("cls");
			monster.display();
			cout << endl;
			menu();
			break;
		}
		case 4:
		{
			reduceStats(monster, randNum);
			int age = monster.getAge();
			age++;
			monster.setAge(age);
			break;
		}
		case 5:
		{
			exit(0);
			break;
		}
		default:
		{
			cout << "Invalid option selected. Please select a valid menu option\n";
			break;
		}
		}
	}
	catch (...)
	{
		cout << "Not an integer, please select a valid menu option \n";
	}
}

// Reduce stats of your friendly monster
void reduceStats(LittleMonster& monster, int randNum)
{
	int hunger = monster.getHunger();
	int thirst = monster.getThirst();
	int happiness = monster.getHappiness();
	int health = monster.getHealth();

	// Check if we need to reduce health by checking if any of the stats are below 0
	if (hunger < 0 || thirst < 0 || happiness < 0)
	{
		monster.setHealth((health - randNum));
	}
	monster.setHunger((hunger - randNum));
	monster.setThirst((thirst - randNum));
	monster.setHappiness((happiness - randNum));
}