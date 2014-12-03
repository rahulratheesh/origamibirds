#ifndef PLANE_H
#define PLANE_H

#include <glm/glm.hpp>
#include "intersect.h"
#include "boundingsphere.h"

class Plane : public Collider
{
    public:
        Plane(const glm::vec3& normal, float distance) :
            Collider(Collider::PLANE),
            m_normal(normal),
            m_distance(distance) {}

        Plane normalized();
        Intersect getIntersection(const BoundingSphere& other);

        inline glm::vec3 getNormal() const { return m_normal; }
        inline float getDistance() const { return m_distance; }

        virtual ~Plane() {}

    protected:

    private:
        glm::vec3 m_normal;
        float m_distance;
};

#endif // PLANE_H
