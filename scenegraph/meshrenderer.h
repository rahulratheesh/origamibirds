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
            glm::mat4 m = getTransform()->getModel();
            glm::mat4 mvp = camera.getViewProjection() * m;
            shader.setUniformMatrix4f("u_transform", mvp);
            shader.setUniformMatrix4f("u_normal_transform", glm::transpose(glm::inverse(m)));
            shader.setUniformVector3f("u_color", m_material.getColor());

            shader.setUniformVector3f("u_ambient", glm::vec3(1.0, 1.0, 1.0));
            shader.setUniformDirectionalLight("u_directionalLight",
                                              *new DirectionalLight(*new BaseLight(glm::vec3(1.0f, 1.0f, 1.0f), 0.25f), glm::vec3(1.0f, 1.0f, 1.0f))) ;
            m_mesh.draw();
        }

    private:
        Mesh m_mesh;
        Material m_material;

};


#endif // MESHRENDERER_H_INCLUDED
