// CSC275 Final Project.cpp : Defines the entry point for the console application.
//
// 1. Opening Screen with a description of the application and instructions (DONE)
// 2. Menu for the user to choose options (DONE)
// 3. 4 classes (DONE)
// 4. inheritance (minimum of 2 derived classes) (DONE)
// 5. Polymorphism (DONE)
// 6. Encapsulation (DONE)
// 7. File Input and Output (Save & Load Features)
// 8. Exception Handling (CURRENTLY BUGGED)
// 9. Boost Library () still kind of a lofty requirement, not sure what to use...
// 
// I want a tamagochi clone

#include "stdafx.h"
#include <iostream>
#include <string>
#include "LittleMonster.h"
#include "Item.h"
#include <ctime>
#include <exception>

using namespace std;

void menu();
void choice();
void reduceStats(LittleMonster& monster, int randNum);

int main() 
{
	srand(static_cast<unsigned int>(time(0)));
	string monsterName;
	int randomInt = rand() % 10 + 1;

	cout << "Little Monster\n";
	cout << "Keep your new friend alive as long as you can!\n";
	cout << "You can feed, play and give drinks to it! \n";
	cout << "Most Importantly don't let his health reach 0, it goes down if his other stats get too low\n\n\n";

	cout << "What would you like to name your little monster?\n";
	cin >> monsterName;
	cout << endl;

	LittleMonster MyFriend(monsterName);
	MyFriend.display();
	system("pause");
	system("cls");

	while (MyFriend.dead() != true)
	{
		menu();
		choice();
		reduceStats(MyFriend, randomInt);
		MyFriend.display();

		cout << endl;
		cout << endl;
		system("cls");
	}

	cout << "Your friend has died\nI hope you choose to come back for another one!";

	system("pause");
	return 0;
}

void menu()
{
	cout << "1: Give Food\n";
	cout << "2: Give Drink\n";
	cout << "3: Play With\n";
	cout << "4: Next Day\n";
	cout << "5: Exit\n";
}

void choice()
{
	int selection = 0;
	string choice;
	cout << "Please make a selection as an int" << endl;
	cin >> choice;
	try
	{
		selection = stoi(choice);
		if (!isdigit(selection) || (selection < 1) || (selection < 5))
		{
			throw ("Invalid option selected. Please select a valid menu option\n");
		}
		switch (selection)
		{
		case 1: cout << "option 1 selected\n";
		case 2: cout << "option 2 selected\n";
		case 3: cout << "option 3 selected\n";
		case 4: cout << "option 4 selected\n";
		case 5: cout << "option 5 selected\n";
		}
	}
	catch (exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}
	catch (...)
	{

	}
}

void reduceStats(LittleMonster& monster, int randNum)
{
	int hunger = monster.getHunger();
	int thirst = monster.getThirst();
	int happiness = monster.getHappiness();
	int health = monster.getHealth();

	if (hunger <= 10 || thirst <= 10 || happiness >= 10)
	{
		monster.setHealth((health - randNum));
	}
	monster.setHunger((hunger - randNum));
	monster.setThirst((thirst - randNum));
	monster.setHappiness((happiness - randNum));
}