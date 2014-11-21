#include "boundingbox.h"


Intersect BoundingBox::getIntersection(const BoundingBox& other)
{
    glm::vec3 d1 = other.getMinExtent() - m_maxExtent;
    glm::vec3 d2 = m_minExtent - other.getMaxExtent();
    glm::vec3 d = maxVec3(d1, d2);

    float maxDistance = maxValue(d);

    return Intersect( maxDistance < 0, maxDistance );

}

glm::vec3 BoundingBox::maxVec3(const glm::vec3& r, const glm::vec3& s) {
    glm::vec3 result;
    for (unsigned int i = 0; i < 3; i++)
    {
        result[i] = r[i] > s[i] ? r[i] : s[i];
    }
    return result;
}

float BoundingBox::maxValue(const glm::vec3& r)
{
    float maxVal = r[0];
    for (unsigned int i = 0; i < 3; i++)
    {
        if (r[i] > maxVal) maxVal = r[i];
    }
    return maxVal;
}

BoundingBox::~BoundingBox()
{
}
