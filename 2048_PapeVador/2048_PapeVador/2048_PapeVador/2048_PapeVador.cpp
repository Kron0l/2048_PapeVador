#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include "grid.h"

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77




int main()
{
    //intialisation des valeurs par défaut
    string gamemode = "menu";
    string end = "false";

    
    while (gamemode != "stop") {

        //boucle de menu
        if (gamemode == "menu")
        {
            //initialisation valeurs du menu
            bool a = 0;
            string choice;
            string row1 = "=================================";
            string row2 = "         Welcome on 2048         ";
            string row3 = "=================================";
            system("cls");
            cout << row1 << endl << row2 << endl << row3 << endl;
            while (!a) {
                cout << "Want you to play a game? (y/n)" << endl;
                cin >> choice;
                if (choice == "y") {
                    gamemode = "game";
                }
                else if (choice == "n") {
                    gamemode = "stop";
                }
                a = choice == "y" || choice == "n";
            }
        }


        //boucle de jeu
        if (gamemode == "game")
        {
            //initialisation valeurs du jeu
            cout << gamemode << endl;
            int move = 0;
            Grid grid;
            grid.Spawn();
            grid.Display();
            int c = 0;

            while (gamemode == "game")
            {
                move = 0;
                c = 0;

                //contrôles
                switch (c = _getch()) {

                    case KEY_UP:
                        grid.gravity = "up";
                        move = grid.Gravity(move);
                        if (move) {
                            grid.Spawn();
                        }
                        grid.Display();
                        end = grid.End();
                        break;

                    case KEY_DOWN:
                        grid.gravity = "down";
                        move = grid.Gravity(move);
                        if (move) {
                            grid.Spawn();
                        }
                        grid.Display();
                        end = grid.End();
                        break;

                    case KEY_LEFT:
                        grid.gravity = "left";
                        move = grid.Gravity(move);
                        if (move) {
                            grid.Spawn();
                        }
                        grid.Display();
                        end = grid.End();
                        break;

                    case KEY_RIGHT:
                        grid.gravity = "right";
                        move = grid.Gravity(move);
                        if (move) {
                            grid.Spawn();
                        }
                        grid.Display();
                        end = grid.End();
                        break;

                    default:
                        grid.gravity = "neutral";
                        break;
                }

                //fin de jeu affichage victoire ou défaite et sortie du jeu
                if (grid.gravity != "neutral" && end != "false") {
                    if (end == "victory") {
                        cout << "Congratulation for you're beautifull win !!!!" << endl;
                    }else if (end == "loose") {
                        cout << "Haha looser" << endl;
                    }
                    cout << "Enter anything to continue" << endl;
                    string b;
                    cin >> b;
                    if (b.size() > 0) {
                        gamemode = "menu";
                    }
                    
                }

            }

            //destruction de la grid
            grid.~Grid();
        }
    }

    return 0;
}