#include "physicsengine.h"

void PhysicsEngine::addPObject(const PhysicsObject& po)
{
    m_objects.push_back(po);
}

void PhysicsEngine::simulate(float delta)
{
    for (unsigned int i = 0; i < m_objects.size(); i++)
    {
        m_objects[i].move(delta);
    }
}
