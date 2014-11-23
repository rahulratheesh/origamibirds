#include "camera.h"

Camera::Camera(const glm::vec3& position, float fov, float aspect, float zNear, float zFar)
{
    m_perspective = glm::perspective(fov, aspect, zNear, zFar);
    m_position = position;
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
    glm::vec3 strafeDirection = glm::cross(m_direction, m_up);
    m_position += -MOVEMENT_SPEED * strafeDirection;
}

void Camera::lookRight()
{
    glm::vec3 strafeDirection = glm::cross(m_direction, m_up);
    m_position += MOVEMENT_SPEED * strafeDirection;
}

void Camera::input(const Input& input)
{
    if (input.getKey((int)'w'))
    {
        moveForward();
    }
    if (input.getKey((int)'a'))
    {
        lookLeft();
    }
    if (input.getKey((int)'s'))
    {
        moveBackward();
    }
    if (input.getKey((int)'d'))
    {
        lookRight();
    }
}


