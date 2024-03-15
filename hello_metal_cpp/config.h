//
//  config.h
//  hello_metal_cpp
//
//  Created by Daniel Rivera on 2/19/24.
//

#pragma once
#include <Metal/Metal.hpp>
#include <AppKit/AppKit.hpp>
#include <MetalKit/MetalKit.hpp>
#include <simd/simd.h>

#include <iostream>
#include <fstream>
#include <sstream>


struct Vertex {
    simd::float2 pos;   //(x,y)
    simd::float3 color; //(r,g,b)
};
