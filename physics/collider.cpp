#include "collider.h"
#include "boundingsphere.h"
#include "boundingbox.h"
#include "plane.h"
#include <iostream>

Intersect Collider::getIntersection(const Collider& other)
{
    if (m_type == SPHERE && other.getType() == SPHERE)
    {
        BoundingSphere* self = (BoundingSphere*)this;
        return self->getIntersection((BoundingSphere&)other);
    }
    if (m_type == BOX && other.getType() == BOX)
    {
        BoundingBox* self = (BoundingBox*)this;
        return self->getIntersection((BoundingBox&)other);
    }
    if (m_type == PLANE && other.getType() == SPHERE)
    {
        Plane* self = (Plane*)this;
        return self->getIntersection((BoundingSphere&)other);
    }
    std::cerr << "Error: Collision detection not implemented" << std::endl;
    exit(1);

    return Intersect(false, 0);

}
