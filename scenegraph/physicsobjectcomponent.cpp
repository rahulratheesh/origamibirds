#include "physicsobjectcomponent.h"

void PhysicsObjectComponent::update(float delta)
{
    getTransform()->setTranslate(m_physicsObject->getPosition());

    if (m_physicsObject->getIsGoingBack())
    {
        getTransform()->setRotate(glm::vec3(0.0f, -90.0f, 0.0f));
    }
    else
    {
        getTransform()->setRotate(glm::vec3(0.0f, 90.0f, 0.0f));
    }
}

