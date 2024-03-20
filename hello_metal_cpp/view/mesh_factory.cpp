//
//  mesh_factory.cpp
//  hello_metal_cpp
//
//  Created by Daniel Rivera on 2/19/24.
//
#include "mesh_factory.h"

MTL::Buffer* MeshFactory::build_triangle(MTL::Device* device) {

    Vertex vertices[3] = {
        {{-0.75, -0.75}, {1.0, 1.0, 0.0}},
        {{ 0.75, -0.75}, {1.0, 1.0, 0.0}},
        {{  0.0,  0.75}, {1.0, 1.0, 0.0}}
    };

    MTL::Buffer* buffer = device->newBuffer(3 * sizeof(Vertex), MTL::ResourceStorageModeShared);

    memcpy(buffer->contents(), vertices, 3 * sizeof(Vertex));
    
    return buffer;
}

Mesh MeshFactory::buildQuad(MTL::Device* device) {
    Mesh mesh;
    
    Vertex vertices[4] = {
        {{-0.75, -0.75}, {1.0, 0.0, 0.0}},
        {{ 0.75, -0.75}, {0.0, 1.0, 0.0}},
        {{  0.75,  0.75}, {1.0, 0.0, 0.0}},
        {{  -0.75,  0.75}, {0.0, 1.0, 0.0}}
    };
    
    ushort indices[6] = {0, 1, 2, 2, 3, 0};

    mesh.vertexBuffer = device->newBuffer(4 * sizeof(Vertex), MTL::ResourceStorageModeShared);
    memcpy(mesh.vertexBuffer->contents(), vertices, 4 * sizeof(Vertex));
    
    mesh.indexBuffer = device->newBuffer(6 * sizeof(ushort), MTL::ResourceStorageModeShared);
    memcpy(mesh.indexBuffer->contents(), indices, 6 * sizeof(ushort));
    
    return mesh;
}
