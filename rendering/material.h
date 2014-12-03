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
        inline void setTexture(Texture* texture) { m_texture = texture; }
        inline void setColor(const glm::vec3& color) {m_color = color; }

        virtual ~Material() {}

    protected:

    private:
        Texture* m_texture;
        glm::vec3 m_color;
};

#endif // MATERIAL_H
