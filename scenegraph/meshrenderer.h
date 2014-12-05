#ifndef MESHRENDERER_H_INCLUDED
#define MESHRENDERER_H_INCLUDED

#include "component.h"
#include "../rendering/mesh.h"
#include "../rendering/material.h"
#include "../rendering/shader.h"
#include <glm/glm.hpp>

class MeshRenderer : public Component
{
    public:
        MeshRenderer(const Mesh& mesh, const Material& material) :
            m_mesh(mesh),
            m_material(material) {}

        void input(const Input& input) {}
        void update(float delta) {}

        void render(const Shader& shader, const Camera& camera)
        {
            shader.bind();
            m_material.getTexture()->bind();
            glm::mat4 mvp = camera.getViewProjection() * getTransform()->getModel();
            shader.setUniformMatrix4f("u_transform", mvp);
            shader.setUniformVector3f("u_color", m_material.getColor());
            m_mesh.draw();
        }

    private:
        Mesh m_mesh;
        Material m_material;

};


#endif // MESHRENDERER_H_INCLUDED
