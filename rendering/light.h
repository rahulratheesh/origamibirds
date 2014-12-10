#ifndef LIGHT_H
#define LIGHT_H

#include <glm/glm.hpp>

class Light
{
    public:
        Light() {}
    private:
};

class BaseLight
{
    public:
        BaseLight(glm::vec3 color, float intensity) :
            m_color(color),
            m_intensity(intensity)
        {}

        inline const glm::vec3& getColor() const { return m_color; }
        inline const float getIntensity() const { return m_intensity; }

    private:
        glm::vec3 m_color;
        float m_intensity;
};

class DirectionalLight
{
    public:
        DirectionalLight(BaseLight baseLight, glm::vec3 direction) :
            m_baseLight(baseLight),
            m_direction(glm::normalize(direction))
    {}

    inline const BaseLight& getBaseLight() const { return m_baseLight; }
    inline const glm::vec3& getDirection() const { return m_direction; }

    private:
        BaseLight m_baseLight;
        glm::vec3 m_direction;
};

#endif // LIGHT_H
