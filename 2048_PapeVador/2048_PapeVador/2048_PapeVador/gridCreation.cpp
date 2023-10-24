#include <iostream>
#include <vector>
#include <string>
#include "fonctions.h"
using namespace std;

vector<vector<int>> gridCreation() {
    

    vector<int> col1({ 0,0,0,0 });
    vector<int> col2({ 0,0,0,0 });
    vector<int> col3({ 0,0,0,0 });
    vector<int> col4({ 0,0,0,0 });

    vector<vector<int>> grid({ col1,col2,col3,col4 });
return grid;
}