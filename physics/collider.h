#ifndef COLLIDER_H
#define COLLIDER_H

#include "intersect.h"
#include <glm/glm.hpp>

class Collider
{
    public:
        enum { SPHERE, BOX, PLANE, SIZE};

        Collider(int type) :
            m_type(type) {}

        Intersect getIntersection(const Collider& other);

        // to be overriden by subclasses
        virtual void transform(const glm::vec3& translation) {}
        virtual glm::vec3 getCenter() const { return glm::vec3(0.0f, 0.0f, 0.0f); }

        inline int getType() const { return m_type; }
    protected:


    private:
        int m_type;
};

#endif // COLLIDER_H
