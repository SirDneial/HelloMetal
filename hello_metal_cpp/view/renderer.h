//
//  renderer.h
//  hello_metal_cpp
//
//  Created by Daniel Rivera on 02/19/2024.
//

#pragma once
#include "../config.h"

class Renderer
{
    public:
        Renderer(MTL::Device* device);
        ~Renderer();
        void draw(MTK::View* view);

    private:
        void buildMeshes();
        void buildShaders();
        MTL::RenderPipelineState* buildShader(const char* filename, const char* vertName, const char* fragName);
        MTL::Device* device;
        MTL::CommandQueue* commandQueue;
        
        MTL::RenderPipelineState* trianglePipeline, *generalPipeline;
        MTL::Buffer* triangleMesh;
};
