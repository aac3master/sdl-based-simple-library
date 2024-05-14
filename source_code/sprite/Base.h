#include <exception>
#include <string>
#include <iostream>
//#include <SDL.h>//for developer: you can enable it for safety, but it will eat more ram and create another instance of WHOLE Sdl2
#include <SDL_image.h>//for developer:it can be placed into main app (your app/game) but for decreasing include block it can be here <:
#include <string>
using namespace std;
class Sprite //Main class in all lib! (just image)
{
    public:
        string texture_path = "";
        SDL_Texture* texture = NULL;
        void SetTexture();
        void Draw();
        SDL_Renderer* where_draw = NULL;
        int x = 0;
        int y = 0;
        int sx = 100;
        int sy = 100;
        int angel = 0;

    private:
        SDL_Texture* loadTexture(string path);

};


SDL_Texture* Sprite::loadTexture(string path) //XstolenX recreated from lazyfoo.net :)
{
    //The final optimized image
    if (path == "")
    {

    }
    else
    {
        SDL_Texture* optimizedTexture = NULL;
        //Load image at specified path
        SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
        if( loadedSurface == NULL )
        {
            printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
        }
        else
        {
            //Convert surface to screen format
            optimizedTexture = SDL_CreateTextureFromSurface(Sprite::where_draw, loadedSurface );
            if( optimizedTexture == NULL )
            {
                printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
            }

            //Get rid of old loaded surface
            SDL_FreeSurface( loadedSurface );
        }

        return optimizedTexture;
    }

}

void Sprite::SetTexture()
{

    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
    }
    else
    {
        Sprite::texture = Sprite::loadTexture(Sprite::texture_path);
    }
}

void Sprite::Draw()
{


    if (Sprite::where_draw == NULL)
    { //Warning! This is experimental function (getting window surface without inputed surface)!!! (not working anymore!!!) TODO:bring back
        //SDL_Window* current_window = NULL;
        //current_window = SDL_GL_GetCurrentWindow();
        //Sprite::surface_where_draw = SDL_GetWindowSurface(current_window);
        //SDL_Rect sprite_rect = {Sprite::x, Sprite::y, Sprite::sx, Sprite::sy};
        //SDL_BlitScaled( Sprite::texture, NULL, Sprite::surface_where_draw, &sprite_rect);
        printf("Skipped draw:no renderer to draw on");
    }
    else
    {
        SDL_Rect sprite_rect = {Sprite::x, Sprite::y, Sprite::sx, Sprite::sy};
        //SDL_BlitScaled( Sprite::texture, NULL, Sprite::surface_where_draw, &sprite_rect);
        SDL_RenderCopyEx(Sprite::where_draw, Sprite::texture, NULL, &sprite_rect, Sprite::angel, NULL, SDL_FLIP_NONE);//copyex gives more functions than blit
    }

}


