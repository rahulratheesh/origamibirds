#include "physicsobject.h"
#include <iostream>

void PhysicsObject::move(float delta)
{
    m_position += m_velocity * delta;
}
