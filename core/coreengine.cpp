#include "coreengine.h"
#include "timer.h"

void runWrapper();
CoreEngine* coreEngineWrapper = NULL;

CoreEngine::CoreEngine(Scene* scene, RenderingEngine* renderingEngine)
{
    m_scene = scene;
    m_renderingEngine = renderingEngine;
    m_isRunning = false;
    m_frameTime = 1/60.0;
    m_scene->setEngine(this);
}

void CoreEngine::start()
{
    if (m_isRunning) return;

    m_scene->init( *m_renderingEngine->getWindow() );

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
        m_scene->input( m_renderingEngine->getWindow()->getInput() );
        m_scene->update(m_frameTime);
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
