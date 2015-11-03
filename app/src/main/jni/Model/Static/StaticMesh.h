//
// Created by Mzartek on 13/10/15.
//

#ifndef ANDROIDPROJECT_STATICMESH_H
#define ANDROIDPROJECT_STATICMESH_H

#include "../Mesh.h"

namespace Engine
{
     class StaticMesh : public Mesh
     {
     private:
	  GLsizei _stride;

	  GLint _vertexAttributeLocation;
	  GLint _textureAttributeLocation;
	  GLint _normalAttributeLocation;
	  GLint _tangentAttributeLocation;

     public:
	  struct Vertex
	  {
	       glm::vec3 position;
	       glm::vec2 texCoord;
	       glm::vec3 normal;
	       glm::vec3 tangent;
	  };

	  StaticMesh(const std::shared_ptr<ShaderProgram> &_program);
	  ~StaticMesh(void);
	  void load(GLsizei numVertex, const Vertex *vertexArray, GLsizei numIndex, const GLuint *indexArray);
	  void load(const std::vector<Vertex> &vertices, const std::vector<GLuint> &indices);

	  MeshType getType(void) const override;

     private:
	  void startDrawing(void) const override;
	  void endDrawing(void) const override;
     };
}

#endif //ANDROIDPROJECT_STATICMESH_H
