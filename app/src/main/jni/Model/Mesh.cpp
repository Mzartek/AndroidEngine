//
// Created by khavranek on 07/10/15.
//

#include "Mesh.h"

Engine::Mesh::Mesh(void)
        : _material(nullptr), _numElement(0)
{
    _vertexBuffer = std::make_shared<Buffer>();
    _indexBuffer = std::make_shared<Buffer>();

    memset(_tex, 0, sizeof _tex);
};

Engine::Mesh::~Mesh(void)
{
}

void Engine::Mesh::setMaterial(const std::shared_ptr<Material> &material)
{
    memset(_tex, 0, sizeof _tex);

    _material = material;

    if (_material->hasDiffuseTexture())
        _tex[0] = _material->getDiffuseTexture()->getId();

    if (_material->hasSpecularTexture())
        _tex[1] = _material->getSpecularTexture()->getId();

    if (_material->hasAmbientTexture())
        _tex[2] = _material->getAmbientTexture()->getId();

    if (_material->hasEmissiveTexture())
        _tex[3] = _material->getEmissiveTexture()->getId();

    if (_material->hasShininessTexture())
        _tex[4] = _material->getShininessTexture()->getId();

    if (_material->hasOpacityTexture())
        _tex[5] = _material->getOpacityTexture()->getId();

    if (_material->hasBumpMap())
        _tex[6] = _material->getBumpMap()->getId();

    if (_material->hasNormalMap())
        _tex[7] = _material->getNormalMap()->getId();

    if (_material->hasDisplacementMap())
        _tex[8] = _material->getDisplacementMap()->getId();

    if (_material->hasLightMap())
        _tex[9] = _material->getLightMap()->getId();
}

const std::shared_ptr<Engine::Material> &Engine::Mesh::getMaterial(void) const
{
    return _material;
}

void Engine::Mesh::display(void) const
{
    //glBindBufferBase(GL_UNIFORM_BUFFER, 2, _material->getMatBuffer());
    //glBindBufferBase(GL_UNIFORM_BUFFER, 3, _material->getStateBuffer());

    //glBindVertexArray(_idVAO);
    //glDrawElements(GL_TRIANGLES, _numElement, GL_UNSIGNED_INT, nullptr);
    //glBindVertexArray(0);
}

void Engine::Mesh::display(const std::shared_ptr<TextureCube> &cubeTexture) const
{
    glActiveTexture(GL_TEXTURE10);
    glBindTexture(GL_TEXTURE_CUBE_MAP, cubeTexture->getId());

    //glBindBufferBase(GL_UNIFORM_BUFFER, 2, _material->getMatBuffer());
    //glBindBufferBase(GL_UNIFORM_BUFFER, 3, _material->getStateBuffer());

    //glBindVertexArray(_idVAO);
    //glDrawElements(GL_TRIANGLES, _numElement, GL_UNSIGNED_INT, nullptr);
    //glBindVertexArray(0);
}

void Engine::Mesh::displayShadow(void) const
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _tex[0]);

    //glBindVertexArray(_idVAO);
    //glDrawElements(GL_TRIANGLES, _numElement, GL_UNSIGNED_INT, nullptr);
    //glBindVertexArray(0);
}

void Engine::Mesh::bindTextures() const
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _tex[0]);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, _tex[1]);

    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, _tex[2]);

    glActiveTexture(GL_TEXTURE3);
    glBindTexture(GL_TEXTURE_2D, _tex[3]);

    glActiveTexture(GL_TEXTURE4);
    glBindTexture(GL_TEXTURE_2D, _tex[4]);

    glActiveTexture(GL_TEXTURE5);
    glBindTexture(GL_TEXTURE_2D, _tex[5]);

    glActiveTexture(GL_TEXTURE6);
    glBindTexture(GL_TEXTURE_2D, _tex[6]);

    glActiveTexture(GL_TEXTURE7);
    glBindTexture(GL_TEXTURE_2D, _tex[7]);

    glActiveTexture(GL_TEXTURE8);
    glBindTexture(GL_TEXTURE_2D, _tex[8]);

    glActiveTexture(GL_TEXTURE9);
    glBindTexture(GL_TEXTURE_2D, _tex[9]);
}

void Engine::Mesh::bindMaterials() const
{
}

bool Engine::CompareMesh::operator()(const std::shared_ptr<Mesh> &first, const std::shared_ptr<Mesh> &second)
{
    if (first->_material == nullptr)
        return false;
    if (first->_material->getOpacity() < second->_material->getOpacity())
        return true;
    return false;
}

