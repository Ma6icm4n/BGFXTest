#pragma once
#include <cstdio>
#include "bgfx/bgfx.h"
#include "bgfx/platform.h"
#include "bx/math.h"
#include "GLFW/glfw3.h"
#define GLFW_EXPOSE_NATIVE_WIN32
#include "GLFW/glfw3native.h"
#include <vector>
#include "Actor.h"
#include "Window.h"
#include "Utils.h"

#define WNDW_WIDTH 1600
#define WNDW_HEIGHT 900

struct PosColorVertex
{
	float x;
	float y;
	float z;
	uint32_t abgr;
};

static PosColorVertex cubeVertices[] =
{
	{-1.0f,  1.0f,  1.0f, 0xff000000 },
	{ 1.0f,  1.0f,  1.0f, 0xff0000ff },
	{-1.0f, -1.0f,  1.0f, 0xff00ff00 },
	{ 1.0f, -1.0f,  1.0f, 0xff00ffff },
	{-1.0f,  1.0f, -1.0f, 0xffff0000 },
	{ 1.0f,  1.0f, -1.0f, 0xffff00ff },
	{-1.0f, -1.0f, -1.0f, 0xffffff00 },
	{ 1.0f, -1.0f, -1.0f, 0xffffffff },
};

static const uint16_t cubeTriList[] =
{
	0, 1, 2,
	1, 3, 2,
	4, 6, 5,
	5, 6, 7,
	0, 2, 4,
	4, 2, 6,
	1, 5, 3,
	5, 7, 3,
	0, 4, 1,
	4, 5, 1,
	2, 3, 6,
	6, 3, 7,
};


using std::vector;

class Game {
public:
	static Game& instance() {
		static Game inst;
		return inst;
	}

	Game(const Game&) = delete;
	Game operator=(const Game&) = delete;
	Game(Game&&) = delete;
	Game& operator=(Game&&) = delete;

	bool initialize();
	void load();
	void loop();
	void unload();
	void destroy();

	void addActor(Actor* actor);
	void removeActor(Actor* actor);

private:
	Game() : isRunning(true), isUpdatingActors(false) {}
	void update(float dt);
	void render();

	bool isRunning;
	Window window;
	
	bool isUpdatingActors;
	vector<Actor*> actors;
	vector<Actor*> pendingActors;

	bgfx::VertexBufferHandle vbh;
	bgfx::IndexBufferHandle ibh;

};