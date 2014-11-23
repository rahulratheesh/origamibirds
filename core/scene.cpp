#include "scene.h"
#include "../rendering/shader.h"

void Scene::init()
{
}

void Scene::processInput(const Input& input)
{
    m_camera->input(input);
    m_root.input();
}

void Scene::update()
{
    m_root.update();
}

void Scene::render()
{
    Shader shader;
    shader.addUniform("u_transform");
    m_root.render(shader, *m_camera);
}

Scene::~Scene()
{
}
