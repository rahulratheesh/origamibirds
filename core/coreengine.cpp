#include "coreengine.h"

void runWrapper();
CoreEngine* coreEngineWrapper = NULL;

CoreEngine::CoreEngine(Scene* scene, RenderingEngine* renderingEngine)
{
    m_scene = scene;
    m_renderingEngine = renderingEngine;
    m_isRunning = false;
}

void CoreEngine::start()
{
    if (m_isRunning) return;

    m_scene->init();

    coreEngineWrapper = this;
    glutIdleFunc( runWrapper );
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
        m_scene->input();
        m_renderingEngine->input( m_renderingEngine->getWindow()->getInput() );
        m_scene->update();
    }

    if (startRender)
    {
        m_scene->render(m_renderingEngine);
    }

}

void runWrapper()
{
    coreEngineWrapper->run();
}
