#include <iostream>
#include <vector>
#include <string>
#include "fonctions.h"

void gridDisplay(vector<vector<int>> grid) {
    for (int x = 0; x < grid.size(); x++) {
        for (int y = 0; y < grid[x].size(); y++) {
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
