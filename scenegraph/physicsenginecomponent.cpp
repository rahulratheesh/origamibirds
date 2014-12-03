#include "physicsenginecomponent.h"
#include "../core/timer.h"

void PhysicsEngineComponent::update(float delta)
{
    m_physicsEngine.simulate(delta);
    m_physicsEngine.handleCollision();
}
