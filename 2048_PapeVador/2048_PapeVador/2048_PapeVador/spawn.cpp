#include <iostream>
#include <vector>
#include <string>
#include "number.h"
using namespace std;

vector<vector<int>> spawn(vector<vector<int>> grid){
    vector<Number> numberList;
    srand(time(NULL));
    vector<int> possibleSpawn;
    for (int x = 0; x < grid.size(); x++) {
        for (int y = 0; y < grid[x].size(); y++) {
            if (grid[x][y] == 0) {
                possibleSpawn.push_back(y * 4 + x);
                cout << x * 4 + y<< " ; ";
            }
        }
    }
    cout << endl;

    for (int i = 0; i < 2; i++) {
        int randomSpawnPos = rand() % possibleSpawn.size();
        int spawnPos = possibleSpawn[randomSpawnPos];
        int spawnX = spawnPos % 4;
        int spawnY = spawnPos / 4;
        int value = ((rand() % 2) + 1) * 2;
        cout << spawnPos << " ; " << spawnX << " ; " << spawnY << endl;
        numberList.push_back(Number(value, spawnX, spawnY));
        cout << "x = " << spawnX << " ; y = " << spawnY << " ; value = " << value << endl;
        grid[spawnX][spawnY] = value;
        cout << grid[spawnX][spawnY] << endl;
        possibleSpawn.erase(possibleSpawn.begin() + randomSpawnPos);
    }

    return grid;
}