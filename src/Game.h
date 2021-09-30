#pragma once
#include <vector>
#include "Actor.h"
#include "Window.h"
#include "Utils.h"
#include "SimpleCube.h"
#include "Time.h"

#define WNDW_WIDTH 1600
#define WNDW_HEIGHT 900



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

	bool isRunning;
	Window window;
	
	bool isUpdatingActors;
	vector<Actor*> actors;
	vector<Actor*> waitingActors;

	Actor* roundabout;
	float time;



};