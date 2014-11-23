#ifndef MESHRENDERER_H_INCLUDED
#define MESHRENDERER_H_INCLUDED

#include "component.h"
#include "../rendering/mesh.h"
#include "../rendering/texture.h"
#include "../rendering/shader.h"
#include <glm/glm.hpp>

class MeshRenderer : public Component
{
    public:
        MeshRenderer(const Mesh& mesh, const Texture& texture) :
            m_mesh(mesh),
            m_texture(texture) {}

        void input() {}
        void update() {}

        void render(const Shader& shader, const Camera& camera)
        {
            shader.bind();
            glm::mat4 mvp = camera.getViewProjection() * getTransform().getModel();
            shader.setUniformMatrix4f("u_transform", mvp);
            m_mesh.draw();
        }

    private:
        Mesh m_mesh;
        Texture m_texture;

};


#endif // MESHRENDERER_H_INCLUDED
