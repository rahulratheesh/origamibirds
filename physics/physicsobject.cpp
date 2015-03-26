#include "physicsobject.h"
#include <iostream>

void PhysicsObject::move(float delta)
{
    if (m_position.y < -1.1 || m_position.y > 4.1 )
    {
        std::cout << "Game Over!!" << std::endl;
        exit(0);
    }

    m_position += m_velocity * delta;

}
