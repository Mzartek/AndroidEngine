//
// Created by Mzartek on 13/10/15.
//

#include "StaticModel.h"

#include "../../Tools/StringHandler.h"
#include "../../Tools/AssimpTool.h"

Engine::StaticModel::StaticModel(const std::shared_ptr<ShaderProgram> &program)
        : Model(program)
{
}

Engine::StaticModel::StaticModel(const std::shared_ptr<StaticModel> &model, const std::shared_ptr<ShaderProgram> &program)
        : Model(model, program)
{
}

Engine::StaticModel::~StaticModel(void)
{
}

void Engine::StaticModel::loadFromFile(const GLchar *inFile)
{
    if (_isMirror == GL_TRUE)
    {
        ALOGE("Error Model configuration");
        throw std::exception();
    }

    _tMesh->clear();

    Assimp::Importer importer;
    const aiScene *pScene = ToolsPrivate::openFile(importer, inFile);
    if (pScene->HasAnimations())
    {
        ALOGE("Error Model configuration");
        throw std::exception();
    }

    std::vector<StaticMesh::Vertex> vertices;
    std::vector<GLuint> indices;
    for (GLuint i = 0; i < pScene->mNumMeshes; i++)
    {
        std::shared_ptr<StaticMesh> mesh = std::make_shared<StaticMesh>(_program);

        vertices = ToolsPrivate::loadStaticVertices(pScene->mMeshes[i]);
        indices = ToolsPrivate::loadIndices(pScene->mMeshes[i]);
        mesh->setMaterial(ToolsPrivate::loadMaterial(pScene->mMaterials[pScene->mMeshes[i]->mMaterialIndex], Tools::getDir(inFile)));

        mesh->load(vertices, indices);

        vertices.clear();
        indices.clear();

        addMesh(mesh);
    }
}

void Engine::StaticModel::display(const std::shared_ptr<PerspCamera> &cam)
{
    checkMatrix();

    Engine::GraphicsRenderer::Instance().setGeometryState();

    glUseProgram(_program->getId());

    glUniformMatrix4fv(_MVPMatrixUniformLocation       , 1, GL_FALSE, glm::value_ptr(cam->getVPMatrix() * _matrix.model));
    glUniformMatrix4fv(_projectionMatrixUniformLocation, 1, GL_FALSE, glm::value_ptr(cam->getProjectionMatrix()));
    glUniformMatrix4fv(_viewMatrixUniformLocation      , 1, GL_FALSE, glm::value_ptr(cam->getViewMatrix()));
    glUniformMatrix4fv(_modelMatrixUniformLocation     , 1, GL_FALSE, glm::value_ptr(_matrix.model));
    glUniformMatrix4fv(_normalMatrixUniformLocation    , 1, GL_FALSE, glm::value_ptr(_matrix.normal));

    for (GLuint i = 0; i < _tMesh->size(); i++)
        if ((*_tMesh)[i]->getMaterial()->getOpacity() == 1.0f)
        {
            if (_cubeTexture)
                (*_tMesh)[i]->display(_cubeTexture);
            else
                (*_tMesh)[i]->display();
        }
}

void Engine::StaticModel::displayTransparent(const std::shared_ptr<PerspCamera> &cam)
{
    checkMatrix();

    Engine::GraphicsRenderer::Instance().setGeometryState();

    glUseProgram(_program->getId());

    glUniformMatrix4fv(_MVPMatrixUniformLocation       , 1, GL_FALSE, glm::value_ptr(cam->getVPMatrix() * _matrix.model));
    glUniformMatrix4fv(_projectionMatrixUniformLocation, 1, GL_FALSE, glm::value_ptr(cam->getProjectionMatrix()));
    glUniformMatrix4fv(_viewMatrixUniformLocation      , 1, GL_FALSE, glm::value_ptr(cam->getViewMatrix()));
    glUniformMatrix4fv(_modelMatrixUniformLocation     , 1, GL_FALSE, glm::value_ptr(_matrix.model));
    glUniformMatrix4fv(_normalMatrixUniformLocation    , 1, GL_FALSE, glm::value_ptr(_matrix.normal));

    for (GLuint i = 0; i < _tMesh->size(); i++)
        if ((*_tMesh)[i]->getMaterial()->getOpacity() < 1.0f)
        {
            if (_cubeTexture)
                (*_tMesh)[i]->display(_cubeTexture);
            else
                (*_tMesh)[i]->display();
        }
}