//
// Created by khavranek on 30/09/15.
//

#ifndef ANDROIDPROJECT_SKYBOX_H
#define ANDROIDPROJECT_SKYBOX_H

#include "Camera/PerspCamera.h"

#include "Texture/TextureCube.h"

#include "Buffer.h"
#include "ShaderProgram.h"

#include "GraphicsRenderer.h"

#define SKYBOX_DIM 10

namespace Engine
{
    class SkyBox : public Object
    {
    private:
        std::shared_ptr<TextureCube> _cubeTexture;
        std::shared_ptr<Buffer> _vertexBuffer;
        std::shared_ptr<Buffer> _indexBuffer;

        std::shared_ptr<ShaderProgram> _program;
        GLint _MVPUniformLocation;

        GLuint _numElement;

    public:
        SkyBox(std::shared_ptr<ShaderProgram> program);
        ~SkyBox(void);

        void load(const GLchar *posx, const GLchar *negx,
                  const GLchar *posy, const GLchar *negy,
                  const GLchar *posz, const GLchar *negz) const;

        const std::shared_ptr<TextureCube> &getTexture(void) const;

        void display(const std::shared_ptr<PerspCamera> &cam) const;
    };
}

#endif //ANDROIDPROJECT_SKYBOX_H
