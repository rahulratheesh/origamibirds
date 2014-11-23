#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "../core/input.h"

class Camera {

    public:

        Camera(const glm::vec3& position, float fov, float aspect, float zNear, float zFar);

        inline glm::vec3& getPosiiton() { return m_position; }
        inline glm::vec3& getDirection() { return m_direction; }
        inline glm::vec3& getUp() { return m_up; }

        inline void setPositon(const glm::vec3& position) { m_position = position; }
        inline void setDirection(const glm::vec3& direction) { m_direction = direction; }
        inline void setUp(const glm::vec3& up) { m_up = up; }

        inline glm::mat4 getViewProjection() const {
            return m_perspective * glm::lookAt(m_position, m_position + m_direction, m_up);
        }

        void moveForward();
        void moveBackward();
        void lookLeft();
        void lookRight();

        void setInput(const Input& input);

        virtual ~Camera() {}

    protected:

    private:
        glm::mat4 m_perspective;
        glm::vec3 m_position;
        glm::vec3 m_direction;
        glm::vec3 m_up;
        float MOVEMENT_SPEED;
};

#endif // CAMERA_H
