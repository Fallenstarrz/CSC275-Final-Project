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
#include "GameFunctions.h"

using namespace std;

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
