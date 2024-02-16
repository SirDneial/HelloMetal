//
//  renderer.cpp
//  hello_metal_cpp
//
//  Created by Andrew Mengede on 15/9/2023.
//

#include "renderer.h"

using namespace MTL;
using namespace NS;

Renderer::Renderer(Device* device):
device(device->retain())
{
    commandQueue = device->newCommandQueue();
    buildPipeline();
}

Renderer::~Renderer() {
    commandQueue->release();
    device->release();
}

void Renderer::buildPipeline() {
    
    std::ifstream file;
    file.open("shaders/triangle.metal");
    std::stringstream reader;
    reader << file.rdbuf();
    std::string raw_string = reader.str();
    String* source_code = String::string(raw_string.c_str(),
                                                 StringEncoding::UTF8StringEncoding);
    Error* error = nullptr;
    CompileOptions* options = nullptr;
    Library* library = device->newLibrary(source_code, options, &error);
    if (!library) {
        std::cout << error->localizedDescription()->utf8String() << std::endl;
    }
    
    String* vertexName = String::string("vertexMain", StringEncoding::UTF8StringEncoding);
    Function* vertexMain = library->newFunction(vertexName);
    
    String* fragmentName = String::string("fragmentMain", StringEncoding::UTF8StringEncoding);
    Function* fragmentMain = library->newFunction(fragmentName);
    
    RenderPipelineDescriptor* descriptor = RenderPipelineDescriptor::alloc()-> init();
    descriptor->setVertexFunction(vertexMain);
    descriptor->setFragmentFunction(fragmentMain);
    descriptor->colorAttachments()->object(0)->setPixelFormat(::PixelFormat::PixelFormatBGRA8Unorm_sRGB);
    
    trianglePipeline = device->newRenderPipelineState(descriptor, &error);
    if (!trianglePipeline) {
        std::cout << error->localizedDescription()->utf8String() << std::endl;
    }
    
    descriptor->release();
    vertexMain->release();
    fragmentMain->release();
    library->release();
}

void Renderer::draw(MTK::View* view) {
    
    AutoreleasePool* pool = AutoreleasePool::alloc()->init();
    
    CommandBuffer* commandBuffer = commandQueue->commandBuffer();
    RenderPassDescriptor* renderPass = view->currentRenderPassDescriptor();
    RenderCommandEncoder* encoder = commandBuffer->renderCommandEncoder(renderPass);
    
    encoder->setRenderPipelineState(trianglePipeline);
    encoder->drawPrimitives(
                            PrimitiveType::PrimitiveTypeTriangle,
                            UInteger(0),  //start
                            UInteger(3)); //points
    
    encoder->endEncoding();
    commandBuffer->presentDrawable(view->currentDrawable());
    commandBuffer->commit();
    
    pool->release();
}
