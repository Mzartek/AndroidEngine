//
// Created by Mzartek on 13/10/15.
//

#include "AssimpTool.h"
#include <assimp/postprocess.h>

const aiScene *Engine::ToolsPrivate::openFile(Assimp::Importer &importer, const GLchar *inFile)
{
    const aiScene *pScene = importer.ReadFile(inFile, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_CalcTangentSpace | aiProcess_JoinIdenticalVertices | aiProcess_OptimizeMeshes);
    if (!pScene)
    {
        ALOGE("Failed to load model File: %s", inFile);
        ALOGE("%s", importer.GetErrorString());
        throw std::exception();
    }

    return pScene;
}

std::vector<Engine::StaticMesh::Vertex> Engine::ToolsPrivate::loadStaticVertices(const aiMesh *mesh)
{
    std::vector<StaticMesh::Vertex> vertices;

    for (GLuint i = 0; i < mesh->mNumVertices; i++)
    {
        const aiVector3D Zero3D(0.0f, 0.0f, 0.0f);
        const aiVector3D pPos = mesh->mVertices[i];
        const aiVector3D pTexCoord = mesh->HasTextureCoords(0) ? mesh->mTextureCoords[0][i] : Zero3D;
        const aiVector3D pNormal = mesh->HasNormals() ? mesh->mNormals[i] : Zero3D;
        const aiVector3D pTangent = mesh->HasTangentsAndBitangents() ? mesh->mTangents[i] : Zero3D;

        StaticMesh::Vertex newVertex = {
                { pPos.x, pPos.y, pPos.z },
                { pTexCoord.x, pTexCoord.y },
                { pNormal.x, pNormal.y, pNormal.z },
                { pTangent.x, pTangent.y, pTangent.z }
        };

        vertices.push_back(newVertex);
    }

    return vertices;
}

std::vector<GLuint> Engine::ToolsPrivate::loadIndices(const aiMesh *mesh)
{
    std::vector<GLuint> indices;
    for (GLuint i = 0; i < mesh->mNumFaces; i++)
    {
        indices.push_back(mesh->mFaces[i].mIndices[0]);
        indices.push_back(mesh->mFaces[i].mIndices[1]);
        indices.push_back(mesh->mFaces[i].mIndices[2]);
    }

    return indices;
}

std::shared_ptr<Engine::Material> Engine::ToolsPrivate::loadMaterial(const aiMaterial *material, const std::string &dir)
{
    std::shared_ptr<Material> newMaterial = std::make_shared<Material>();

    const aiTextureType _textureType[] = {
            aiTextureType_DIFFUSE, aiTextureType_SPECULAR,
            aiTextureType_AMBIENT, aiTextureType_EMISSIVE,
            aiTextureType_SHININESS, aiTextureType_OPACITY,
            aiTextureType_HEIGHT, aiTextureType_NORMALS,
            aiTextureType_DISPLACEMENT, aiTextureType_LIGHTMAP,
    };

    // Textures
    for (GLuint i = 0; i < (sizeof _textureType / sizeof *_textureType); i++)
    {
        aiString path;
        if (material->GetTexture(_textureType[i], 0, &path, nullptr, nullptr, nullptr, nullptr, nullptr) == AI_SUCCESS)
        {
            std::string filePath = dir + path.C_Str();
            std::shared_ptr<Texture2D> newTexture = std::make_shared<Texture2D>();

            newTexture->loadFromFile(filePath.c_str());

            switch (_textureType[i])
            {
                case aiTextureType_DIFFUSE:
                    newMaterial->setDiffuseTexture(newTexture);
                    break;
                case aiTextureType_SPECULAR:
                    newMaterial->setSpecularTexture(newTexture);
                    break;
                case aiTextureType_AMBIENT:
                    newMaterial->setAmbientTexture(newTexture);
                    break;
                case aiTextureType_EMISSIVE:
                    newMaterial->setEmissiveTexture(newTexture);
                    break;
                case aiTextureType_SHININESS:
                    newMaterial->setShininessTexture(newTexture);
                    break;
                case aiTextureType_OPACITY:
                    newMaterial->setOpacityTexture(newTexture);
                    break;
                case aiTextureType_HEIGHT:
                    newMaterial->setBumpMap(newTexture);
                    break;
                case aiTextureType_NORMALS:
                    newMaterial->setNormalMap(newTexture);
                    break;
                case aiTextureType_DISPLACEMENT:
                    newMaterial->setDisplacementMap(newTexture);
                    break;
                case aiTextureType_LIGHTMAP:
                    newMaterial->setLightMap(newTexture);
                    break;
                default:
                    break;
            }
        }
    }

    aiColor4D tmp;

    material->Get(AI_MATKEY_COLOR_DIFFUSE, tmp);
    newMaterial->setDiffuse(glm::vec3(tmp.r, tmp.g, tmp.b));

    material->Get(AI_MATKEY_COLOR_SPECULAR, tmp);
    newMaterial->setSpecular(glm::vec3(tmp.r, tmp.g, tmp.b));

    material->Get(AI_MATKEY_COLOR_AMBIENT, tmp);
    newMaterial->setAmbient(glm::vec3(tmp.r, tmp.g, tmp.b));

    material->Get(AI_MATKEY_COLOR_EMISSIVE, tmp);
    newMaterial->setEmissive(glm::vec3(tmp.r, tmp.g, tmp.b));

    material->Get(AI_MATKEY_SHININESS, tmp);
    newMaterial->setShininess(tmp.r);

    material->Get(AI_MATKEY_OPACITY, tmp);
    newMaterial->setOpacity(tmp.r);

    return newMaterial;
}
