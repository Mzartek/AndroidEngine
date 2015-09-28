//
// Created by mzartek on 27/09/15.
//

#ifndef ANDROIDPROJECT_TEXTURE_H
#define ANDROIDPROJECT_TEXTURE_H

namespace Engine
{
    enum TextureType { TEXTURE_2D_TYPE, TEXTURE_CUBE_TYPE };

    class Texture : public Object
    {
    protected:
        GLuint _idTexture;

    public:
        Texture(void);
        ~Texture(void);
        GLuint getId(void) const;

        virtual TextureType getType(void) const = 0;
    };
}

#endif //ANDROIDPROJECT_TEXTURE_H
