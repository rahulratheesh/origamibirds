#include "renderingengine.h"

RenderingEngine::RenderingEngine(Window& window)
{
    m_window = &window;
    m_mainCamera = new  Camera(70.0, m_window->getAspectRatio(), 0.1f, 100.0f);
    m_basicShader = new Shader();
    m_basicShader->addUniform("u_transform");

    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_DEPTH_CLAMP);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void RenderingEngine::render(Node& node)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    node.render(*m_basicShader, *m_mainCamera);
    m_window->render();
}

void RenderingEngine::input(const Input& input)
{
    m_mainCamera->setInput(input);
}
