#include "renderingengine.h"

RenderingEngine::RenderingEngine(Window& window)
{
    m_window = &window;

    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_DEPTH_CLAMP);
}

void RenderingEngine::render()
{

}

RenderingEngine::~RenderingEngine()
{
    //dtor
}
