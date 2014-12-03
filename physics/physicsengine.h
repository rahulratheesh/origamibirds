#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include <vector>
#include "physicsobject.h"
#include <iostream>

class PhysicsEngine
{
    public:
        PhysicsEngine() {}

        void addObject(const PhysicsObject& physicsObject);
        void simulate(float delta);
        void handleCollision();

        inline const PhysicsObject& getObject(unsigned int index) const { return m_objects[index]; }
        inline unsigned int getNumObjects() const { return m_objects.size(); }

        virtual ~PhysicsEngine() {}

    protected:

    private:
        std::vector<PhysicsObject> m_objects;
        glm::vec3 cohesion(unsigned int i);
};

#endif // PHYSICSENGINE_H
