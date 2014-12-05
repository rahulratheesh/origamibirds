#include "renderingengine.h"

RenderingEngine::RenderingEngine(Window& window)
{
    m_window = &window;
    m_window->setRenderingEngine(this);
    m_basicShader = new Shader();
    m_basicShader->addUniform("u_transform");
    m_basicShader->addUniform("u_color");

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
    node.render(*m_basicShader, *m_mainCamera);
    m_window->render();
}
