//
//  view_delegate.h
//  metal_test
//
//  Created by Daniel Rivera on 02/19/2024.
//

#pragma once
#include "config.h"
#include "../view/renderer.h"
class ViewDelegate : public MTK::ViewDelegate
{
    public:
        ViewDelegate(MTL::Device* device);
        virtual ~ViewDelegate() override;
        virtual void drawInMTKView(MTK::View* view) override;

    private:
        Renderer* renderer;
};
