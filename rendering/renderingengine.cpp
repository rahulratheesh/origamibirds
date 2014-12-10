#include "renderingengine.h"

RenderingEngine::RenderingEngine(Window& window)
{
    m_window = &window;
    m_window->setRenderingEngine(this);
    m_shader = new Shader("phong");

    m_shader->addUniform("u_transform");
    m_shader->addUniform("u_normal_transform");
    m_shader->addUniform("u_color");
    m_shader->addUniform("u_ambient");

    m_shader->addUniform("u_directionalLight.baseLight.color");
    m_shader->addUniform("u_directionalLight.baseLight.intensity");
    m_shader->addUniform("u_directionalLight.direction");

    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);
    //glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_DEPTH_CLAMP);
    glClearColor(0.62f, 0.74f, 0.9f, 1.0f);
}

void RenderingEngine::render(Node& node)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    node.render(*m_shader, *m_mainCamera);
    m_window->render();
}
