#pragma once 
#include <vector>

#include "bx/math.h"
using std::vector;

class Game;
class Component;

class Actor {
public:
	enum class ActorState {
		active, paused, dead
	};

	Actor();
	virtual ~Actor();
	Actor(const Actor&) = delete;
	Actor& operator=(const Actor&) = delete;

	void setPosition(float x, float y, float z);
	void setScale(float x, float y, float z);
	void setRotation(float x, float y, float z);

	Game& getGame() const { return game; }
	float* getPosition() { return m_position; }
	float* getScale() { return m_scale; }
	float* getRotation() { return m_rotation; }
	
	virtual void init();
	virtual void update();
	virtual void destroy();

	void addComponents(Component* component);
	void removeComponents(Component* component);


private:
	Game& game;
	ActorState state;

	float m_position[3] = { 0, 0, 0 };
	float m_scale[3] = { 1, 1, 1 };
	float m_rotation[3] = { 0, 0, 0 };

	vector<Component*> components;

	bool isInit;
};