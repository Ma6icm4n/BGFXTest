#pragma once
#include "Actor.h"
#include "Utils.h"

#define WNDW_WIDTH 1600
#define WNDW_HEIGHT 900

class Camera : public Actor
{
public:
	Camera();
	virtual ~Camera();

	Camera(const Camera&) = delete;
	Camera& operator=(const Camera&) = delete;

	void init() override;
	void update() override;

private:
	bx::Vec3 at;
	bx::Vec3 eye;
	float view[16];
	float proj[16];

};