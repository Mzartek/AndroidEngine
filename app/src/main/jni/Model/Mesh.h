//
// Created by khavranek on 07/10/15.
//

#ifndef ANDROIDPROJECT_MESH_H
#define ANDROIDPROJECT_MESH_H

#include "../Texture/TextureCube.h"

#include "../Buffer.h"
#include "../ShaderProgram.h"

#include "Material.h"

namespace Engine
{
    enum MeshType { STATIC_MESH, SKELETAL_MESH };

    class Mesh : public Object
    {
        friend struct CompareMesh;

        std::shared_ptr<Material> _material;
        struct {
            GLuint id;
            GLboolean hasTex;
            GLint hasTexUniformLocation;
        } _tex[10];

        GLint _diffuseMaterialUniformLocation;
        GLint _specularMaterialUniformLocation;
        GLint _ambientMaterialUniformLocation;
        GLint _emissiveMaterialUniformLocation;
        GLint _shininessMaterialUniformLocation;
        GLint _opacityMaterialUniformLocation;

    protected:
        std::shared_ptr<Buffer> _vertexBuffer;
        std::shared_ptr<Buffer> _indexBuffer;
        GLsizei _numElement;

    public:
        Mesh(const std::shared_ptr<ShaderProgram> &_program);
        ~Mesh(void);
        void setMaterial(const std::shared_ptr<Material> &material);

        const std::shared_ptr<Material> &getMaterial(void) const;

        void display(void) const;
        void display(const std::shared_ptr<TextureCube> &cubeTexture) const;
        void displayShadow(void) const;

    private:
        void bindTextures(void) const;
        void bindMaterials(void) const;

        // Virtual methods
    public:
        virtual MeshType getType(void) const = 0;

    protected:
        virtual void startDrawing(void) const = 0;
        virtual void endDrawing(void) const = 0;
    };
}

#endif //ANDROIDPROJECT_MODEL_H
