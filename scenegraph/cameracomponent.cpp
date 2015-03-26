#include "cameracomponent.h"
#include "../core/coreengine.h"

void CameraComponent::input(const Input& input)
{
    if (input.getKey((int)'w'))
    {
        m_camera.moveForward();
    }
    if (input.getKey((int)'a'))
    {
        m_camera.lookLeft();
    }
    if (input.getKey((int)'s'))
    {
        m_camera.moveBackward();
    }
    if (input.getKey((int)'d'))
    {
        m_camera.lookRight();
    }
    if (input.getKey((int)'q'))
    {
        m_camera.moveDown();
    }
    if (input.getKey((int)'e'))
    {
        m_camera.moveUp();
    }
}

void CameraComponent::update(float delta)
{
    glm::vec3 currCameraPos = m_camera.getPosiiton();
    glm::vec3 pos = getTransform()->getTranslate();
    currCameraPos.x = pos.x;
    //currCameraPos.y = pos.y;
    if (currCameraPos.y < 0) currCameraPos.y = 0;
    m_camera.setPositon(currCameraPos);
}

void CameraComponent::addToEngine(CoreEngine* coreEngine)
{
    coreEngine->getRenderingEngine()->setCamera(m_camera);
}
