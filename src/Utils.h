#ifndef UTILS_H
#define UTILS_H


#include "bgfx/bgfx.h"
#include "bgfx/platform.h"
#include <string>
#include "bx/timer.h"
#include "bx/math.h"

#include "GLFW/glfw3.h"
#define GLFW_EXPOSE_NATIVE_WIN32
#include "GLFW/glfw3native.h"

#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>


bgfx::ShaderHandle loadShader(const char* filename);

#endif // !UTILS_H
