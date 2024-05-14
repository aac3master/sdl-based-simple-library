#include <exception>
#include <string>
#include <iostream>
#include <SDL.h> //required for lib.
#include "source_code/lib_main/Init.h"
#include "source_code/window/Basic.h"
#include "source_code/sprite/Base.h"

SDL_Window* my_window = NULL;//Sets window var

int main( int argc, char * argv[] ) //For user: add here quit bool to control while
{
    //Init();//for safety you can use it but i tested app without it, and it works
    my_window = CreateWindow(1000, 1000);//creating sdl2 window
    Sprite my_sprite;//creating new instance of sprite
    Sprite my_sprite2;//creating new instance of sprite
    my_sprite.texture_path = "smile.png";//adding texture (use .UpdateAll() to commit changes!!!)
    //heh, i got new error! so now to commit texture you need to use SetTexture() (DONT PUT THIS INTO WHILE OR YOU WILL GET A BAD TIMES!!!)
    my_sprite.SetTexture();
    my_sprite.x = 500;//set x pos (also can be y for hight), in example making sprite be almost in center
    my_sprite.sx = 100;//sets x size (sx = size x, sy = size y) in pixels (Warning! Sprite will render 100x100 by default! If you have sprite (image) with another size, please set sx and sy like you image size!!!)
    my_sprite.angel = 50;// angel


    my_sprite2.texture_path = "smile.png";//
    my_sprite2.SetTexture();
    my_sprite2.x = 200;//
    my_sprite2.y = 600;
    my_sprite2.sx = 300;//
    my_sprite2.angel = -50;//

    SDL_Renderer* my_renderer = CreateRendererFromWindow(my_window);//Create renderer for rendering sprites
    my_sprite.where_draw = my_renderer;//Input: Renderer (sdl)
    my_sprite.UpdateAll();//Commit all changes and setting on sprite

    my_sprite2.where_draw = my_renderer;//
    my_sprite2.UpdateAll();//
    while (true)//Simple game loop! (while is part of c++)
    {
        //my_sprite.sx++;//funny o:
        my_sprite.UpdateAll();//Add it in loop only if you changing sprite! (after commands of change, like: my_sprite.texture_path = "smile.png";
        my_sprite2.UpdateAll();//
        UpdateTick(my_window);
        UpdateRenderer(my_renderer);//Warning! this clears screen! put it before draw!(ONLY)
        my_sprite.Draw();//Not actually. You still need to RenderFromRenderer
        my_sprite2.Draw();//
        RenderFromRenderer(my_renderer);//put after draw to commit changes on screen!


    }//All code after this line will be executed when while will stop (i recomend to add "quit" bool into your app/game)
    return 1;//while blocks all code here (after while)!
}
