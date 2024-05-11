#include <exception>
#include <string>
#include <iostream>
//#include <SDL.h>

SDL_Window* CreateWindow(int sx, int sy)//Why not class? IDK. It was written before sprite.
{
    SDL_Window* window = NULL;
    window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, sx, sy, SDL_WINDOW_SHOWN );

    if( window == NULL )
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
    }
    return window;
}

void UpdateTick(SDL_Window* window)//Anti white screen TM
{
    SDL_Event e;

    SDL_PollEvent( &e );
    SDL_UpdateWindowSurface(window);


}

void UpdateRenderer(SDL_Renderer* Renderer)//Just clear renderer result
{
    SDL_RenderClear(Renderer);

}

void RenderFromRenderer(SDL_Renderer* Renderer)//Show renderer result on window
{
    SDL_RenderPresent(Renderer);
}


SDL_Renderer* CreateRendererFromWindow(SDL_Window* wind)
{
    SDL_Renderer* Renderer = SDL_CreateRenderer(wind, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(Renderer, 0x00, 0x00, 0x00, 0x00);
    return Renderer;
}

bool CloseWindow(SDL_Window* window, bool exit_sdl = false)//*no comments*
{
    SDL_DestroyWindow( window );
    if (exit_sdl == true)
    {
        SDL_Quit();
        return true;
    }
    else
    {
        return true;
    }
}
