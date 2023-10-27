
#include <vector>
#include <string>
#include "number.h"
using namespace std;



class Grid
{
public:
	vector<vector<Number*>> grid;
	string gravity = "neutral";

	template<typename T>
	T Add(T value, T x, T y) {
		grid[x][y][0].value = value;
		return 0;
	}

	template<typename T>
	T Down(T deep, T x, T y) {
		grid[x][y + deep][0].value = grid[x][y][0].value;
		grid[x][y][0].value = 0;
		return 0;
	}
	template<typename T>
	T Up(T deep, T x, T y) {
		grid[x][y - deep][0].value = grid[x][y][0].value;
		grid[x][y][0].value = 0;
		return 0;
	}
	template<typename T>
	T Right(T deep, T x, T y) {
		grid[x + deep][y][0].value = grid[x][y][0].value;
		grid[x][y][0].value = 0;
		return 0;
	}
	template<typename T>
	T Left(T deep, T x, T y) {
		grid[x - deep][y][0].value = grid[x][y][0].value;
		grid[x][y][0].value = 0;
		return 0;
	}

	template<typename T>
	T MergeDown(T deep, T x, T y) {
		grid[x][y + deep][0].value = grid[x][y + deep][0].value*2;
		grid[x][y][0].value = 0;
		return 0;
	}
	template<typename T>
	T MergeUp(T deep, T x, T y) {
		grid[x][y - deep][0].value = grid[x][y - deep][0].value * 2;
		grid[x][y][0].value = 0;
		return 0;
	}
	template<typename T>
	T MergeRight(T deep, T x, T y) {
		grid[x + deep][y][0].value = grid[x + deep][y][0].value * 2;
		grid[x][y][0].value = 0;
		return 0;
	}
	template<typename T>
	T MergeLeft(T deep, T x, T y) {
		grid[x - deep][y][0].value = grid[x - deep][y][0].value * 2;
		grid[x][y][0].value = 0;
		return 0;
	}

	//create grid
	Grid()
	{
		for (int x = 0; x < 4; x++) {
			vector<Number*> row;
			for (int y = 0; y < 4; y++) {
				row.push_back(new Number(0, x, y));
			}
			grid.push_back(row);
		}
	}

	//display grid
	void Display()
	{
		system("cls");
		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++) {
				if (grid[x][y][0].value >10) {
					if (grid[x][y][0].value >100) {
						if (grid[x][y][0].value >1000) {
							cout << "|" << grid[x][y][0].value;
						}
						else {
							cout << "| " << grid[x][y][0].value;
						}
					}
					else {
						cout << "| " << grid[x][y][0].value << " ";
					}
				}
				else {
					cout << "|  " << grid[x][y][0].value << " ";
				}
			}
			cout << "|" << endl;
		}
		cout << endl << endl;
	}

	//insert value
	void Insert(int value, int x, int y) {
		Add<int>(value, x, y);
	}

	//spawn random 2 cells in empty cells with random value between 2 and 4
	void Spawn() {
		vector<int> possibleSpawn;
		srand(time(NULL));


		for (int x = 0; x < grid.size(); x++) {
			for (int y = 0; y < grid[x].size(); y++) {
				if (grid[x][y][0].value == 0) {
					possibleSpawn.push_back(y * 4 + x);
				}
			}
		}
		if (possibleSpawn.size() != 0) {
			for (int i = 0; i < 2; i++) {
				int randomSpawnPos = rand() % possibleSpawn.size();
				int spawnPos = possibleSpawn[randomSpawnPos];
				int spawnX = spawnPos % 4;
				int spawnY = spawnPos / 4;
				int value = ((rand() % 2) + 1) * 2;
				Add(value, spawnX, spawnY);
				possibleSpawn.erase(possibleSpawn.begin() + randomSpawnPos);
			}
		}
	}

	void Gravity() {
		if (gravity == "down") {
			for (int y = 2; y >= 0; y--) {
				for (int x = 0; x < 4; x++) {
					if (grid[x][y][0].value > 0) {
						if (grid[x][y + 1][0].value == 0) {
							if (y <= 1) {
								if (grid[x][y + 2][0].value == 0) {
									if (y == 0) {
										if (grid[x][y + 3][0].value == 0) {
											Down(3, x, y);
										}
										else if (grid[x][y][0].value == grid[x][y + 3][0].value) {
											MergeDown(3, x, y);
										}
										else {
											Down(2, x, y);
										}
									}
									else {
										Down(2, x, y);
									}
								}
								else if (grid[x][y][0].value == grid[x][y + 2][0].value) {
									MergeDown(2, x, y);
								}
								else {
									Down(1, x, y);
								}
							}
							else {
								Down(1, x, y);
							}
						}
						else if (grid[x][y][0].value == grid[x][y + 1][0].value) {
							MergeDown(1, x, y);
						}
					}
				}
			}
		}
		if (gravity == "up") {
			for (int y = 1; y <= 3; y++) {
				for (int x = 0; x < 4; x++) {
					if (grid[x][y][0].value > 0) {
						if (grid[x][y - 1][0].value == 0) {
							if (y >= 2) {
								if (grid[x][y - 2][0].value == 0) {
									if (y == 3) {
										if (grid[x][y - 3][0].value == 0) {
											Up(3, x, y);
										}
										else if (grid[x][y][0].value == grid[x][y - 3][0].value) {
											MergeUp(3, x, y);
										}
										else {
											Up(2, x, y);
										}
									}
									else {
										Up(2, x, y);
									}
								}
								else if (grid[x][y][0].value == grid[x][y - 2][0].value) {
									MergeUp(2, x, y);
								}
								else {
									Up(1, x, y);
								}
							}
							else {
								Up(1, x, y);
							}
						}
						else if (grid[x][y][0].value == grid[x][y - 1][0].value) {
							MergeUp(1, x, y);
						}
					}
				}
			}
		}
		if (gravity == "right") {
			for (int x = 2; x >= 0; x--) {
				for (int y = 0; y < 4; y++) {
					if (grid[x][y][0].value > 0) {
						if (grid[x + 1][y][0].value == 0) {
							if (x <= 1) {
								if (grid[x + 2][y][0].value == 0) {
									if (x == 0) {
										if (grid[x + 3][y][0].value == 0) {
											Right(3, x, y);
										}
										else if (grid[x][y][0].value == grid[x + 3][y][0].value) {
											MergeRight(3, x, y);
										}
										else {
											Right(2, x, y);
										}
									}
									else {
										Right(2, x, y);
									}
								}
								else if (grid[x][y][0].value == grid[x + 2][y][0].value) {
									MergeRight(2, x, y);
								}
								else {
									Right(1, x, y);
								}
							}
							else {
								Right(1, x, y);
							}
						}
						else if (grid[x][y][0].value == grid[x + 1][y][0].value) {
							MergeRight(1, x, y);
						}
					}
				}
			}
		}
		if (gravity == "left") {
			for (int x = 1; x <= 3; x++) {
				for (int y = 0; y < 4; y++) {
					if (grid[x][y][0].value > 0) {
						if (grid[x - 1][y][0].value == 0) {
							if (x >= 2) {
								if (grid[x - 2][y][0].value == 0) {
									if (x == 3) {
										if (grid[x - 3][y][0].value == 0) {
											Left(3, x, y);
										}
										else if (grid[x][y][0].value == grid[x - 3][y][0].value) {
											MergeLeft(3, x, y);
										}
										else {
											Left(2, x, y);
										}
									}
									else {
										Left(2, x, y);
									}
								}
								else if (grid[x][y][0].value == grid[x - 2][y][0].value) {
									MergeLeft(2, x, y);
								}
								else {
									Left(1, x, y);
								}
							}
							else {
								Left(1, x, y);
							}
						}
						else if (grid[x][y][0].value == grid[x - 1][y][0].value) {
							MergeLeft(1, x, y);
						}
					}
				}
			}
		}
	}

	//delete grid
	~Grid()
	{
	}

};