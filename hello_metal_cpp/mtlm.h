//
//  mtlm.h
//  hello_metal_cpp
//
//  Created by Daniel Rivera on 3/19/24.
//

#pragma once
#include <simd/simd.h>

namespace mtlm {

    simd::float4x4 identity();
    simd::float4x4 translation(simd::float3 dPos);
    simd::float4x4 z_rotation(float theta);
    simd::float4x4 scale(float factor);
}
