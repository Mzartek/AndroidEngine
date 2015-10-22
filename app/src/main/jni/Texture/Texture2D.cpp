//
// Created by mzartek on 28/09/15.
//

#include "Texture2D.h"

Engine::Texture2D::Texture2D(void)
{
}

Engine::Texture2D::~Texture2D(void)
{
}

Engine::TextureType Engine::Texture2D::getType(void) const
{
    return TEXTURE_2D_TYPE;
}

void Engine::Texture2D::loadFromFile(const GLchar *path)
{
    SDL_Surface *image = IMG_Load(path);
    if (image == nullptr)
    {
        ALOGE("Error while loading image: %s", path);
        throw std::exception();
    }

    if (glIsTexture(_idTexture)) glDeleteTextures(1, &_idTexture);
    glGenTextures(1, &_idTexture);
    glBindTexture(GL_TEXTURE_2D, _idTexture);

    switch (image->format->format)
    {
        case 386930691:
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->w, image->h, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
            break;
        case 376840196:
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->w, image->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image->pixels);
            break;
        default:
            ALOGE("%s: Pixel format unsupported(%d)", path, image->format->format);
            throw std::exception();
    }
    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 16);

    SDL_FreeSurface(image);
}
