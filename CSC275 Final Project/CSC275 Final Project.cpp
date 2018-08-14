// CSC275 Final Project.cpp : Defines the entry point for the console application.
//
// 1. Opening Screen with a description of the application and instructions 
	//(Line 42 to 45, Used to display directions and introduce the game.)
// 2. Menu for the user to choose options 
	//(Line 79, used to display input options to the user)
// 3. 4 classes 
	//(Item.cpp/Item.h, Used when creating items & when creating your monster.)
// 4. inheritance (minimum of 2 derived classes) 
	//(Item.cpp/Item.h, Used in item creation)
// 5. Polymorphism 
	//(Item.cpp/Item.h, used to polymorph the useItem function)
// 6. Encapsulation 
	//(Item.cpp/Item.h, used to created objects to use in order to refill various stats)
// 7. File Input and Output 
	//(Line 69, used to save the age and name of your last run)
// 8. Exception Handling 
	//(Line 95, used to ensure that the input is a correct digit)
// 9. Boost Library 
	//(Line 35, Used to generate random numbers)
// 
// This is a small tamagotchi I built for my CSC275 final.

#include "stdafx.h"
#include <iostream>
#include <string>
#include "LittleMonster.h"
#include "Item.h"
#include <ctime>
#include "iostream"
#include <exception>
#include <fstream>
#include <boost/random/mersenne_twister.hpp> 
#include <boost/random/uniform_int_distribution.hpp>

using namespace std;

void menu();
void choice(LittleMonster& monster, int randNum);
void reduceStats(LittleMonster& monster, int randNum);

int main() 
{
	// Boost random number generator
	boost::random::mt19937 gen;
	boost::random::uniform_int_distribution<> rng(1, 10);
	string monsterName;
	int randomInt;

	// Intro & project overview
	cout << "Little Monster\n";
	cout << "Keep your new friend alive as long as you can!\n";
	cout << "You can feed, play and give drinks to it! \n";
	cout << "Most Importantly don't let his health reach 0, it goes down if his other stats get too low\n\n\n";

	cout << "What would you like to name your little monster?\n";
	cin >> monsterName;
	cout << endl;

	// create monster
	LittleMonster MyFriend(monsterName);
	MyFriend.display();
	system("pause");

	system("cls");

	// Game loop
	while (MyFriend.dead() != true)
	{
		randomInt = rng(gen);
		MyFriend.display();
		cout << endl;
		menu();
		choice(MyFriend, randomInt);

		system("cls");
	}
	ofstream highScores("HighScores.txt");
	highScores <<"Monster Name: " << MyFriend.getName() << " Age: " << MyFriend.getAge();
	highScores.close();
	cout << "Your friend has died\nI hope you choose to come back for another one!";

	system("pause");
	return 0;
}

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

	if (hunger < 0 || thirst < 0 || happiness < 0)
	{
		monster.setHealth((health - randNum));
	}
	monster.setHunger((hunger - randNum));
	monster.setThirst((thirst - randNum));
	monster.setHappiness((happiness - randNum));
}