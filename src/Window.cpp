#include "Window.h"


Window::Window() : GLFWWindow(nullptr), width(WNDW_WIDTH), height(WNDW_HEIGHT) {}

bool Window::initialize() {

	int isInitGLFW = glfwInit();
	if (!isInitGLFW) {
		int code = glfwGetError(NULL);
		std::cout << "Unable to initinialize GLFW :" << code << std::endl;
		return false;
	}

	GLFWWindow = Window::createWindow(width, height);
	if (!GLFWWindow) {
		int code = glfwGetError(NULL);
		std::cout << "Unable to Create Window :" << code << std::endl;
		return false;
	}

	return true;
}


GLFWwindow* Window::createWindow(int width, int height) {

	GLFWwindow* window = glfwCreateWindow(width, height, "Hello, bgfx!", NULL, NULL);

	bgfx::PlatformData pd;
	pd.nwh = glfwGetWin32Window(window);
	bgfx::setPlatformData(pd);
	bgfx::Init bgfxInit;

	bgfxInit.type = bgfx::RendererType::Count;
	bgfxInit.resolution.width = width;
	bgfxInit.resolution.height = height;
	bgfxInit.resolution.reset = BGFX_RESET_VSYNC;
	bgfx::init(bgfxInit);

	bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0f, 0);
	bgfx::setViewRect(0, 0, 0, width, height);

	return window;
}

void Window::destroy() {

	glfwDestroyWindow(GLFWWindow);

}

