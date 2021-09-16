#pragma once
#include <cstdio>
#include "bgfx/bgfx.h"
#include "bgfx/platform.h"
#include "GLFW/glfw3.h"
#define GLFW_EXPOSE_NATIVE_WIN32
#include "GLFW/glfw3native.h"



class Window {

public:
	Window();
	~Window();
	
	GLFWwindow* createWindow(int width, int height);
	void destroyWindow(GLFWwindow* window);

private:
	GLFWwindow* window;

};