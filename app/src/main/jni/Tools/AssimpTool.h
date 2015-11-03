//
// Created by Mzartek on 13/10/15.
//

#ifndef ANDROIDPROJECT_ASSIMPTOOL_H
#define ANDROIDPROJECT_ASSIMPTOOL_H

#include "../Model/Material.h"

#include "../Model/Static/StaticMesh.h"

#include "../Object.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>

namespace Engine
{
     namespace ToolsPrivate
     {
	  extern const aiScene *openAsset(Assimp::Importer &importer, const GLchar *asset);
	  extern std::vector<StaticMesh::Vertex> loadStaticVertices(const aiMesh *mesh);
	  extern std::vector<GLuint> loadIndices(const aiMesh *mesh);
	  extern std::shared_ptr<Material> loadMaterial(const aiMaterial *material, const std::string &dir);
     }
}

#endif //ANDROIDPROJECT_ASSIMPTOOL_H
