#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include <vector>
#include "physicsobject.h"

class PhysicsEngine
{
    public:
        PhysicsEngine() {}

        void addPObject(const PhysicsObject& po);
        void simulate(float delta);

        virtual ~PhysicsEngine() {}

    protected:

    private:
        std::vector<PhysicsObject> m_objects;
};

#endif // PHYSICSENGINE_H
