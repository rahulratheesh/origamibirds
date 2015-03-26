#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include <vector>
#include "physicsobject.h"
#include "../core/input.h"
#include <iostream>

class PhysicsEngine
{
    public:
        PhysicsEngine() { m_music = false; }

        void addObject(const PhysicsObject& physicsObject);
        void simulate(float delta);
        void handleCollision();
        void playMusic();
        void input(const Input& input);

        inline const PhysicsObject& getObject(unsigned int index) const { return m_objects[index]; }
        inline unsigned int getNumObjects() const { return m_objects.size(); }

        virtual ~PhysicsEngine() {}

    protected:

    private:
        std::vector<PhysicsObject> m_objects;
        glm::vec3 cohesion(unsigned int i);
        glm::vec3 separation(unsigned int i);
        glm::vec3 alignment(unsigned int i);
        bool m_music;
};

#endif // PHYSICSENGINE_H
