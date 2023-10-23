#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    
    vector<int> row1({ 0,0,0,0});
    vector<int> row2({ 0,0,0,0});
    vector<int> row3({ 0,0,0,0 });
    vector<int> row4({ 0,0,0,0 });
    
    vector<vector<int>> grid({ row1,row2,row3,row4 });

    for (int x = 0; x <= 3; x++) {
        for (int y = 0; y <= 3; y++) {
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

