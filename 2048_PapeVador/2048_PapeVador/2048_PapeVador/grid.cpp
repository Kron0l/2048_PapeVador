#include "grid.h"



template<typename T>
T Grid::Add(T value, T x, T y) {
	grid[x][y][0].value = value;
	//cout << "ok"<<endl;
	return 0;
}

//d?placement des tuiles
template<typename T>
T Grid::Down(T deep, T x, T y) {
	grid[x][y + deep][0].value = grid[x][y][0].value;
	grid[x][y][0].value = 0;
	return 0;
}
template<typename T>
T Grid::Up(T deep, T x, T y) {
	grid[x][y - deep][0].value = grid[x][y][0].value;
	grid[x][y][0].value = 0;
	return 0;
}
template<typename T>
T Grid::Right(T deep, T x, T y) {
	grid[x + deep][y][0].value = grid[x][y][0].value;
	grid[x][y][0].value = 0;
	return 0;
}
template<typename T>
T Grid::Left(T deep, T x, T y) {
	grid[x - deep][y][0].value = grid[x][y][0].value;
	grid[x][y][0].value = 0;
	return 0;
}

//fusion des tuiles
template<typename T>
T Grid::MergeDown(T deep, T x, T y) {
	if (grid[x][y][0].merge == 0) {
		grid[x][y + deep][0].value = grid[x][y + deep][0].value * 2;
		grid[x][y][0].value = 0;
		grid[x][y][0].merge = 1;
	}

	return 0;
}
template<typename T>
T Grid::MergeUp(T deep, T x, T y) {
	if (grid[x][y][0].merge == 0) {
		grid[x][y - deep][0].value = grid[x][y - deep][0].value * 2;
		grid[x][y][0].value = 0;
		grid[x][y][0].merge = 1;
	}
	return 0;
}
template<typename T>
T Grid::MergeRight(T deep, T x, T y) {

	if (grid[x][y][0].merge == 0) {
		grid[x + deep][y][0].value = grid[x + deep][y][0].value * 2;
		grid[x][y][0].value = 0;
		grid[x][y][0].merge = 1;
	}
	return 0;
}
template<typename T>
T Grid::MergeLeft(T deep, T x, T y) {
	if (grid[x][y][0].merge == 0) {
		grid[x - deep][y][0].value = grid[x - deep][y][0].value * 2;
		grid[x][y][0].value = 0;
		grid[x][y][0].merge = 1;
	}
	return 0;
}

//creation de la Grid
Grid::Grid()
{
	x = 0;
	y = 0;
	sizeX = 552;
	sizeY = 552;

	for (int x = 0; x < 4; x++) {
		vector<Number*> row;
		for (int y = 0; y < 4; y++) {
			row.push_back(new Number(0, x, y));
		}
		grid.push_back(row);
	}
}

//affichage de la Grid
void Grid::Display(SDL_Texture** spriteList, SDL_Renderer* renderer)
{
	int length = 4;
	int height = 4;
	int gridSize = sizeX;
	int cellSize = 128;
	int asset;

	SDL_Rect squareGrid = { 0, 0, gridSize, gridSize };
	SDL_Rect squareCell = { 0, 0, cellSize, cellSize };
	SDL_Texture* cellTexture = NULL;
	cellTexture = spriteList[0];
	SDL_RenderCopy(renderer, cellTexture, NULL, &squareGrid);
	for (int y = 0; y < 4; y++) {
		squareCell.y = y * cellSize + (y + 1) * 8;
		for (int x = 0; x < 4; x++) {
			if (grid[x][y][0].value != 0) {
				asset = 11 - bitset<12>(grid[x][y][0].value).to_string().find("1");
				squareCell.x = x * cellSize + (x + 1) * 8;
				cellTexture = spriteList[asset];
				SDL_RenderCopy(renderer, cellTexture, NULL, &squareCell);
			}
		}
	}
	SDL_RenderPresent(renderer);

}

//insertion d'une valeur dans la Grid
void Grid::Insert(int value, int x, int y) {
	Add<int>(value, x, y);
}

//apparition d'une cellule contenant un chiffre ?tant soit 2 soit 4
void Grid::Spawn() {
	//initialisation des valeurs
	vector<int> possibleSpawn;
	//initialisation de la fonction random
	srand(time(NULL));

	//check de la grille pour connaitre les cases vides (o? le spawn est possible)
	for (int x = 0; x < grid.size(); x++) {
		for (int y = 0; y < grid[x].size(); y++) {
			if (grid[x][y][0].value == 0) {
				possibleSpawn.push_back(y * 4 + x);
			}
		}
	}

	//apparition al?atoire
	if (possibleSpawn.size() != 0) {
		int randomSpawnPos = rand() % possibleSpawn.size();
		int spawnPos = possibleSpawn[randomSpawnPos];
		int spawnX = spawnPos % 4;
		int spawnY = spawnPos / 4;
		int value = ((rand() % 2) + 1) * 2;
		Add(value, spawnX, spawnY);
	}
}

//deplacement des tuiles; renvoi 1 si il y a eu un mouvement et 0 si il n'y en a pas eu
int Grid::Gravity(int move) {

	//d?placement vers le bas si il est possible
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
										//cout << "down3" << endl;
										move = 1;
									}
									else if (grid[x][y][0].value == grid[x][y + 3][0].value && grid[x][y+3][0].merge == 0 ) {
										MergeDown(3, x, y);
										//cout << "merge3" << endl;
										move = 1;
									}
									else {
										Down(2, x, y);
										//cout << "down2" << endl;
										move = 1;
									}
								}
								else {
									Down(2, x, y);
									//cout << "down2" << endl;
									move = 1;
								}
							}
							else if (grid[x][y][0].value == grid[x][y + 2][0].value && grid[x][y + 2][0].merge == 0) {
								MergeDown(2, x, y);
								//cout << "merge2" << endl;
								move = 1;
							}
							else {
								Down(1, x, y);
								move = 1;
								//cout << "down1" << endl;
							}
						}
						else {
							Down(1, x, y);
							//cout << "down1" << endl;
							move = 1;
						}
					}
					else if (grid[x][y][0].value == grid[x][y + 1][0].value && grid[x][y + 1][0].merge == 0) {
						MergeDown(1, x, y);
						//cout << "merge1" << endl;
						move = 1;

					}
				}
			}
		}
	}

	//d?placement vers le haut si il est possible
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
										//cout << "up3" << endl;
										move = 1;
									}
									else if (grid[x][y][0].value == grid[x][y - 3][0].value) {
										MergeUp(3, x, y);
										//cout << "merge3" << endl;
										move = 1;
									}
									else {
										Up(2, x, y);
										//cout << "up2" << endl;
										move = 1;
									}
								}
								else {
									Up(2, x, y);
									//cout << "up2" << endl;
									move = 1;
								}
							}
							else if (grid[x][y][0].value == grid[x][y - 2][0].value) {
								MergeUp(2, x, y);
								//cout << "merge2" << endl;
								move = 1;
							}
							else {
								Up(1, x, y);
								//cout << "up1" << endl;
								move = 1;
							}
						}
						else {
							Up(1, x, y);
							//cout << "up1" << endl;
							move = 1;
						}
					}
					else if (grid[x][y][0].value == grid[x][y - 1][0].value) {
						MergeUp(1, x, y);
						//cout << "merge1" << endl;
						move = 1;
					}
				}
			}
		}
	}

	//d?placement vers la droite si il est possible
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
										//cout << "right3" << endl;
										move = 1;
									}
									else if (grid[x][y][0].value == grid[x + 3][y][0].value) {
										MergeRight(3, x, y);
										//cout << "merge3" << endl;
										move = 1;
									}
									else {
										Right(2, x, y);
										//cout << "right2" << endl;
										move = 1;
									}
								}
								else {
									Right(2, x, y);
									//cout << "right2" << endl;
									move = 1;
								}
							}
							else if (grid[x][y][0].value == grid[x + 2][y][0].value) {
								MergeRight(2, x, y);
								//cout << "merge2" << endl;
								move = 1;
							}
							else {
								Right(1, x, y);
								//cout << "right1" << endl;
								move = 1;
							}
						}
						else {
							Right(1, x, y);
							//cout << "right1" << endl;
							move = 1;
						}
					}
					else if (grid[x][y][0].value == grid[x + 1][y][0].value) {
						MergeRight(1, x, y);
						//cout << "merge1" << endl;
						move = 1;
					}
				}
			}
		}
	}

	//d?placement vers la gauche si il est possible
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
										//cout << "left3" << endl;
										move = 1;
									}
									else if (grid[x][y][0].value == grid[x - 3][y][0].value) {
										MergeLeft(3, x, y);
										//cout << "merge3" << endl;
										move = 1;
									}
									else {
										Left(2, x, y);
										//cout << "left2" << endl;
										move = 1;
									}
								}
								else {
									Left(2, x, y);
									//cout << "left2" << endl;
									move = 1;
								}
							}
							else if (grid[x][y][0].value == grid[x - 2][y][0].value) {
								MergeLeft(2, x, y);
								//cout << "merge2" << endl;
								move = 1;
							}
							else {
								Left(1, x, y);
								//cout << "left1" << endl;
								move = 1;
							}
						}
						else {
							Left(1, x, y);
							//cout << "left1" << endl;
							move = 1;
						}
					}
					else if (grid[x][y][0].value == grid[x - 1][y][0].value) {
						MergeLeft(1, x, y);
						//cout << "merge1" << endl;
						move = 1;
					}
				}
			}
		}
	}

	return move;
}

//check si la partie est terminee; renvoie "victory" si il y a victoire, "loose" si il y a defaite et "false" si la partie n'est pas finie
string Grid::End() {
	//initialisation des valeurs 
	string end = "false";
	int full = 1;
	int merge = 0;

	//check si il reste des cases vides ou une case ?gale ? 2048
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			//cout << "check move" << endl;
			if (grid[x][y][0].value == 0) {
				//cout << "move ok" << endl;
				full = 0;
			}
			if (grid[x][y][0].value == 2048) {
				//cout << "2048 ok" << endl;
				end = "victory";
			}
		}
	}

	//check si une fusion est possible
	if (full && end != "victory") {
		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 4; y++) {
				//cout << "check merge" << endl;
				if (x < 3) {
					if (grid[x][y][0].value == grid[x + 1][y][0].value) {
						merge = 1;
						//cout << "merge" << endl;
					}
				}
				if (x > 0) {
					if (grid[x][y][0].value == grid[x - 1][y][0].value) {
						merge = 1;
						//cout << "merge" << endl;
					}
				}
				if (y < 3) {
					if (grid[x][y][0].value == grid[x][y + 1][0].value) {
						merge = 1;
						//cout << "merge" << endl;
					}
				}
				if (y > 0) {
					if (grid[x][y][0].value == grid[x][y - 1][0].value) {
						merge = 1;
						//cout << "merge" << endl;
					}
				}

			}
		}
	}

	//si aucun mouvement n'est possible est que la victoire n'est pas atteinte renvoi la d?faite
	if (full == 1 && merge == 0 && end != "victory") {
		end = "loose";
	}
	return end;
}

//destruction de la Grid
Grid::~Grid()
{
}