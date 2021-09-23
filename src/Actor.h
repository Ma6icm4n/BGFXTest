#pragma once 
#include <vector>
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

	Game& getGame() const { return game; }
	const ActorState getState() const { return state; }
	
	void setPosition();
	void setScale();
	void setRotation();
	void setState();

	void computeWorldTransform();

	void update(float dt);
	void UpdateComponents(float dt);
	virtual void updateActor(float dt);
	void addComponent(Component* component);
	void removeComponent(Component* component);

private:
	Game& game;
	ActorState state;
	bool mustRecomputeWorldTransform;

	vector<Component*> components;
};