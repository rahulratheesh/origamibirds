#include "camera.h"

Camera::Camera(float fov, float aspect, float zNear, float zFar)
{
    m_perspective = glm::perspective(fov, aspect, zNear, zFar);
    m_position = glm::vec3(0.0, 0.0, 0.0);
    m_direction = glm::vec3(0.0, 0.0, -1.0);
    m_up = glm::vec3(0.0, 1.0, 0.0);

    MOVEMENT_SPEED = 0.01f;
}

void Camera::moveForward()
{
    m_position += MOVEMENT_SPEED * m_direction;
}

void Camera::moveBackward()
{
    m_position += -MOVEMENT_SPEED * m_direction;
}

void Camera::lookLeft()
{
    glm::vec3 left = glm::normalize(glm::cross(m_direction, m_up));
    left = -MOVEMENT_SPEED * left;
    m_position += left;
}

void Camera::lookRight()
{
    glm::vec3 right = glm::normalize(glm::cross(m_direction, m_up));
    right = MOVEMENT_SPEED * right;
    m_position += right;
}

void Camera::moveDown()
{
    m_position += MOVEMENT_SPEED * m_up;
}

void Camera::moveUp()
{
    m_position -= MOVEMENT_SPEED * m_up;
}




