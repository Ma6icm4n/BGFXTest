#include <cstdio>
#include "bgfx/bgfx.h"
#include "bgfx/platform.h"
#include "bx/math.h"
#include "GLFW/glfw3.h"
#define GLFW_EXPOSE_NATIVE_WIN32
#include "GLFW/glfw3native.h"
#include "Window.h"
#include "Utils.h"
#include "Game.h"

int main(void)
{
    bool isGameInit = Game::instance().initialize();
    if (isGameInit) {
        Game::instance().load();
    }

    
    Game::instance().destroy();
    glfwTerminate();

    return 0;
}