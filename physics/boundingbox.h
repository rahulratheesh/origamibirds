#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <glm/glm.hpp>
#include "intersect.h"

class BoundingBox
{
    public:
        BoundingBox(glm::vec3 minExtent, glm::vec3 maxExtent) :
            m_minExtent(minExtent),
            m_maxExtent(maxExtent) {}

        Intersect getIntersection(const BoundingBox& other);

        inline glm::vec3 getMinExtent() const { return m_minExtent; }
        inline glm::vec3 getMaxExtent() const { return m_maxExtent; }


        virtual ~BoundingBox() {}

    protected:

    private:
        glm::vec3 m_minExtent;
        glm::vec3 m_maxExtent;

        glm::vec3 maxVec3(const glm::vec3& r, const glm::vec3& s);
        float maxValue(const glm::vec3& r);
};

#endif // BOUNDINGBOX_H
