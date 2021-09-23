//#include "SimpleCube.h"
//
//void init() {
//
//    bgfx::VertexLayout pcvDecl;
//    pcvDecl.begin()
//        .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
//        .add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Uint8, true)
//        .end();
//    bgfx::VertexBufferHandle vbh = bgfx::createVertexBuffer(bgfx::makeRef(cubeVertices, sizeof(cubeVertices)), pcvDecl);
//    bgfx::IndexBufferHandle ibh = bgfx::createIndexBuffer(bgfx::makeRef(cubeTriList, sizeof(cubeTriList)));
//}