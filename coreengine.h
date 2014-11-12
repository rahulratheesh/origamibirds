#ifndef COREENGINE_H
#define COREENGINE_H

#include "window.h"
#include "scene.h"
#include "renderingengine.h"

class CoreEngine
{
    public:
        CoreEngine(Window* window, Scene* scene, RenderingEngine* renderingEngine);

        void start();
        void stop();
        void run();
        void render();

        virtual ~CoreEngine();
    protected:

    private:
        bool m_isRunning;
        Window* m_window;
        Scene* m_scene;
        RenderingEngine* m_renderingEngine;
};

#endif // COREENGINE_H
