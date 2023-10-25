
#include <vector>
using namespace std;
class Number
{
public:
	int value;
	vector<int> position;

	//create number
	Number(int value, int x ,int y)
	{
		this->value = value;
		position.push_back (x);
		position.push_back (y);
	}

	//delete number
	~Number()
	{
	}
	
};