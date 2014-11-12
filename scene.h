#ifndef SCENE_H
#define SCENE_H

#include "input.h"
#include "mesh.h"
#include "shader.h"
#include "camera.h"
#include "transform.h"
#include "timer.h"
#include "camera.h"
#include "texture.h"

class Scene
{
    public:
        Scene();

        void processInput(const Input& input);
        void update();
        void render();

        virtual ~Scene();
    protected:

    private:

        Mesh* m_mesh;
        Shader* m_shader;
        Texture* m_texture;
        Transform* m_transform;
        Camera* m_camera;
        glm::vec2 oldMousePosition;
};

#endif // SCENE_H
