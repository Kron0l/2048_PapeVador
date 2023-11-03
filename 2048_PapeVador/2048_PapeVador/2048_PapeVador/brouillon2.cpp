//// Fake booleans go brr
//#define TRUE  1
//#define FALSE 0
//typedef int Bool;
//
//// Importing stdio, stdlib and a bunch of SDL libraries
//#include <iostream>
//#include <stdlib.h>
//#include <vector>
//#include <string>
//#include <SDL.h>
//#include <SDL_image.h>
//
//using namespace std;
//
//// Global SDL stuff
//SDL_Window* window = NULL;
//
//// Function prototypes
///*~SDL~*/  Bool initSDL(int screenWidth, int screenHeight);
///*~SDL~*/  SDL_Surface* loadBMP(const char* path);
///*~SDL~*/  void closeWindow();
///*>NIP<*/  void FillGrid(vector<int> grid);
///*>NIP<*/  void DisplayGrid(vector<int> grid, SDL_Texture** spriteList, SDL_Renderer* renderer);
///*>NIP<*/  void Dig(int length, int height, int* grid, int targetAbs, int targetOrd);
///*>NIP<*/  int FlagCounter(int length, int height, int* grid, int targetAbs, int targetOrd);
//
//
//// Initializing SDL
//Bool initSDL(int screenWidth, int screenHeight)
//{
//	Bool success = TRUE;
//	if (SDL_Init(SDL_INIT_VIDEO) < 0)
//	{
//		cout << "SDL could not be initialized ! SDL_Error : " << SDL_GetError() << endl;
//		success = FALSE;
//	}
//	else
//	{
//		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
//		if (window == NULL)
//		{
//			cout << "Window could not be created ! SDL_Error : " << SDL_GetError() << endl;
//			success = FALSE;
//		}
//	}
//	return success;
//}
//
//void closeWindow()
//{
//	SDL_DestroyWindow(window);
//	window = NULL;
//
//	SDL_Quit();
//}
//
//// Loads a BMP just the same, but prints out whatever could have gone wrong
//SDL_Surface* loadBMP(const char* filePath)
//{
//	Bool success = TRUE;
//
//	SDL_Surface* surface = NULL;
//	surface = SDL_LoadBMP(filePath);
//	if (surface == NULL)
//	{
//		cout << "Unable to load image " << filePath << "!SDL_Error : " << SDL_GetError() << endl;
//	}
//
//	return surface;
//}
//
//// Fills the grid with random mines positions and only hidden cells
//void FillGrid(vector<int> grid)
//{
//	int mines = 10;
//	int length = 4;
//	int height = 4;
//	int x, y, coord, minePlaced = mines;
//
//	// Fills the whole grid with the code 30 (which represents a Hidden No-Bomb cell)
//	for (int ord = 0; ord < height; ord++)
//	{
//		for (int abs = 0; abs < length; abs++)
//		{
//			coord = abs + ord * length;
//			grid[coord] = 30;
//		}
//	}
//
//	// Increment cells at random by 1, which creates 31 (which represents a Hidden With-Bomb cell), effectively placing the amount of mines desired
//	for (minePlaced; minePlaced > 0; minePlaced--)
//	{
//		coord = (rand() % length) + (rand() % height) * length;
//
//		if (grid[coord] != 31)
//		{
//			grid[coord] += 1;
//		}
//		else
//		{
//			minePlaced++;
//		}
//	}
//
//
//	// Remove commentary to fill first 10 cells of a board with everything a cell can display. In order : Neighbor indicator from 1 to 8, Flag, Empty, Bomb, Detonated Bomb
//	// The rest of the cells are Hidden
//
//	/*grid[0] = 1;
//	grid[1] = 2;
//	grid[2] = 3;
//	grid[3] = 4;
//	grid[4] = 5;
//	grid[5] = 6;
//	grid[6] = 7;
//	grid[7] = 8;
//	grid[8] = 10;
//	grid[9] = 20;
//	grid[10] = 21;
//	grid[11] = 22;*/
//
//}
//
//// Displays the grid by incrementing a renderer with rectangles. These rectangles are given the sprites matching the cell code
//// Textures are all created within main, and are passed to this function via the spriteList
//void DisplayGrid(vector<int> grid, SDL_Texture** spriteList, SDL_Renderer* renderer)
//{
//	int length = 4;
//	int height = 4;
//	int cellSize = 50;
//	int absOffset = 0, ordOffset = 0;
//	int targetdCell;
//
//	SDL_Rect square = { 0, 0, cellSize, cellSize };
//	SDL_Texture* cellTexture = NULL;
//
//	for (int target = 0; target < (length * height); target++)
//	{
//		// Setting up the offset to place the next cell at the right line and column
//		absOffset = cellSize * target;
//		ordOffset = cellSize * (target / length);
//		while (absOffset > (length - 1) * cellSize)
//		{
//			absOffset -= length * cellSize;
//		}
//
//		// Applying the offset. Above modification are not done directly on the Rectangle for readibility
//		square.x = absOffset;
//		square.y = ordOffset;
//
//		// Reading cell data to load the proper image in the Surface
//		if (grid[target] == 30 || grid[target] == 31) {
//			cellTexture = spriteList[0];
//		}
//		else if (grid[target] == 20) {
//			cellTexture = spriteList[1];
//		}
//		else if (grid[target] == 10 || grid[target] == 11) {
//			cellTexture = spriteList[2];
//		}
//		else if (grid[target] == 21) {
//			cellTexture = spriteList[3];
//		}
//		else if (grid[target] == 22) {
//			cellTexture = spriteList[4];
//		}
//		else if (grid[target] == 1) {
//			cellTexture = spriteList[5];
//		}
//		else if (grid[target] == 2) {
//			cellTexture = spriteList[6];
//		}
//		else if (grid[target] == 3) {
//			cellTexture = spriteList[7];
//		}
//		else if (grid[target] == 4) {
//			cellTexture = spriteList[8];
//		}
//		else if (grid[target] == 5) {
//			cellTexture = spriteList[9];
//		}
//		else if (grid[target] == 6) {
//			cellTexture = spriteList[10];
//		}
//		else if (grid[target] == 7) {
//			cellTexture = spriteList[11];
//		}
//		else if (grid[target] == 8) {
//			cellTexture = spriteList[12];
//		}
//		SDL_RenderCopy(renderer, cellTexture, NULL, &square);
//	}
//	SDL_RenderPresent(renderer);
//}
//
//int main(int argc, char* args[])
//{
//	// Seeding RNG
//	srand(time(NULL));
//
//	// Data for screen and grid
//	int length = 10, height = 8, mines = 10, cellSize = 50;
//	vector<int> grid;
//	int targetAbs, targetOrd;
//	int screenWidth = cellSize * length;
//	int screenHeight = cellSize * height;
//
//	// Decides wheter the game has been either won or lost
//	int condition = 0;
//
//	FillGrid(grid);
//
//	//Start up SDL and create window
//	if (!initSDL(screenWidth, screenHeight))
//	{
//		cout << "Failed to initialize !" << endl;
//	}
//	else
//	{
//		SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, NULL);
//
//		// Initilaizing Surfaces
//		SDL_Surface* cellSurfaceHidden = loadBMP("down.bmp");
//		SDL_Surface* cellSurfaceShown = loadBMP("down.bmp");
//		SDL_Surface* cellSurfaceFlag = loadBMP("down.bmp");
//		SDL_Surface* cellSurfaceMine = loadBMP("down.bmp");
//		SDL_Surface* cellSurfaceExpmine = loadBMP("down.bmp");
//		SDL_Surface* cellSurface1 = loadBMP("down.bmp");
//		SDL_Surface* cellSurface2 = loadBMP("down.bmp");
//		SDL_Surface* cellSurface3 = loadBMP("down.bmp");
//		SDL_Surface* cellSurface4 = loadBMP("down.bmp");
//		SDL_Surface* cellSurface5 = loadBMP("down.bmp");
//		SDL_Surface* cellSurface6 = loadBMP("down.bmp");
//		SDL_Surface* cellSurface7 = loadBMP("down.bmp");
//		SDL_Surface* cellSurface8 = loadBMP("down.bmp");
//
//		// Initialize Textures
//		SDL_Texture* cellSpriteHidden = SDL_CreateTextureFromSurface(renderer, cellSurfaceHidden);
//		SDL_Texture* cellSpriteShown = SDL_CreateTextureFromSurface(renderer, cellSurfaceShown);
//		SDL_Texture* cellSpriteFlag = SDL_CreateTextureFromSurface(renderer, cellSurfaceFlag);
//		SDL_Texture* cellSpriteMine = SDL_CreateTextureFromSurface(renderer, cellSurfaceMine);
//		SDL_Texture* cellSpriteExpmine = SDL_CreateTextureFromSurface(renderer, cellSurfaceExpmine);
//		SDL_Texture* cellSprite1 = SDL_CreateTextureFromSurface(renderer, cellSurface1);
//		SDL_Texture* cellSprite2 = SDL_CreateTextureFromSurface(renderer, cellSurface2);
//		SDL_Texture* cellSprite3 = SDL_CreateTextureFromSurface(renderer, cellSurface3);
//		SDL_Texture* cellSprite4 = SDL_CreateTextureFromSurface(renderer, cellSurface4);
//		SDL_Texture* cellSprite5 = SDL_CreateTextureFromSurface(renderer, cellSurface5);
//		SDL_Texture* cellSprite6 = SDL_CreateTextureFromSurface(renderer, cellSurface6);
//		SDL_Texture* cellSprite7 = SDL_CreateTextureFromSurface(renderer, cellSurface7);
//		SDL_Texture* cellSprite8 = SDL_CreateTextureFromSurface(renderer, cellSurface8);
//
//		// Filling the spriteList
//		SDL_Texture** spriteList;
//		spriteList[0] = cellSpriteHidden;
//		spriteList[1] = cellSpriteShown;
//		spriteList[2] = cellSpriteFlag;
//		spriteList[3] = cellSpriteMine;
//		spriteList[4] = cellSpriteExpmine;
//		spriteList[5] = cellSprite1;
//		spriteList[6] = cellSprite2;
//		spriteList[7] = cellSprite3;
//		spriteList[8] = cellSprite4;
//		spriteList[9] = cellSprite5;
//		spriteList[10] = cellSprite6;
//		spriteList[11] = cellSprite7;
//		spriteList[12] = cellSprite8;
//
//		DisplayGrid(grid, spriteList, renderer);
//
//		// Event handler and loop breaker
//		Bool quit = FALSE;
//		SDL_Event e;
//
//		SDL_Delay(3000);
//		while (!quit)
//		{
//			//Handle events on queue
//			while (SDL_PollEvent(&e) != 0)
//			{
//				//User requests quit
//				int t = 0;
//				if (e.type == SDL_QUIT)
//				{
//					quit = TRUE;
//				}
//				else if (e.button.button == SDL_BUTTON_LEFT && e.button.state == SDL_PRESSED)
//				{
//					targetAbs = e.button.x / cellSize;
//					targetOrd = e.button.y / cellSize;
//
//					quit = TurnManager(grid, 1, targetAbs, targetOrd);
//					DisplayGrid(grid, spriteList, renderer);
//				}
//				else if (e.button.button == SDL_BUTTON_RIGHT && e.button.state == SDL_PRESSED)
//				{
//					targetAbs = e.button.x / cellSize;
//					targetOrd = e.button.y / cellSize;
//
//					quit = TurnManager(grid, 2, targetAbs, targetOrd);
//					DisplayGrid(grid, spriteList, renderer);
//				}
//			}
//		}
//		// Scenario in which game is lost
//		if (quit == -1)
//		{
//			printf("\nYou loose\n");
//			SDL_Delay(4000);
//		}
//		// Scenario in which game is won
//		else if (quit == 1)
//		{
//			printf("\nYou win\n");
//			SDL_Delay(4000);
//		}
//
//	}
//
//	// Free ressources and close SDL
//	closeWindow();
//
//	return 0;
//}
//
//// Counts the neighbor mines around a cell
//int MineCounter(int length, int height, vector<int> grid, int targetAbs, int targetOrd)
//{
//	int coord, neighborMine = 0;
//
//	// Go through the 3 neighbor coordinates of the targeted cell
//	for (int ord = -1; ord < 2; ord++)
//	{
//		for (int abs = -1; abs < 2; abs++)
//		{
//			// Skip the test if it would be performed on the target, or if the cell tested is out of range
//			if (!(abs == 0 && ord == 0) && (targetAbs + abs > -1 && targetAbs + abs < length) && (targetOrd + ord > -1 && targetOrd + ord < height))
//			{
//				coord = (targetAbs + abs) + (targetOrd + ord) * length;
//				if (grid[coord] >= 10 && grid[coord] % 2 == 1)
//				{
//					neighborMine++;
//				}
//			}
//		}
//	}
//
//	// Returns the number of neighbor mines
//	return neighborMine;
//}
//
//// Processes user input : Edit the board accordingly and decides wheter the game has been lost, won, or shall continue
//int TurnManager(vector<int> grid, int action, int targetAbs, int targetOrd)
//{
//	int height = 4;
//	int length = 4;
//	int condition = 0;
//	int coord = targetAbs + targetOrd * length;
//
//	// Places a flag on the selected cell
//	if (action == 2)
//	{
//		// If no flags are found, places one. Otherwise, removes a flag if one is found. Does nothing if the targted cell was not covered.
//		if (grid[coord] < 10 || grid[coord] / 10 == 2)
//		{
//			printf("Bro, you can't, it's cringe...\n");
//		}
//		else if (grid[coord] / 10 == 3)
//		{
//			grid[coord] -= 20;
//		}
//		else
//		{
//			grid[coord] += 20;
//		}
//	}
//
//	// Attempt a dig on the selected cell
//	else
//	{
//		// Check if the cell was hidden. If not, doesn't dig anything and notifies the player
//		if (grid[coord] / 10 == 1)
//		{
//			printf("<?>~ You can't dig up a flag... ~<?>\n");
//		}
//
//		// Discover the cell and all it's 8 neighbor if it has mined neighbors but a sufficient amount of flag have been placed
//		// This doesn't check if the flags are indeed covering a mine, and can still dig up one
//		else if (grid[coord] < 10)
//		{
//			int newAbs, newOrd;
//			if (FlagCounter(length, height, grid, targetAbs, targetOrd) == grid[coord])
//			{
//				for (int offsetAbs = -1; offsetAbs < 2; offsetAbs++)
//				{
//					for (int offsetOrd = -1; offsetOrd < 2; offsetOrd++)
//					{
//						newAbs = targetAbs + offsetAbs;
//						newOrd = targetOrd + offsetOrd;
//
//						if (!(offsetAbs == 0 && offsetOrd == 0) && (newAbs > -1 && newAbs < length) && (newOrd > -1 && newOrd < height) && grid[newAbs + newOrd * length] / 10 != 1)
//						{
//							Dig(length, height, grid, newAbs, newOrd);
//						}
//					}
//				}
//			}
//		}
//		else
//		{
//			Dig(length, height, grid, targetAbs, targetOrd);
//		}
//	}
//
//	// Checks for a game over scenario
//	for (int i = 0; i < length * height; i++)
//	{
//		// In case player lost, reveals every other mines and ends
//		if (grid[i] == 21 || grid[i] == 22)
//		{
//			for (int x = 0; x < length * height; x++)
//			{
//				if (grid[x] == 31 || grid[x] == 11)
//				{
//					grid[x] = 21;
//				}
//			}
//			return -1;
//		}
//		// In case player haven't won yet, increments a variable to prevent him from winning
//		else if (grid[i] == 30 || grid[i] == 10)
//		{
//			condition++;
//		}
//	}
//	if (condition == 0)
//	{
//		// Player has won
//		return 1;
//	}
//	// The game continues
//	return 0;
//}
//
//// Counts the number of neighbor flags of a cell
//int FlagCounter(int length, int height, vector<int> grid, int targetAbs, int targetOrd)
//{
//	int coord, neighborFlag = 0;
//
//	// Go through the 3 neighbor coordinates of the targeted cell
//	for (int ord = -1; ord < 2; ord++)
//	{
//		for (int abs = -1; abs < 2; abs++)
//		{
//			// Skip the test if it would be performed on the target, or if the cell tested is out of range
//			if (!(abs == 0 && ord == 0) && (targetAbs + abs > -1 && targetAbs + abs < length) && (targetOrd + ord > -1 && targetOrd + ord < height))
//			{
//				coord = (targetAbs + abs) + (targetOrd + ord) * length;
//				if (grid[coord] / 10 == 1)
//				{
//					neighborFlag++;
//				}
//			}
//		}
//	}
//
//	// Returns the number of neighbor mines
//	return neighborFlag;
//}
//
//// Reveals a cell, and if possible, every possible neighbors
//void Dig(int length, int height, vector<int> grid, int targetAbs, int targetOrd)
//{
//	int coord = targetAbs + targetOrd * length;
//	int unsafeNeighborsCount;
//	int newAbs, newOrd;
//
//	unsafeNeighborsCount = MineCounter(length, height, grid, targetAbs, targetOrd);
//
//	// Reveals a mine if it dug up one after the player clicked on a number with missplaced flags
//	if (grid[coord] == 31)
//	{
//		grid[coord] = 22;
//	}
//
//	// Reveals only the targeted cell if it has unsafe neighborhood
//	else if (unsafeNeighborsCount != 0)
//	{
//		grid[coord] = unsafeNeighborsCount;
//	}
//
//	// Reveals the targeted cell and attempt do to the same to it's neighbors if it has safe neighborhood
//	else
//	{
//		grid[coord] = 20;
//
//		for (int offsetAbs = -1; offsetAbs < 2; offsetAbs++)
//		{
//			for (int offsetOrd = -1; offsetOrd < 2; offsetOrd++)
//			{
//				newAbs = targetAbs + offsetAbs;
//				newOrd = targetOrd + offsetOrd;
//
//				if (!(offsetAbs == 0 && offsetOrd == 0) && (newAbs > -1 && newAbs < length) && (newOrd > -1 && newOrd < height))
//				{
//					// Only Dig if the cell is hidden to begin with. Avoids an infinite loop of trying to Dig already revealed neighbors
//					if (grid[newAbs + newOrd * length] / 10 == 3)
//					{
//						Dig(length, height, grid, newAbs, newOrd);
//					}
//				}
//			}
//		}
//	}
//}