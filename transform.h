#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Transform {
    public:
        Transform(const glm::vec3 translate_vector = glm::vec3(),
                  const glm::vec3 rotate_vector = glm::vec3(),
                  const glm::vec3 scale_vector = glm::vec3(1.0f, 1.0f, 1.0f)) {
            m_translate_vector = translate_vector;
            m_rotate_vector = rotate_vector;
            m_scale_vector = scale_vector;
        }
        virtual ~Transform() {}

        inline glm::vec3& getTranslateVector() { return m_translate_vector; }
        inline glm::vec3& getRotateVector() { return m_rotate_vector; }
        inline glm::vec3& getScaleVector() { return m_scale_vector; }

        inline void setTranslateVector(const glm::vec3& translate_vector) { this->m_translate_vector = translate_vector; }
        inline void setTranslateVector(double x, double y, double z) { this->m_translate_vector = glm::vec3(x, y, z); }
        inline void setRotateVector(const glm::vec3& rotate_vector) { this->m_rotate_vector = rotate_vector; }
        inline void setScaleVector(const glm::vec3& scale_vector) { this->m_scale_vector = scale_vector; }

        inline glm::mat4 getModel() const {

            glm::mat4 translate_matrix = glm::translate(m_translate_vector);

            glm::mat4 rotate_matrix_x = glm::rotate(m_rotate_vector.x, glm::vec3(1, 0, 0));
            glm::mat4 rotate_matrix_y = glm::rotate(m_rotate_vector.y, glm::vec3(0, 1, 0));
            glm::mat4 rotate_matrix_z = glm::rotate(m_rotate_vector.z, glm::vec3(0, 0, 1));
            glm::mat4 rotate_matrix = rotate_matrix_z * rotate_matrix_y * rotate_matrix_x;

            glm::mat4 scale_matrix = glm::scale(m_scale_vector);

            return translate_matrix * rotate_matrix * scale_matrix;

        }

    protected:

    private:
        glm::vec3 m_translate_vector;
        glm::vec3 m_rotate_vector;
        glm::vec3 m_scale_vector;
};

#endif // TRANSFORM_H