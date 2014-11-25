#include "scene.h"


void Scene::init()
{
}

void Scene::input(float delta)
{
    m_root.input(delta);
}

void Scene::update(float delta)
{
    m_root.update(delta);
}

void Scene::render(RenderingEngine* renderingEngine)
{
    renderingEngine->render(m_root);
}

