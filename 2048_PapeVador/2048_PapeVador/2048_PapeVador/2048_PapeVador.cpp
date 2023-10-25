#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include "grid.h"
#include "common.h"

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


vector<Number> numberList;
Grid grid;
void gridDisplay(vector<vector<int>> grid);
vector<vector<int>> spawn(vector<vector<int>> grid);

vector<vector<int>> gravityDown(vector<vector<int>> grid);
vector<vector<int>> gravityLeft(vector<vector<int>> grid);
vector<vector<int>> gravityRight(vector<vector<int>> grid);
vector<vector<int>> gravityUp(vector<vector<int>> grid);


int main()
{
        int c = 0;

        gridDisplay(grid.grid);
        cout << endl << endl;

       while (1)
        {
            c = 0;

            switch (c = _getch()) {
            case KEY_UP:
                grid.gravity = "up";

                grid.grid = gravityUp(grid.grid);
                grid.grid = spawn(grid.grid);
                gridDisplay(grid.grid);
                break;

            case KEY_DOWN:
                grid.gravity = "down";

                grid.grid = gravityDown(grid.grid);
                grid.grid = spawn(grid.grid);
                gridDisplay(grid.grid);
                break;

            case KEY_LEFT:
                grid.gravity = "left";

                grid.grid = gravityLeft(grid.grid);
                grid.grid = spawn(grid.grid);
                gridDisplay(grid.grid);
                break;

            case KEY_RIGHT:
                grid.gravity = "right";

                grid.grid = gravityRight(grid.grid);
                grid.grid = spawn(grid.grid);
                gridDisplay(grid.grid);
                break;

            default:
                grid.gravity = "neutral";
                break;
            }
            cout << grid.gravity << endl;

        }

        return 0;
}

