//
//  triangle.metal
//  hello_metal_cpp
//
//  Created by Daniel Rivera on 2/15/24.
//

#include <metal_stdlib>
using namespace metal;

struct VertexPayload {              //Mesh Vertex Type
    float4 position [[position]];   //Qualified attribute
    half3 color;                    //Half precision, faster
};

constant float4 positions[] = {
    float4(-0.75, -0.75, 0.0, 1.0), //bottom left: red
    float4( 0.75, -0.75, 0.0, 1.0), //bottom right: green
    float4(  0.0,  0.75, 0.0, 1.0), //center top: blue
};

constant half3 colors[] = {
    half3(1.0, 0.0, 0.0), //bottom left: red
    half3(0.0, 1.0, 0.0), //bottom right: green
    half3(0.0, 0.0, 1.0), //center top: blue
};

VertexPayload vertex vertexMain(uint vertexID [[vertex_id]]) {
    VertexPayload payload;
    payload.position = positions[vertexID];
    payload.color = colors[vertexID];
    return payload;
}

half4 fragment fragmentMain(VertexPayload frag [[stage_in]]) {
    return half4(frag.color, 1.0);
}
