#ifndef PHYSICSOBJECTCOMPONENT_H
#define PHYSICSOBJECTCOMPONENT_H

#include "component.h"
#include "../physics/physicsobject.h"

class Input;

class PhysicsObjectComponent : public Component
{
    public:
        PhysicsObjectComponent(const PhysicsObject* physicsObject) :
            m_physicsObject(physicsObject)
        {}

        void update(float delta);
        void input(Input& input);

        virtual ~PhysicsObjectComponent() {}

    protected:

    private:
        const PhysicsObject* m_physicsObject;
};

#endif // PHYSICSOBJECTCOMPONENT_H
