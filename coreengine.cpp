#include "coreengine.h"

void runWrapper();
CoreEngine* coreEngineWrapper = NULL;

CoreEngine::CoreEngine(Window* window, Scene* scene, RenderingEngine* renderingEngine)
{
    m_window = window;
    m_scene = scene;
    m_renderingEngine = renderingEngine;
    m_isRunning = false;
}

void CoreEngine::start()
{
    if (m_isRunning) return;

    coreEngineWrapper = this;
    glutIdleFunc( runWrapper );
}

void runWrapper()
{
    coreEngineWrapper->run();
}

void CoreEngine::stop()
{
    m_isRunning = false;
}

void CoreEngine::run()
{
    // Todo: run at 60 FPS

    m_isRunning = true;
    bool startRender = false;

    if (m_isRunning)
    {
        startRender = true;
        m_scene->processInput( m_window->getInput() );
        m_scene->update();
    }

    if (startRender)
    {
        render();
    }

}

void CoreEngine::render()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_scene->render();
    m_window->render();
}

CoreEngine::~CoreEngine()
{
    //dtor
}
