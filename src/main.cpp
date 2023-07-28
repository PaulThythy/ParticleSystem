#ifdef _WIN32
	#include <SDL.h>
#elif __linux__
	#include <SDL2/SDL.h>
#endif

#include "../include/application.h"
#include "../include/constants.h"

int main(int argc, char* argv[]) {
    Application app(WINDOW_WIDTH, WINDOW_HEIGHT);
    return app.execute();
}
