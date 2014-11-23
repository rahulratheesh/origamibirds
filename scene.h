#ifndef SCENE_H
#define SCENE_H

#include "core/input.h"
#include "rendering/mesh.h"
#include "rendering/shader.h"
#include "rendering/camera.h"
#include "core/transform.h"
#include "core/timer.h"
#include "rendering/camera.h"
#include "rendering/texture.h"
#include "core/node.h"

class Scene
{
    public:
        Scene() {}

        void init();
        void processInput(const Input& input);
        void update();
        void render();

        virtual ~Scene();
    protected:

    private:

        Node m_root;
        Mesh* m_mesh;
        Shader* m_shader;
        Texture* m_texture;
        Transform* m_transform;
        Camera* m_camera;
        glm::vec2 oldMousePosition;
};

#endif // SCENE_H
