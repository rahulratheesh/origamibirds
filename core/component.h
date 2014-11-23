#ifndef COMPONENT_H_INCLUDED
#define COMPONENT_H_INCLUDED

#include "node.h"

class Component
{
    public:
        virtual void input() {}
        virtual void update() {}
        virtual void render(const Shader& shader, const Camera& camera) {}

        inline Transform getTransform() { return m_parent->getTransform(); }

    private:
        Node* m_parent;

};


#endif // COMPONENT_H_INCLUDED
