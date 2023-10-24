
#include <vector>
#include <string>
using namespace std;
class Grid
{
public:
	vector<vector<int>> grid;
	string gravity;

	//create grid
	Grid()
	{
		gravity = "down";
		for (int i = 0; i < 4; i++) {
			vector<int> row({ 0,0,0,0 });
			grid.push_back(row);
		}
	}

	//delete grid
	~Grid()
	{
	}

};