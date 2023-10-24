#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include "fonctions.h"
#include "grid.h"
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

int main()
{
        int c = 0;

        Grid grid;
        gridDisplay(grid.grid);
        cout << endl << endl;
        grid.grid = spawn(grid.grid);
        gridDisplay(grid.grid);

        while (1)
        {
            c = 0;

            switch (c = _getch()) {
            case KEY_UP:
                grid.gravity = "up";
                cout << grid.gravity << endl;
                break;
            case KEY_DOWN:
                grid.gravity = "down";
                cout << grid.gravity << endl;
                break;
            case KEY_LEFT:
                grid.gravity = "left";
                cout << grid.gravity << endl;
                break;
            case KEY_RIGHT:
                grid.gravity = "right";
                cout << grid.gravity << endl;
                break;
            default:
                break;
            }

        }

        return 0;
 












    /*Grid grid;
    gridDisplay(grid.grid);
    for (int x = 0; x < 8; x++) {
        cout << endl << endl;
        grid.grid = spawn(grid.grid);
        gridDisplay(grid.grid);
    }*/


}

