#ifdef _WIN32
	#include <SDL.h>
#elif __linux__
	#include <SDL2/SDL.h>
#endif

#include "../include/application.h"

int main(int argc, char* argv[]) {
    Application app(800, 600);
    return app.execute();
}
