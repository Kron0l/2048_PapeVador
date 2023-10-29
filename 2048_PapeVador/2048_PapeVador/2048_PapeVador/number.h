
#include <vector>
#include <bitset>
using namespace std;
class Number
{
public:
	//initialisation des valeurs publiques
	int value;
	vector<int> position;

	//creation d'un Number
	Number(int value, int x ,int y)
	{
		this->value = value;
		position.push_back (x);
		position.push_back (y);
	}

	//destruction d'un Number
	~Number()
	{
	}
	
};