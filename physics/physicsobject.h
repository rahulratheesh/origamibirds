#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H

#include <glm/glm.hpp>

class PhysicsObject
{
    public:
        PhysicsObject(glm::vec3 position, glm::vec3 velocity) :
            m_position(position),
            m_velocity(velocity) {}

        void move(float delta);

        inline glm::vec3 getPosition() const { return m_position; }
        inline glm::vec3 getVelocity() const { return m_velocity; }

        virtual ~PhysicsObject() {}

    protected:

    private:
        glm::vec3 m_position;
        glm::vec3 m_velocity;

};

#endif // PHYSICSOBJECT_H
