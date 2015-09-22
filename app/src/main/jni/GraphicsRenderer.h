//
// Created by mzartek on 22/09/15.
//

#ifndef ANDROIDPROJECT_GRAPHICSRENDERER_H
#define ANDROIDPROJECT_GRAPHICSRENDERER_H

#include "Object.h"

namespace Engine
{
    class GraphicsRenderer
    {
    public:
        static GraphicsRenderer& Instance(void);

    private:
        GraphicsRenderer(void);
        ~GraphicsRenderer(void);

    public:
        void printGLinfo(void);
    };
}

#endif //ANDROIDPROJECT_GRAPHICSRENDERER_H
