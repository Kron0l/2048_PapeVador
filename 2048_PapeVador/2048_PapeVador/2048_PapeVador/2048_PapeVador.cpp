


#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <SDL.h>
#include "grid.h"

using namespace std;



using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

const int SCREEN_WIDTH = 138;
const int SCREEN_HEIGHT = 138;


SDL_Window* window = NULL;

bool initSDL(int screenWidth, int screenHeight);
void closeWindow();
SDL_Surface* loadBMP(const char* path);

bool initSDL(int screenWidth, int screenHeight)
{
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL could not be initialized ! SDL_Error : " << SDL_GetError() << endl;
        success = false;
    }
    else
    {
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            cout << "Window could not be created ! SDL_Error : " << SDL_GetError() << endl;
            success = false;
        }
    }
    return success;
}

void closeWindow()
{
    SDL_DestroyWindow(window);
    window = NULL;

    SDL_Quit();
}

SDL_Surface* loadBMP(const char* filePath)
{
    bool success = true;

    SDL_Surface* surface = NULL;
    surface = SDL_LoadBMP(filePath);
    if (surface == NULL)
    {
        cout << "Unable to load image " << filePath << "!SDL_Error : " << SDL_GetError() << endl;
    }

    return surface;
}

int main(int argc, char* args[])
{
    
    //intialisation des valeurs par d?faut
    string gamemode = "game";
    string end = "false";
    int screenWidth = 552;
    int screenHeight = 552;
    Grid grid;
    


        //boucle de jeu
    if (gamemode == "game")
    {
        if (!initSDL(screenWidth, screenHeight))
        {
            cout << "Failed to initialize !" << endl;
        }
        else
        {
            SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, NULL);

            SDL_Surface* cellSurfaceGrid = loadBMP("Assets/grid.bmp");
            SDL_Surface* cellSurface2 = loadBMP("Assets/2.bmp");
            SDL_Surface* cellSurface4 = loadBMP("Assets/4.bmp");
            SDL_Surface* cellSurface8 = loadBMP("Assets/8.bmp");
            SDL_Surface* cellSurface16 = loadBMP("Assets/16.bmp");
            SDL_Surface* cellSurface32 = loadBMP("Assets/32.bmp");
            SDL_Surface* cellSurface64 = loadBMP("Assets/64.bmp");
            SDL_Surface* cellSurface128 = loadBMP("Assets/128.bmp");
            SDL_Surface* cellSurface256 = loadBMP("Assets/256.bmp");
            SDL_Surface* cellSurface512 = loadBMP("Assets/512.bmp");
            SDL_Surface* cellSurface1024 = loadBMP("Assets/1024.bmp");
            SDL_Surface* cellSurface2048 = loadBMP("Assets/2048.bmp");

            SDL_Texture* cellSpriteGrid = SDL_CreateTextureFromSurface(renderer, cellSurfaceGrid);
            SDL_Texture* cellSprite2 = SDL_CreateTextureFromSurface(renderer, cellSurface2);
            SDL_Texture* cellSprite4 = SDL_CreateTextureFromSurface(renderer, cellSurface4);
            SDL_Texture* cellSprite8 = SDL_CreateTextureFromSurface(renderer, cellSurface8);
            SDL_Texture* cellSprite16 = SDL_CreateTextureFromSurface(renderer, cellSurface16);
            SDL_Texture* cellSprite32 = SDL_CreateTextureFromSurface(renderer, cellSurface32);
            SDL_Texture* cellSprite64 = SDL_CreateTextureFromSurface(renderer, cellSurface64);
            SDL_Texture* cellSprite128 = SDL_CreateTextureFromSurface(renderer, cellSurface128);
            SDL_Texture* cellSprite256 = SDL_CreateTextureFromSurface(renderer, cellSurface256);
            SDL_Texture* cellSprite512 = SDL_CreateTextureFromSurface(renderer, cellSurface512);
            SDL_Texture* cellSprite1024 = SDL_CreateTextureFromSurface(renderer, cellSurface1024);
            SDL_Texture* cellSprite2048 = SDL_CreateTextureFromSurface(renderer, cellSurface2048);

            SDL_Texture** spriteList = new SDL_Texture * [12];;

            spriteList[0] = cellSpriteGrid;
            spriteList[1] = cellSprite2;
            spriteList[2] = cellSprite4;
            spriteList[3] = cellSprite8;
            spriteList[4] = cellSprite16;
            spriteList[5] = cellSprite32;
            spriteList[6] = cellSprite64;
            spriteList[7] = cellSprite128;
            spriteList[8] = cellSprite256;
            spriteList[9] = cellSprite512;
            spriteList[10] = cellSprite1024;
            spriteList[11] = cellSprite2048;
            grid.Spawn();
            grid.Display(spriteList, renderer);


            bool quit = false;
            SDL_Event e;
            int move = 0;

            SDL_Delay(300);
            if (gamemode == "game") {
                while (!quit)
                {
                    //Handle events on queue
                    while (SDL_PollEvent(&e) != 0)
                    {
                        //User requests quit
                        move = 0;

                        if (e.type == SDL_QUIT)
                        {
                            quit = true;
                        }
                        else if (e.type == SDL_KEYDOWN) {
                            if (e.key.keysym.sym == SDLK_UP)
                            {
                                //cout << "up" << endl;
                                grid.gravity = "up";
                                move = grid.Gravity(move);
                                if (move) {
                                    grid.Spawn();
                                }
                                grid.Display(spriteList, renderer);
                                end = grid.End();
                            }
                            else if (e.key.keysym.sym == SDLK_DOWN)
                            {
                               //cout << "down" << endl;
                                grid.gravity = "down";
                                move = grid.Gravity(move);
                                if (move) {
                                    grid.Spawn();
                                }
                                grid.Display(spriteList, renderer);
                                end = grid.End();
                            }
                            else if (e.key.keysym.sym == SDLK_RIGHT)
                            {
                                //cout << "right" << endl;
                                grid.gravity = "right";
                                move = grid.Gravity(move);
                                if (move) {
                                    grid.Spawn();
                                }
                                grid.Display(spriteList, renderer);
                                end = grid.End();
                            }
                            else if (e.key.keysym.sym == SDLK_LEFT)
                            {
                                //cout << "left" << endl;
                                grid.gravity = "left";
                                move = grid.Gravity(move);
                                if (move) {
                                    grid.Spawn();
                                }
                                grid.Display(spriteList, renderer);
                                end = grid.End();
                            }
                        }
                        if (end != "false") {
                            if (end == "victory") {
                                cout << "Congratulation for your win!!!" << endl;
                                gamemode = "stop";
                                grid.~Grid();
                                closeWindow();
                            }
                            else if (end == "loose") {
                                cout << "HAHA LOOSER!!!!" << endl;
                                gamemode = "stop";
                                grid.~Grid();
                                closeWindow();
                            }
                        }
                    }
                }
            }
        }

        
    }
    return 0;
}
