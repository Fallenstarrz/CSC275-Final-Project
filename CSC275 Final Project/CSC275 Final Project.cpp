// CSC275 Final Project.cpp : Defines the entry point for the console application.
//
// 1. Opening Screen with a description of the application and instructions
// 2. Menu for the user to choose options
// 3. 4 classes
// 4. inheritance (minimum of 2 derived classes)
// 5. Polymorphism
// 6. Encapsulation
// 7. File Input and Output
// 8. Templates
// 9. Exception Handling
// 
// I want a tamagochi clone

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

// Function for menu

int main() 
{
	cout << "Little Monster\n";
	cout << "Keep your new friend alive as long as you can!\n";
	cout << "You can feed, play and give drinks to it! \n";
	cout << "Most Importantly don't let his health reach 0, it goes down if his other stats get too low\n";

	// Class LittleMonster
	// 
	// Class Action
	// Class :: Feed
	// Class :: GiveWater
	// Class :: Play
	// 
	// Save Score to File as HighScore
	//		Score += time.DeltaTime
	// Template -> float &/|| int &/|| double
	// Exception on file I/O success

	cin.get();
	return 0;
}

