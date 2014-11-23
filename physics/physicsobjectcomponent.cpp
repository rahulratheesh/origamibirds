#include "physicsobjectcomponent.h"

void PhysicsObjectComponent::update(float delta)
{
    std::cout << "POC 1" << std::endl;
    getTransform().setTranslate(m_physicsObject->getPosition());
}
