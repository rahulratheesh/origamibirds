#include "boundingsphere.h"
#include <iostream>

Intersect BoundingSphere::getIntersection(const BoundingSphere& other)
{
    float centerDistance = glm::length(m_center - other.m_center);
    float radiusDistance = m_radius + other.m_radius;

    if (centerDistance < radiusDistance)
    {
        return Intersect(true, centerDistance - radiusDistance);
    }
    else
    {
        return Intersect(false, centerDistance - radiusDistance);
    }
}

void BoundingSphere::transform(const glm::vec3& translate)
{
    m_center += translate;
}
