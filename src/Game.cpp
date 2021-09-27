#include "Game.h"
#include "Actor.h"
#include "SimpleCube.h"

#include <iostream>
#include <sstream>


bool Game::initialize() {

	bool isWindowInit = window.initialize();
	return isWindowInit;

}

void Game::load(){
    Actor* aCube = new Actor();
    SimpleCube* cube = new SimpleCube(aCube);
    aCube->setPosition(2.0f, 3.0f, 2.0f);
    aCube->setScale(0.5f, 0.5f, 0.5f);
    

    for (auto actor : actors) {
        actor->init();
    }
    
}
void Game::loop(){

    
    while (true) {


        const bx::Vec3 at = { 0.0f, 0.0f,  0.0f };
        const bx::Vec3 eye = { 0.0f, 0.0f, -5.0f };
        float view[16];
        bx::mtxLookAt(view, eye, at);
        float proj[16];
        bx::mtxProj(proj, 60.0f, float(WNDW_WIDTH) / float(WNDW_HEIGHT), 0.1f, 100.0f, bgfx::getCaps()->homogeneousDepth);
        bgfx::setViewTransform(0, view, proj);
        float time = Time::getTime();
        

        for (auto actor : actors) {
            actor->setRotation(time *45, time *45, 0.0f);
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
