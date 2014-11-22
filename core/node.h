#ifndef NODE_H
#define NODE_H

#include <vector>
#include "component.h"
#include "transform.h"

class Node
{
    public:
        Node() {}

        void input();
        void update();
        void render();

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
