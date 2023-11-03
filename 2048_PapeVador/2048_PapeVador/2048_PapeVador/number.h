#pragma once

#include <vector>
#include "GameObject.h"

using namespace std;
class Number : GameObject
{
public:
	//initialisation des valeurs publiques
	int value;
	vector<int> position;
	int merge = 0;
	
	//creation d'un Number
	Number(int value, int x, int y);

	//destruction d'un Number
	~Number();

};