//
//  mesh_factory.h
//  hello_metal_cpp
//
//  Created by Daniel Rivera on 2/19/24.
//

#pragma once
#include "../config.h"

struct Mesh {
    MTL::Buffer* vertexBuffer, *indexBuffer;
};

namespace MeshFactory {
    MTL::Buffer* build_triangle(MTL::Device* device);
    Mesh buildQuad(MTL::Device* device);
}
