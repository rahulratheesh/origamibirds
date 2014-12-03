#include "physicsengine.h"
#include "intersect.h"

void PhysicsEngine::addObject(const PhysicsObject& physicsObject)
{
    m_objects.push_back(physicsObject);
}

// simulates Boyd's flocking bird algorithm
void PhysicsEngine::simulate(float delta)
{
    for (unsigned int i = 0; i < m_objects.size(); i++)
    {
        m_objects[i].setVelocity(0.01f * (m_objects[i].getVelocity() + cohesion(i)));
        m_objects[i].move(delta);
    }
}

glm::vec3 PhysicsEngine::cohesion(unsigned int i)
{
    glm::vec3 force = glm::vec3(0);
    glm::vec3 centreOfMass = glm::vec3(0);
    int neighbours = 0;
    for (unsigned int j = 0; j < m_objects.size(); j++)
    {
        if (j != i)
        {
            centreOfMass += m_objects[j].getPosition();
            neighbours++;
        }
    }
    if (neighbours > 0)
    {
        centreOfMass /= neighbours;
        force = centreOfMass - m_objects[i].getPosition();
        force = glm::normalize(force);
    }
    return force;
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
