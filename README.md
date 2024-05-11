# sdl-based-simple-library
For small games
---How to set up---
Code blocks:
1.Select sdl2 template
2.Download mingw devel and dll
3.Unpack somwhere and select in whizard
4.Add 'source_code' dir into your project
5.Set up sdl image: go to Project>Properties>Project's build options>
  1.Go to search dir. and add: source_code\sprite\SDL_IMAGE\include\SDL2 ('source_code' dir. is dir. from step 4)
  2.Go to Linker settings and add:-lSDL2_image

All done.
Now create file and copy code in it from example.cpp from this github page!
For vs just set up sdl (for vs), do step 4 for code blocks and then set up sdl image (also for vs)
