#ifndef PHYSICSOBJECTCOMPONENT_H
#define PHYSICSOBJECTCOMPONENT_H

#include "../core/component.h"
#include "physicsobject.h"

class PhysicsObjectComponent : public Component
{
    public:
        PhysicsObjectComponent(const PhysicsObject* physicsObject) :
            m_physicsObject(physicsObject)
        {}

        void update(float delta);

        virtual ~PhysicsObjectComponent() {}

    protected:

    private:
        const PhysicsObject* m_physicsObject;
};

#endif // PHYSICSOBJECTCOMPONENT_H
