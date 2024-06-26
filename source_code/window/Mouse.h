#include <exception>
#include <string>
#include <iostream>
//#include <SDL.h>
#include <SDL_image.h>//for developer:it can be placed into main app (your app/game) but for decreasing include block it can be here <:

using namespace std;

void SetCursorFromImage(string path, int hot_x = 0, int hot_y = 0)
{
    SDL_Surface *surface = IMG_Load(path.c_str());
    SDL_Cursor *cursor = SDL_CreateColorCursor(surface, hot_x, hot_y);
    SDL_SetCursor(cursor);
}
