//
// Created by mzartek on 29/09/15.
//

#ifndef ANDROIDPROJECT_TEXTURECUBE_H
#define ANDROIDPROJECT_TEXTURECUBE_H

#include "Texture.h"

namespace Engine
{
     class TextureCube : public Texture
     {
     public:
	  TextureCube(void);
	  ~TextureCube(void);
	  TextureType getType(void) const override;

	  void loadFromAssets(const GLchar *posx, const GLchar *negx,
			      const GLchar *posy, const GLchar *negy,
			      const GLchar *posz, const GLchar *negz);
     };
}

#endif //ANDROIDPROJECT_TEXTURECUBE_H
