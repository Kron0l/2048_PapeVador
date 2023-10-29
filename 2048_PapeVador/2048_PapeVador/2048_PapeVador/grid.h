
#include <vector>
#include <string>
#include "number.h"
#include <windows.h>
#include <bitset>
using namespace std;




class Grid
{
private:

	//initialisation des valeurs privées
	vector<vector<Number*>> grid;
public:

	//initialisation des valeurs publiques
	string gravity = "neutral";

	//initialisations des templates
	//ajout de tuile
	template<typename T>
	T Add(T value, T x, T y) {
		grid[x][y][0].value = value;
		//cout << "ok"<<endl;
		return 0;
	}

	//déplacement des tuiles
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

	//fusion des tuiles
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

	//création de la Grid
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

	//affichage de la Grid
	void Display()
	{
		//initlialisation des couleurs de la console
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		int color;

		//nettoyage de la console
		system("cls");

		//affichage de la grille en fonction de grid
		cout << (char)218;//"(char)Ascii_code" affiche le caractère correspondant au code ascii
		for (int j = 0; j < 3; j++) {
			for (int i = 0; i < 4; i++) {
				cout << (char)196;
			}
			cout << (char)194;
		}
		for (int i = 0; i < 4; i++) {
			cout << (char)196;
		}
		cout << (char)191;
		cout << endl;

		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++) {
					cout << (char)179;
					color = 11 - bitset<12>(grid[x][y][0].value).to_string().find("1");//calcul de quelle couleur doit être le chiffre
				if (grid[x][y][0].value > 0) {
					SetConsoleTextAttribute(hConsole, color);
					if (grid[x][y][0].value > 10) {
						if (grid[x][y][0].value > 100) {
							if (grid[x][y][0].value > 1000) {
								cout << grid[x][y][0].value;
							}
							else {
								cout << " " << grid[x][y][0].value;
							}
						}
						else {
							cout << " " << grid[x][y][0].value << " ";
						}
					}
					else {
						cout << "  " << grid[x][y][0].value << " ";
					}
				}
				else {
					cout << "    ";
				}
				SetConsoleTextAttribute(hConsole, 7);

			}
			if (y < 3) {
				cout << (char)179 << endl << (char)195;
				for (int j = 0; j < 3; j++) {
					for (int i = 0; i < 4; i++) {
						cout << (char)196;
					}
					cout << (char)197;
				}
				for (int i = 0; i < 4; i++) {
					cout << (char)196;
				}
				cout << (char)180;
				cout << endl;
			}
		}
		cout << (char)179 << endl << (char)192;
		for (int j = 0; j < 3; j++) {
			for (int i = 0; i < 4; i++) {
				cout << (char)196;
			}
			cout << (char)193;
		}
		for (int i = 0; i < 4; i++) {
			cout << (char)196;
		}
		cout << (char)217;

		cout << endl << endl;
	}

	//insertion d'une valeur dans la Grid
	void Insert(int value, int x, int y) {
		Add<int>(value, x, y);
	}

	//apparition d'une cellule contenant un chiffre étant soit 2 soit 4
	void Spawn() {
		//initialisation des valeurs
		vector<int> possibleSpawn;
		//initialisation de la fonction random
		srand(time(NULL));

		//check de la grille pour connaitre les cases vides (où le spawn est possible)
		for (int x = 0; x < grid.size(); x++) {
			for (int y = 0; y < grid[x].size(); y++) {
				if (grid[x][y][0].value == 0) {
					possibleSpawn.push_back(y * 4 + x);
				}
			}
		}

		//apparition aléatoire
		if (possibleSpawn.size() != 0) {
			int randomSpawnPos = rand() % possibleSpawn.size();
			int spawnPos = possibleSpawn[randomSpawnPos];
			int spawnX = spawnPos % 4;
			int spawnY = spawnPos / 4;
			int value = ((rand() % 2) + 1) * 2;
			Add(value, spawnX, spawnY);
		}
	}

	//déplacement des tuiles; renvoi 1 si il y a eu un mouvement et 0 si il n'y en a pas eu
	int Gravity(int move) {

		//déplacement vers le bas si il est possible
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
										else if (grid[x][y][0].value == grid[x][y + 3][0].value) {
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
								else if (grid[x][y][0].value == grid[x][y + 2][0].value) {
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
						else if (grid[x][y][0].value == grid[x][y + 1][0].value) {
							MergeDown(1, x, y);
							//cout << "merge1" << endl;
							move = 1;

						}
					}
				}
			}
		}

		//déplacement vers le haut si il est possible
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

		//déplacement vers la droite si il est possible
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

		//déplacement vers la gauche si il est possible
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

	//check si la partie est terminé; renvoie "victory" si il y a victoire, "loose" si il y a défaite et "false" si la partie n'est pas fini
	string End() {
		//initialisation des valeurs 
		string end = "false";
		int full = 1;
		int merge = 0;

		//check si il reste des cases vides ou une case égale à 2048
		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 4; y++) {
				//cout << "check move" << endl;
				if (grid[x][y][0].value == 0) {
					//cout << "move ok" << endl;
					full = 0;
				}
				if (grid[x][y][0].value == 2048) {
					//cout << "2048 ok" << endl;
					end="victory";
				}
			}
		}

		//check si une fusion est possible
		if (full && end!="victory") {
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

		//si aucun mouvement n'est possible est que la victoire n'est pas atteinte renvoi la défaite
		if (full == 1 && merge == 0 && end != "victory") {
			end = "loose";
		}
		return end;
	}

	//destruction de la Grid
	~Grid()
	{
	}

};