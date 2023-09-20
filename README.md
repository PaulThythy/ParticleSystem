# ParticleSystem
This project is based on the SDL2 library. It describes particle interactions in a window (represented by circles).

## Generator choice : 
The **Ninja** generator for cmake was chosen for its windows and linux compatibility. Without the precision of the generator, Windows uses the Visual Studio solution, making the project dependent on it.<br/>
This explains this line in *run.sh* :<br/>
```sh
cmake -G "<Generator>" <path_to_the_CMakeLists.txt>
```

## Prerequisites :
Make and CMake on linux and Windows. For windows, you will have to install MinGW to compile source files.
