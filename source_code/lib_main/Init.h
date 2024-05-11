#include <exception>
#include <string>
#include <iostream>
#include <SDL.h>

bool Init()
{
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    else
    {
        return true;
    }
}
