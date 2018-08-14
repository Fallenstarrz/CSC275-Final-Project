#pragma once

#include "stdafx.h"
#include <iostream>
#include "LittleMonster.h"

using namespace std;

void menu();
void choice(LittleMonster& monster, int randNum);
void reduceStats(LittleMonster& monster, int randNum);