#ifndef COMPONENT_H_INCLUDED
#define COMPONENT_H_INCLUDED

#include "node.h"
#include <iostream>

class Component
{
    public:
        virtual void input(float delta) {}
        virtual void update(float delta) {}
        virtual void render(const Shader& shader, const Camera& camera) {}

        inline Transform* getTransform() { return m_parent->getTransform(); }

        void setParent(Node* parent) { m_parent = parent; }

    private:
        Node* m_parent;

};


#endif // COMPONENT_H_INCLUDED
