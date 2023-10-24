
#include <vector>
using namespace std;
class number
{
public:
	int value;
	vector<int> position;

	//create number
	number(int value, int x ,int y)
	{
		this->value = value;
		position.push_back (x);
		position.push_back (y);
	}

	//delete number
	~number()
	{
	}
	
};