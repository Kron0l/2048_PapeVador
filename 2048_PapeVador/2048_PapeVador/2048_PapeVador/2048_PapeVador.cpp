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
    
    Grid grid;
    grid.Display();
    int c = 0;

        

    while (1)
    {
        c = 0;

        switch (c = _getch()) {
        case KEY_UP:
            grid.gravity = "up";
            grid.Gravity();
            grid.Spawn();
            grid.Display();

                
            break;

        case KEY_DOWN:
            grid.gravity = "down";
            grid.Gravity();
            grid.Spawn();
            grid.Display();

                
            break;

        case KEY_LEFT:
            grid.gravity = "left";
            grid.Gravity();
            grid.Spawn();
            grid.Display();

                
            break;

        case KEY_RIGHT:
            grid.gravity = "right";
            grid.Gravity();
            grid.Spawn();
            grid.Display();

                
            break;

        default:
            grid.gravity = "neutral";
            break;
        }
        cout << grid.gravity << endl;

    }

    grid.~Grid();

    return 0;
}