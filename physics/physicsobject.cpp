#include "physicsobject.h"

void PhysicsObject::move(float delta)
{
    m_position += m_velocity * delta;
}
