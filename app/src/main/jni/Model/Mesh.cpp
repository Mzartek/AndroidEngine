//
// Created by khavranek on 07/10/15.
//

#include "Mesh.h"

Engine::Mesh::Mesh(const std::shared_ptr<ShaderProgram> &_program)
        : _material(nullptr), _numElement(0)
{
    _vertexBuffer = std::make_shared<Buffer>();
    _indexBuffer = std::make_shared<Buffer>();

    memset(_tex, 0, sizeof _tex);

    _diffuseMaterialUniformLocation = glGetUniformLocation(_program->getId(), "diffuseMaterial");
    _specularMaterialUniformLocation = glGetUniformLocation(_program->getId(), "specularMaterial");
    _ambientMaterialUniformLocation = glGetUniformLocation(_program->getId(), "ambientMaterial");
    _emissiveMaterialUniformLocation = glGetUniformLocation(_program->getId(), "emissiveMaterial");
    _shininessMaterialUniformLocation = glGetUniformLocation(_program->getId(), "shininessMaterial");
    _opacityMaterialUniformLocation = glGetUniformLocation(_program->getId(), "opacityMaterial");

    _tex[0].hasTexUniformLocation = glGetUniformLocation(_program->getId(), "hasDiffuseTexture");
    _tex[1].hasTexUniformLocation = glGetUniformLocation(_program->getId(), "hasSpecularTexture");
    _tex[2].hasTexUniformLocation = glGetUniformLocation(_program->getId(), "hasAmbientTexture");
    _tex[3].hasTexUniformLocation = glGetUniformLocation(_program->getId(), "hasEmissiveTexture");
    _tex[4].hasTexUniformLocation = glGetUniformLocation(_program->getId(), "hasShininessTexture");
    _tex[5].hasTexUniformLocation = glGetUniformLocation(_program->getId(), "hasOpacityTexture");
    _tex[6].hasTexUniformLocation = glGetUniformLocation(_program->getId(), "hasBumpMap");
    _tex[7].hasTexUniformLocation = glGetUniformLocation(_program->getId(), "hasNormalMap");
    _tex[8].hasTexUniformLocation = glGetUniformLocation(_program->getId(), "hasDisplacementMap");
    _tex[9].hasTexUniformLocation = glGetUniformLocation(_program->getId(), "hasLightMap");
};

Engine::Mesh::~Mesh(void)
{
}

void Engine::Mesh::setMaterial(const std::shared_ptr<Material> &material)
{
    memset(_tex, 0, sizeof _tex);

    _material = material;

    if ((_tex[0].hasTex = _material->hasDiffuseTexture()))
        _tex[0].id = _material->getDiffuseTexture()->getId();

    if ((_tex[1].hasTex = _material->hasSpecularTexture()))
        _tex[1].id = _material->getSpecularTexture()->getId();

    if ((_tex[2].hasTex = _material->hasAmbientTexture()))
        _tex[2].id = _material->getAmbientTexture()->getId();

    if ((_tex[3].hasTex = _material->hasEmissiveTexture()))
        _tex[3].id = _material->getEmissiveTexture()->getId();

    if ((_tex[4].hasTex = _material->hasShininessTexture()))
        _tex[4].id = _material->getShininessTexture()->getId();

    if ((_tex[5].hasTex = _material->hasOpacityTexture()))
        _tex[5].id = _material->getOpacityTexture()->getId();

    if ((_tex[6].hasTex = _material->hasBumpMap()))
        _tex[6].id = _material->getBumpMap()->getId();

    if ((_tex[7].hasTex = _material->hasNormalMap()))
        _tex[7].id = _material->getNormalMap()->getId();

    if ((_tex[8].hasTex = _material->hasDisplacementMap()))
        _tex[8].id = _material->getDisplacementMap()->getId();

    if ((_tex[9].hasTex = _material->hasLightMap()))
        _tex[9].id = _material->getLightMap()->getId();
}

const std::shared_ptr<Engine::Material> &Engine::Mesh::getMaterial(void) const
{
    return _material;
}

void Engine::Mesh::display(void) const
{
    this->bindMaterials();
    this->bindTextures();

    this->startDrawing();
    glDrawElements(GL_TRIANGLES, _numElement, GL_UNSIGNED_INT, nullptr);
    this->endDrawing();
}

void Engine::Mesh::display(const std::shared_ptr<TextureCube> &cubeTexture) const
{
    this->bindMaterials();
    this->bindTextures();

    glActiveTexture(GL_TEXTURE10);
    glBindTexture(GL_TEXTURE_CUBE_MAP, cubeTexture->getId());

    this->startDrawing();
    glDrawElements(GL_TRIANGLES, _numElement, GL_UNSIGNED_INT, nullptr);
    this->endDrawing();
}

void Engine::Mesh::displayShadow(void) const
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _tex[0].id);
    glUniform1i(_tex[0].hasTexUniformLocation, _tex[0].hasTex);

    this->startDrawing();
    glDrawElements(GL_TRIANGLES, _numElement, GL_UNSIGNED_INT, nullptr);
    this->endDrawing();
}

void Engine::Mesh::bindTextures() const
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _tex[0].id);
    glUniform1i(_tex[0].hasTexUniformLocation, _tex[0].hasTex);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, _tex[1].id);
    glUniform1i(_tex[1].hasTexUniformLocation, _tex[1].hasTex);

    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, _tex[2].id);
    glUniform1i(_tex[2].hasTexUniformLocation, _tex[2].hasTex);

    glActiveTexture(GL_TEXTURE3);
    glBindTexture(GL_TEXTURE_2D, _tex[3].id);
    glUniform1i(_tex[3].hasTexUniformLocation, _tex[3].hasTex);

    glActiveTexture(GL_TEXTURE4);
    glBindTexture(GL_TEXTURE_2D, _tex[4].id);
    glUniform1i(_tex[4].hasTexUniformLocation, _tex[4].hasTex);

    glActiveTexture(GL_TEXTURE5);
    glBindTexture(GL_TEXTURE_2D, _tex[5].id);
    glUniform1i(_tex[5].hasTexUniformLocation, _tex[5].hasTex);

    glActiveTexture(GL_TEXTURE6);
    glBindTexture(GL_TEXTURE_2D, _tex[6].id);
    glUniform1i(_tex[6].hasTexUniformLocation, _tex[6].hasTex);

    glActiveTexture(GL_TEXTURE7);
    glBindTexture(GL_TEXTURE_2D, _tex[7].id);
    glUniform1i(_tex[7].hasTexUniformLocation, _tex[7].hasTex);

    glActiveTexture(GL_TEXTURE8);
    glBindTexture(GL_TEXTURE_2D, _tex[8].id);
    glUniform1i(_tex[8].hasTexUniformLocation, _tex[8].hasTex);

    glActiveTexture(GL_TEXTURE9);
    glBindTexture(GL_TEXTURE_2D, _tex[9].id);
    glUniform1i(_tex[9].hasTexUniformLocation, _tex[9].hasTex);
}

void Engine::Mesh::bindMaterials() const
{
    glUniform3fv(_diffuseMaterialUniformLocation, 1, glm::value_ptr(_material->getDiffuse()));
    glUniform3fv(_specularMaterialUniformLocation, 1, glm::value_ptr(_material->getSpecular()));
    glUniform3fv(_ambientMaterialUniformLocation, 1, glm::value_ptr(_material->getAmbient()));
    glUniform3fv(_emissiveMaterialUniformLocation, 1, glm::value_ptr(_material->getEmissive()));
    glUniform1f(_shininessMaterialUniformLocation, _material->getShininess());
    glUniform1f(_opacityMaterialUniformLocation, _material->getOpacity());
}

bool Engine::CompareMesh::operator()(const std::shared_ptr<Mesh> &first, const std::shared_ptr<Mesh> &second)
{
    if (first->_material == nullptr)
        return false;
    if (first->_material->getOpacity() < second->_material->getOpacity())
        return true;
    return false;
}

