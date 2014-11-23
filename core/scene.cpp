#include "scene.h"


void Scene::init()
{
}

void Scene::input()
{
    m_root.input();
}

void Scene::update()
{
    m_root.update();
}

void Scene::render(RenderingEngine* renderingEngine)
{
    renderingEngine->render(m_root);
}

