#include "Camera.h"
#include "Time.h"

Camera::Camera() {}

Camera::~Camera() {}

void Camera::init() {
    at = { 0.0f, 0.0f,  0.0f };
    eye = { 0.0f, 20.0f, -20.0f };
    float view[16];
    float proj[16];
    bx::mtxLookAt(view, eye, at);
	Actor::init();
}

void Camera::update() {

    bx::mtxLookAt(view, eye, at);
    bx::mtxProj(proj, 60.0f, float(WNDW_WIDTH) / float(WNDW_HEIGHT), 0.1f, 100.0f, bgfx::getCaps()->homogeneousDepth);
    bgfx::setViewTransform(0, view, proj);
}