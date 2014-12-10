#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H

#include <glm/glm.hpp>
#include "collider.h"

class PhysicsObject
{
    public:
        PhysicsObject(Collider* collider, glm::vec3 velocity, bool isBoid) :
            m_position(collider->getCenter()),
            m_oldPosition(collider->getCenter()),
            m_velocity(velocity),
            m_collider(collider),
            m_isBoid(isBoid),
            m_isGoingBack(false)

        {}

        void move(float delta);

        inline glm::vec3 getPosition() const { return m_position; }
        inline glm::vec3 getOldPosition() const { return m_oldPosition; }
        inline glm::vec3 getVelocity() const { return m_velocity; }
        inline bool getIsBoid() const { return m_isBoid; }
        inline bool getIsGoingBack() const { return m_isGoingBack; }

        inline void setVelocity(glm::vec3 velocity) { m_velocity = velocity; }
        inline void setIsGoingBack(bool isGoingBack) { m_isGoingBack = isGoingBack; }

        Collider& getCollider() {
            glm::vec3 translate = m_position - m_oldPosition;
            m_oldPosition = m_position;
            m_collider->transform(translate);
            return *m_collider;
        }

        virtual ~PhysicsObject() {}

    protected:

    private:
        glm::vec3 m_position;
        glm::vec3 m_oldPosition;
        glm::vec3 m_velocity;
        Collider* m_collider;

        bool m_isBoid;
        bool m_isGoingBack;

};

#endif // PHYSICSOBJECT_H
