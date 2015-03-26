#include "physicsengine.h"
#include "intersect.h"
#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alut.h>

void PhysicsEngine::addObject(const PhysicsObject& physicsObject)
{
    m_objects.push_back(physicsObject);
}

void PhysicsEngine::input(const Input& input)
{
    // update velocity
    glm::vec3 newVelocity = glm::vec3(m_objects[0].getVelocity().x, -0.2f, 0.0f);
    if (input.getClick() == true)
    {
        float force = 0.02f;
        newVelocity = glm::vec3(m_objects[0].getVelocity().x, m_objects[0].getVelocity().y + force, 0.0f);
    }

    m_objects[0].setVelocity( newVelocity );

}

void PhysicsEngine::playMusic()
{
    ALuint buffer, source;
    ALint state;
    // Initialize the environment
    alutInit(0, NULL);
    // Capture errors
    alGetError();
    // Load pcm data into buffer
    buffer = alutCreateBufferFromFile("xmas_birds.wav");
    // Create sound source (use buffer to fill source)
    alGenSources(1, &source);
    alSourcei(source, AL_BUFFER, buffer);
    // Play
    alSourcePlay(source);
    // Wait for the song to complete
    do {
        alGetSourcei(source, AL_SOURCE_STATE, &state);
    } while (state == AL_PLAYING);
    // Clean up sources and buffers
    alDeleteSources(1, &source);
    alDeleteBuffers(1, &buffer);
    // Exit everything
    alutExit();
}


void PhysicsEngine::simulate(float delta)
{
    for (unsigned int i = 0; i < m_objects.size(); i++)
    {
        if (!m_objects[i].getIsBoid())
            return;

        // simulates Boyd's flocking bird algorithm
//        m_objects[i].setVelocity( 0.4f * m_objects[i].getVelocity() );
//        m_objects[i].setVelocity( m_objects[i].getVelocity() += cohesion(i) );
//        m_objects[i].setVelocity( m_objects[i].getVelocity() += separation(i) );
//        m_objects[i].setVelocity( m_objects[i].getVelocity() += (0.1f * alignment(i)) );

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
    float separationDistance = 0.7f;
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
            if ( m_objects[i].getIsBoid() && m_objects[j].getIsBoid() )
                return ;

            Intersect intersect = m_objects[i].getCollider().getIntersection(m_objects[j].getCollider());
            if (intersect.getDoesIntersect())
            {
                //std::cout << "Object " << i << " collided with object " << j << std::endl;
                m_objects[i].setVelocity( -1.0f * m_objects[i].getVelocity() );
                //m_objects[j].setVelocity( -1.0f * m_objects[j].getVelocity() );
            }
        }
    }

}
