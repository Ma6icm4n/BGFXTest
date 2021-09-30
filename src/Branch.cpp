#include "Branch.h"

Branch::Branch(Actor* ownerP) : Component(ownerP) {

}

Branch::~Branch() {
	destroy();
}

void Branch::init() {
	bgfx::VertexLayout pcvDecl;
	pcvDecl.begin()
		.add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
		.add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Uint8, true)
		.end();
	m_vbh = bgfx::createVertexBuffer(bgfx::makeRef(branchVertices, sizeof(branchVertices)), pcvDecl);
	m_ibh = bgfx::createIndexBuffer(bgfx::makeRef(branchTriList, sizeof(branchTriList)));

	bgfx::ShaderHandle vsh = loadShader("vs_cubes.bin");
	bgfx::ShaderHandle fsh = loadShader("fs_cubes.bin");
	m_program = bgfx::createProgram(vsh, fsh, true);


	Component::init();
}

void Branch::update() {
	Component::update();
}

void Branch::destroy() {
	Component::destroy();
}