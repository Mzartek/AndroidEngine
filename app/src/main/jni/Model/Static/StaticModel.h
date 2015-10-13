//
// Created by Mzartek on 13/10/15.
//

#ifndef ANDROIDPROJECT_STATICMODEL_H
#define ANDROIDPROJECT_STATICMODEL_H

#include "../../GraphicsRenderer.h"

#include "../Model.h"

namespace Engine
{
    class StaticModel : public Model
    {
    public:
        StaticModel(const std::shared_ptr<ShaderProgram> &program);
        StaticModel(const std::shared_ptr<StaticModel> &model, const std::shared_ptr<ShaderProgram> &program);
        ~StaticModel(void);

        void loadFromFile(const GLchar *inFile);

        void display(const std::shared_ptr<PerspCamera> &cam) override;
        void displayTransparent(const std::shared_ptr<PerspCamera> &cam) override;
    };
}

#endif //ANDROIDPROJECT_STATICMODEL_H
