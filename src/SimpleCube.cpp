#include "SimpleCube.h"

SimpleCube::SimpleCube(Actor* ownerP) : Component(ownerP) {
   
}

SimpleCube::~SimpleCube() {
    destroy();
}

void SimpleCube::init() {
    bgfx::VertexLayout pcvDecl;
    pcvDecl.begin()
        .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
        .add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Uint8, true)
        .end();
    m_vbh = bgfx::createVertexBuffer(bgfx::makeRef(cubeVertices, sizeof(cubeVertices)), pcvDecl);
    m_ibh = bgfx::createIndexBuffer(bgfx::makeRef(cubeTriList, sizeof(cubeTriList)));

    bgfx::ShaderHandle vsh = loadShader("vs_cubes.bin");
    bgfx::ShaderHandle fsh = loadShader("fs_cubes.bin");
    m_program = bgfx::createProgram(vsh, fsh, true);
	Component::init();
}

void SimpleCube::update() {
    Component::update();
}

void SimpleCube::destroy() {
    Component::destroy();
}