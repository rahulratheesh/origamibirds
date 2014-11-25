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
    glm::vec3 strafeDirection = glm::cross(m_direction, m_up);
    m_position += -MOVEMENT_SPEED * strafeDirection;
}

void Camera::lookRight()
{
    glm::vec3 strafeDirection = glm::cross(m_direction, m_up);
    m_position += MOVEMENT_SPEED * strafeDirection;
}

void Camera::moveDown()
{
    m_position += MOVEMENT_SPEED * m_up;
}

void Camera::moveUp()
{
    m_position -= MOVEMENT_SPEED * m_up;
}

void Camera::setInput(const Input& input)
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
    if (input.getKey((int)'q'))
    {
        moveDown();
    }
    if (input.getKey((int)'e'))
    {
        moveUp();
    }
}




