# sdl-based-simple-library
For small games <br> 
---How to set up--- <br> 
Code blocks (gcc): <br> 
1.Select sdl2 template <br> 
2.Download mingw devel and dll (sdl) <br> 
3.Unpack somwhere and select in whizard <br> 
4.Add 'source_code' dir, 'smile.png' and all cursors (.png) into your project <br> 
5.Set up sdl image: go to Project>Properties>Project's build options> <br> 
5.1.Go to search dir. and add: source_code\sprite\SDL_IMAGE\include\SDL2 ('source_code' dir. is dir. from step 4 ) <br> 
5.2.Go to Linker settings and add:-lSDL2_image <br>
(***DONT FORGET TO PUT ALL DLLS AT OUTPUT FOLDER!!!***)<br>
Warn.!This is for gcc! Use internet tutorial for another ide or compiler!<br>
All done. <br> 
Now create file and copy code in it from example.cpp from this github page! <br> 
For vs just set up sdl (for vs), create project, do step 4 for code blocks and then set up sdl image (also for vs) <br> 
Demo on youtube (old):
https://www.youtube.com/watch?v=pYf4jZuNeGY <br>
Warning: <br>
<h2>Project deprecated. New lib available <h2\> <br>
<h1>https://github.com/aac3master/SimpleDraw</h1>
