#include <iostream>
#include <vector>
#include <string>
#include "fonctions.h"

void gridDisplay(vector<vector<int>> grid) {
    for (int y = 0; y < grid.size(); y++) {
        for (int x = 0; x < grid[y].size(); x++) {
            if (grid[x][y] != 0) {
                cout << grid[x][y] << ',';
            }
            else {
                cout << " " << ',';
            }
        }
        cout << endl;
    }
}