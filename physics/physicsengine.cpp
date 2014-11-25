#include "physicsengine.h"
#include "intersect.h"

void PhysicsEngine::addObject(const PhysicsObject& physicsObject)
{
    m_objects.push_back(physicsObject);
}

void PhysicsEngine::simulate(float delta)
{
    for (unsigned int i = 0; i < m_objects.size(); i++)
    {
        m_objects[i].move(delta);
    }
}

void PhysicsEngine::handleCollision()
{
    for (unsigned int i = 0; i < m_objects.size(); i++)
    {
        for (unsigned int j = i+1; j < m_objects.size(); j++)
        {
            Intersect intersect = m_objects[i].getBoundingSphere().getIntersection(m_objects[j].getBoundingSphere());
            if (intersect.getDoesIntersect())
            {
                m_objects[i].setVelocity( -1.0f * m_objects[i].getVelocity() );
                m_objects[j].setVelocity( -1.0f * m_objects[j].getVelocity() );
            }
        }
    }

}
