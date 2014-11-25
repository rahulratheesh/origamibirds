#ifndef NODE_H
#define NODE_H

#include <vector>
#include "../core/transform.h"

class Component;
class Shader;
class Camera;

class Node
{
    public:
        Node(const glm::vec3& pos = glm::vec3(0.0f, 0.0f, 0.0f),
             const glm::vec3& rot = glm::vec3(0.0f, 0.0f, 0.0f),
             const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f)) :
            m_transform(pos, rot, scale)
            {}

        void input(float delta);
        void update(float delta);
        void render(const Shader& shader, const Camera& camera);

        void addChild(Node* child);
        void addComponent(Component* component);

        inline Transform* getTransform() { return &m_transform; }

        virtual ~Node() {}
    protected:

    private:
        std::vector<Node*> m_children;
        std::vector<Component*> m_components;
        Transform m_transform;
};

#endif // NODE_H
