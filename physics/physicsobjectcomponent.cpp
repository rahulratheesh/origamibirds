#include "physicsobjectcomponent.h"

void PhysicsObjectComponent::update(float delta)
{
    getTransform()->setTranslate(m_physicsObject->getPosition());
}
