#include "physicsengine.h"
#include "intersect.h"

void PhysicsEngine::addObject(const PhysicsObject& physicsObject)
{
    m_objects.push_back(physicsObject);
}

void PhysicsEngine::input(const Input& input)
{
    // leader's position
    glm::vec2 p1;
    p1.x = m_objects[0].getPosition().x;
    p1.y = m_objects[0].getPosition().y;

    // mouse position
    glm::vec2 p2;
    p2.x = input.getObjCoord().x;
    p2.y = input.getObjCoord().y;

    // new force component
    glm::vec2 f = p2 - p1;
    glm::vec3 force = glm::normalize(glm::vec3(f.x, f.y, 0.0f));

    // update velocity
    for (unsigned int i = 0; i < m_objects.size(); i++)
    {
        if (force.x < 0.0)
        {
            m_objects[i].setIsGoingBack(true);
        }
        else
        {
            m_objects[i].setIsGoingBack(false);
        }
        m_objects[i].setVelocity( 0.3f * (m_objects[i].getVelocity() + force) );
    }

}


void PhysicsEngine::simulate(float delta)
{
    for (unsigned int i = 0; i < m_objects.size(); i++)
    {
        if (!m_objects[i].getIsBoid())
            return;

        // simulates Boyd's flocking bird algorithm
        m_objects[i].setVelocity( 0.4f * m_objects[i].getVelocity() );
        m_objects[i].setVelocity( m_objects[i].getVelocity() += cohesion(i) );
        m_objects[i].setVelocity( m_objects[i].getVelocity() += separation(i) );
        m_objects[i].setVelocity( m_objects[i].getVelocity() += (0.1f * alignment(i)) );

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

glm::vec3 PhysicsEngine::separation(unsigned int i)
{
    glm::vec3 force = glm::vec3(0);
    float separationDistance = 0.5f;
    for (unsigned int j = 0; j < m_objects.size(); j++)
    {
        if (j != i)
        {
            if ( pow(glm::distance(m_objects[j].getPosition(), m_objects[i].getPosition()),2) < separationDistance)
            {
                glm::vec3 heading = m_objects[i].getPosition() - m_objects[j].getPosition();
                float scale = glm::length(heading) / sqrt(separationDistance);
                force = glm::normalize(heading) / scale;
            }
        }
    }

    return force;
}

glm::vec3 PhysicsEngine::alignment(unsigned int i)
{
    glm::vec3 force = glm::vec3(0);
    int neighbours = 0;
    for (unsigned int j = 0; j < m_objects.size(); j++)
    {
        if (j != i)
        {
            force += m_objects[j].getVelocity();
            neighbours++;
        }
    }
    if (neighbours > 0)
    {
        force /= neighbours;
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
            Intersect intersect = m_objects[i].getCollider().getIntersection(m_objects[j].getCollider());
            if (intersect.getDoesIntersect())
            {
                m_objects[i].setVelocity( -1.0f * m_objects[i].getVelocity() );
                m_objects[j].setVelocity( -1.0f * m_objects[j].getVelocity() );
            }
        }
    }

}
