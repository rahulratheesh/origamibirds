#include "physicsenginecomponent.h"

void PhysicsEngineComponent::update(float delta)
{
    m_physicsEngine.simulate(delta);
}
