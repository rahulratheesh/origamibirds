#ifndef PHYSICSENGINECOMPONENT_H
#define PHYSICSENGINECOMPONENT_H

#include "../core/component.h"
#include "physicsengine.h"

class PhysicsEngineComponent : public Component
{
    public:
        PhysicsEngineComponent(const PhysicsEngine& physicsEngine) :
            m_physicsEngine(physicsEngine)
        {}

        void update(float delta);

        inline const PhysicsEngine& getPhysicsEngine() const { return m_physicsEngine; }
        virtual ~PhysicsEngineComponent() {}

    protected:

    private:
        PhysicsEngine m_physicsEngine;
};

#endif // PHYSICSENGINECOMPONENT_H
