#include "TextureCube.h"

#include "Tools/AssetTool.h"

Engine::TextureCube::TextureCube(void)
{
}

Engine::TextureCube::~TextureCube(void)
{
}

Engine::TextureType Engine::TextureCube::getType(void) const
{
     return TEXTURE_CUBE_TYPE;
}

void Engine::TextureCube::loadFromAssets(
     const GLchar *posx, const GLchar *negx,
     const GLchar *posy, const GLchar *negy,
     const GLchar *posz, const GLchar *negz)
{
     Tools::AssetRessource assetRessource;
     SDL_RWops *rw;
     const GLchar *tex[] = { posx, negx, posy, negy, posz, negz };
     SDL_Surface *image[6];

     for (int i = 0; i < 6; ++i)
     {
	  assetRessource = Tools::openAsset(tex[i]);
	  rw = SDL_RWFromMem(assetRessource.buffer, assetRessource.size);
	  Tools::closeAsset(assetRessource);
	  image[i] = IMG_Load_RW(rw, 1);
     }
     
     GLenum cube_map_target[] = {
	  GL_TEXTURE_CUBE_MAP_POSITIVE_X, GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
	  GL_TEXTURE_CUBE_MAP_POSITIVE_Y, GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
	  GL_TEXTURE_CUBE_MAP_POSITIVE_Z, GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
     };

     if (glIsTexture(_idTexture)) glDeleteTextures(1, &_idTexture);
     glGenTextures(1, &_idTexture);
     glBindTexture(GL_TEXTURE_CUBE_MAP, _idTexture);

     for (int i = 0; i < 6; i++)
     {
	  if (image[i] == nullptr)
	  {
	       ALOGE("Error while loading image: %s", tex[i]);
	       throw std::exception();
	  }

	  switch (image[i]->format->format)
	  {
	  case 386930691:
	       glTexImage2D(cube_map_target[i], 0, GL_RGB, image[i]->w, image[i]->h, 0, GL_RGB, GL_UNSIGNED_BYTE, image[i]->pixels);
	       break;
	  case 376840196:
	       glTexImage2D(cube_map_target[i], 0, GL_RGBA, image[i]->w, image[i]->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image[i]->pixels);
	       break;
	  default:
	       ALOGE("%s: Pixel format unsupported (%d)", tex[i], image[i]->format->format);
	       throw std::exception();
	  }
	  glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	  glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	  glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	  glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	  SDL_FreeSurface(image[i]);
     }
}
