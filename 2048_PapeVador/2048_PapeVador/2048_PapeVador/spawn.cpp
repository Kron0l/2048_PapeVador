#include <iostream>
#include <vector>
#include <string>
#include "number.h"
using namespace std;

vector<vector<int>> spawn(vector<vector<int>> grid){
    vector<number> numberList;
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

    int randomSpawnPos1 = rand() % possibleSpawn.size();
    int SpawnPos1 = possibleSpawn[randomSpawnPos1];

    possibleSpawn.erase(possibleSpawn.begin() + randomSpawnPos1);

    int randomSpawnPos2 = rand() % possibleSpawn.size();
    int SpawnPos2 = possibleSpawn[randomSpawnPos2];

    int Spawn1x = SpawnPos1 % 4;
    int Spawn1y = SpawnPos1 / 4;
    int Spawn2x = SpawnPos2 % 4;
    int Spawn2y = SpawnPos2 / 4;
    cout << SpawnPos1 << " ; " << Spawn1x << " ; " << Spawn1y << endl;
    cout << SpawnPos2 << " ; " << Spawn2x << " ; " << Spawn2y << endl;

    numberList.push_back(number(2, Spawn1x, Spawn1y));
    numberList.push_back(number(4, Spawn2x, Spawn2y));
    cout << "x = " << numberList[0].position[0] << " ; y = " << numberList[0].position[1] << " ; value = " << numberList[0].value << endl;
    cout << "x = " << numberList[1].position[0] << " ; y = " << numberList[1].position[1] << " ; value = " << numberList[1].value << endl;

    grid[numberList[0].position[0]][numberList[0].position[1]] = numberList[0].value;
    grid[numberList[1].position[0]][numberList[1].position[1]] = numberList[1].value;

    return grid;
}
