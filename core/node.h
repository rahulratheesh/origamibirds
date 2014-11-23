#ifndef NODE_H
#define NODE_H

#include <vector>
#include "transform.h"

class Component;
class Shader;
class Camera;

class Node
{
    public:
        Node() {}

        void input();
        void update();
        void render(const Shader& shader, const Camera& camera);

        void addChild(Node* child);
        void addComponent(Component* component);

        inline Transform getTransform() const { return m_transform; }

        virtual ~Node() {}
    protected:

    private:
        std::vector<Node*> m_children;
        std::vector<Component*> m_components;
        Transform m_transform;
};

#endif // NODE_H
