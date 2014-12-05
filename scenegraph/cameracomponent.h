#ifndef CAMERACOMPONENT_H
#define CAMERACOMPONENT_H

#include "component.h"
#include "../rendering/camera.h"

class Input;

class CameraComponent : public Component
{
    public:
        CameraComponent(const Camera& camera) :
            m_camera(camera)
        {

        }

        void input(const Input& input);
        void update(float delta);
        void addToEngine(CoreEngine* engine);

    private:
        Camera m_camera;
};

#endif // CAMERACOMPONENT_H
