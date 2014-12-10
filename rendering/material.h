#ifndef MATERIAL_H
#define MATERIAL_H

#include "texture.h"
#include <glm/glm.hpp>

class Material
{
    public:
        Material(Texture* texture, glm::vec3 color) :
            m_texture(texture),
            m_color(color) {}

        inline Texture* getTexture() const { return m_texture; }
        inline glm::vec3 getColor() const { return m_color; }
        inline float getKa() const { return m_ka; }
        inline float getKd() const { return m_kd; }
        inline float getKs() const { return m_ks; }
        inline float getN() const { return m_n; }

        inline void setTexture(Texture* texture) { m_texture = texture; }
        inline void setColor(const glm::vec3& color) {m_color = color; }
        inline void setKa(float ka) { m_ka = ka; }
        inline void setKd(float kd) { m_kd = kd; }
        inline void setKs(float ks) { m_ks = ks; }
        inline void setN(float n) { m_n = n; }

        virtual ~Material() {}

    protected:

    private:
        Texture* m_texture;
        // base color
        glm::vec3 m_color;
        // ambient factor
        float m_ka;
        // diffuse factor
        float m_kd;
        // specular factor
        float m_ks;
        // shineness
        float m_n;

};

#endif // MATERIAL_H
