

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    
    vector<string> row1({ "00","01","02","03" });
    vector<string> row2({ "10","11","12","13" });
    vector<string> row3({ "20","21","22","23" });
    vector<string> row4({ "30","31","32","33" });
    
    vector<vector<string>> grid({ row1,row2,row3,row4 });

    for (int x = 0; x <= 3; x++) {
        for (int y = 0; y <= 3; y++) {
            cout << grid[x][y] << ',';
        }
        cout << endl;
    }


    //vector<vector<int>> ti;

    //cout << "\n";
     
}

