#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H

#include <glm/glm.hpp>
#include "boundingsphere.h"

class PhysicsObject
{
    public:
        PhysicsObject(glm::vec3 position, glm::vec3 velocity) :
            m_position(position),
            m_velocity(velocity),
            m_radius(1.0f) {}

        void move(float delta);

        inline glm::vec3 getPosition() const { return m_position; }
        inline glm::vec3 getVelocity() const { return m_velocity; }
        inline void setVelocity(glm::vec3 velocity) { m_velocity = velocity; }

        BoundingSphere getBoundingSphere() const { return BoundingSphere(m_position, m_radius); }

        virtual ~PhysicsObject() {}

    protected:

    private:
        glm::vec3 m_position;
        glm::vec3 m_velocity;
        float m_radius;

};

#endif // PHYSICSOBJECT_H
