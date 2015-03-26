#include "physicsobjectcomponent.h"
#include "../core/input.h"

void PhysicsObjectComponent::update(float delta)
{
    getTransform()->setTranslate(m_physicsObject->getPosition());

}


