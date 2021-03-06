#ifndef BOUNDINGSPHERE_H
#define BOUNDINGSPHERE_H

#include <glm/glm.hpp>
#include "intersect.h"
#include "collider.h"

class BoundingSphere : public Collider
{
    public:
        BoundingSphere(glm::vec3 center, float radius) :
            Collider(Collider::SPHERE),
            m_center(center),
            m_radius(radius) {}

        Intersect getIntersection(const BoundingSphere& other);
        void transform(const glm::vec3& translate);

        inline glm::vec3 getCenter() const { return m_center; }
        inline float getRadius() const { return m_radius; }

        virtual ~BoundingSphere() {}

    protected:

    private:

        glm::vec3 m_center;
        float m_radius;
};

#endif // BOUNDINGSPHERE_H
