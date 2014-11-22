#include "plane.h"

Plane Plane::normalized()
{
    float magnitude = glm::length(m_normal);
    return Plane(m_normal/magnitude, m_distance/magnitude);
}

Intersect Plane::getIntersection(const BoundingSphere& other)
{
    float distanceToSphere = fabs(glm::dot(m_normal, other.getCenter())) + m_distance;
    float distanceToSphereRadius = distanceToSphere - other.getRadius();

    return Intersect(distanceToSphereRadius < 0, distanceToSphereRadius);
}

