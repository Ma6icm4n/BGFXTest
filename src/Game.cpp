#include "Game.h"
#include "Actor.h"
#include "SimpleCube.h"
#include "Roundabout.h"
#include "Camera.h"

#include <iostream>
#include <sstream>


bool Game::initialize() {

	bool isWindowInit = window.initialize();
	return isWindowInit;

}

void Game::load(){

    roundabout = new Roundabout();
    roundabout->setPosition(0.0f, 0.0f, 0.0f);
    camera = new Camera();

    for (auto actor : actors) {
        actor->init();
    }
    
}
void Game::loop(){

    
    while (true) {

        float time = Time::getTime();

        for (auto actor : actors) {
            roundabout->setRotation(0.0f, time * 45, Maths::cos(time) *45 );
            actor->update();
        }

        bgfx::frame();
    }
}

void Game::addActor(Actor* actor) {
    actors.push_back(actor);
}
void Game::removeActor(Actor* actor) {
    auto iter = std::find(begin(waitingActors), end(waitingActors), actor);
    if(iter != end(waitingActors)) {
        std::iter_swap(iter, end(waitingActors) - 1);
        waitingActors.pop_back();
    }

    iter = std::find(begin(actors), end(actors), actor);
    if(iter != end(actors)) {
        std::iter_swap(iter, end(actors) - 1);
        actors.pop_back();
    }
}

void Game::unload(){
    actors.clear();
}
void Game::destroy(){

    bgfx::shutdown();
	window.destroy();
}
