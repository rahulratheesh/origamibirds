#include "physicsenginecomponent.h"
#include "../core/input.h"

void PhysicsEngineComponent::input(const Input& input)
{
    m_physicsEngine.input(input);
}

void PhysicsEngineComponent::update(float delta)
{
    m_physicsEngine.simulate(delta);
    m_physicsEngine.handleCollision();
}
