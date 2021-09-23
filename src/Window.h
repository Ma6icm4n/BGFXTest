#pragma once
#include <cstdio>
#include "bgfx/bgfx.h"
#include "bgfx/platform.h"
#include "GLFW/glfw3.h"
#define GLFW_EXPOSE_NATIVE_WIN32
#include "GLFW/glfw3native.h"
#include <iostream>

#define WNDW_WIDTH 1600
#define WNDW_HEIGHT 900

class Window {

public:
	Window();
	
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

	bool initialize();
	void destroy();
	
	GLFWwindow* getGLFWWindow() const { return GLFWWindow; }
	int getWidth() const { return width; }
	int getHeight() const { return height; }
private:
	GLFWwindow* createWindow(int width, int height);
	GLFWwindow* GLFWWindow;
	int width;
	int height;

};