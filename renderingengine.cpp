#include "renderingengine.h"

RenderingEngine::RenderingEngine(const Window& window)
{
    m_window = &window;

    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_FRAMEBUFFER_SRGB);
}

void RenderingEngine::render()
{

}

RenderingEngine::~RenderingEngine()
{
    //dtor
}