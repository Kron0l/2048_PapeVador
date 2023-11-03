#pragma once

#include <vector>
#include <string>
#include <windows.h>
#include <bitset>
#include <SDL.h>
#include <time.h>
#include "number.h"
using namespace std;




class Grid : GameObject
{
private:
	vector<vector<Number*>> grid;

	//initialisation des valeurs priv?es
public:
	//initialisation des valeurs publiques
	string gravity = "neutral";
	//initialisations des templates
	template<typename T>
	T Add(T value, T x, T y);

	//deplacement des tuiles
	template<typename T>
	T Down(T deep, T x, T y);
	template<typename T>
	T Up(T deep, T x, T y);
	template<typename T>
	T Right(T deep, T x, T y);
	template<typename T>
	T Left(T deep, T x, T y);

	//fusion des tuiles
	template<typename T>
	T MergeDown(T deep, T x, T y);
	template<typename T>
	T MergeUp(T deep, T x, T y);
	template<typename T>
	T MergeRight(T deep, T x, T y);
	template<typename T>
	T MergeLeft(T deep, T x, T y);
	

	//creation de la Grid
	Grid();
		
	//affichage de la Grid
	void Display(SDL_Texture** spriteList, SDL_Renderer* renderer);

	//insertion d'une valeur dans la Grid
	void Insert(int value, int x, int y);

	//apparition d'une cellule contenant un chiffre ?tant soit 2 soit 4
	void Spawn();

	//deplacement des tuiles; renvoi 1 si il y a eu un mouvement et 0 si il n'y en a pas eu
	int Gravity(int move);

	//check si la partie est terminee; renvoie "victory" si il y a victoire, "loose" si il y a defaite et "false" si la partie n'est pas finie
	string End();

	//destruction de la Grid
	~Grid();
};
