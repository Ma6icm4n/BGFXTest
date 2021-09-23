#ifndef UTILS_H
#define UTILS_H



#include <cstdio>
#include "bgfx/bgfx.h"
#include "bgfx/platform.h"
#include <string>
#include "bx/timer.h"
#include "bx/math.h"

bgfx::ShaderHandle loadShader(const char* filename);

#endif // !UTILS_H
