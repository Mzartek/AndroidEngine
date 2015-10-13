//
// Created by Mzartek on 13/10/15.
//

#include "StaticMesh.h"

Engine::StaticMesh::StaticMesh(const std::shared_ptr<ShaderProgram> &_program)
    : Mesh::Mesh(_program), _stride(11 * sizeof(GLfloat))
{
}

Engine::StaticMesh::~StaticMesh(void)
{
}

void Engine::StaticMesh::load(GLsizei numVertex, const Vertex *vertexArray, GLsizei numIndex, const GLuint *indexArray)
{
    _numElement = numIndex;

    _vertexBuffer->createStore(GL_ARRAY_BUFFER, vertexArray, numVertex * sizeof *vertexArray, GL_STATIC_DRAW);
    _indexBuffer->createStore(GL_ELEMENT_ARRAY_BUFFER, indexArray, numIndex * sizeof *indexArray, GL_STATIC_DRAW);
}

void Engine::StaticMesh::load(const std::vector<Vertex> &vertices, const std::vector<GLuint> &indices)
{
    load(static_cast<GLsizei>(vertices.size()), vertices.data(), static_cast<GLsizei>(indices.size()), indices.data());
}

Engine::MeshType Engine::StaticMesh::getType(void) const
{
    return STATIC_MESH;
}

void Engine::StaticMesh::startDrawing() const
{
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer->getId());
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBuffer->getId());
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _stride, BUFFER_OFFSET(0));
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, _stride, BUFFER_OFFSET(3 * sizeof(GLfloat)));
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, _stride, BUFFER_OFFSET(5 * sizeof(GLfloat)));
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, _stride, BUFFER_OFFSET(8 * sizeof(GLfloat)));
}

void Engine::StaticMesh::endDrawing() const
{
    glDisableVertexAttribArray(3);
    glDisableVertexAttribArray(2);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}