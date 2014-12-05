#include "scene.h"


void Scene::init()
{
}

void Scene::input(const Input& input)
{
    m_root.input(input);
}

void Scene::update(float delta)
{
    m_root.update(delta);
}

void Scene::render(RenderingEngine* renderingEngine)
{
    renderingEngine->render(m_root);
}

