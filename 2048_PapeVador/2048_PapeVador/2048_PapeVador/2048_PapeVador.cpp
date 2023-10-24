#include <iostream>
#include <vector>
#include <string>
#include "fonctions.h"
using namespace std;

int main()
{
    
    vector<vector<int>> grid = gridCreation();
    gridDisplay(grid);
    for (int x = 0; x < 8; x++) {
        cout << endl << endl;
        grid = spawn(grid);
        gridDisplay(grid);
    }


}
