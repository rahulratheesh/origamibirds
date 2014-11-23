#ifndef COREENGINE_H
#define COREENGINE_H

#include "../rendering/window.h"
#include "scene.h"
#include "../rendering/renderingengine.h"

class CoreEngine
{
    public:
        CoreEngine(Scene* scene, RenderingEngine* renderingEngine);

        void start();
        void stop();
        void run();
        void render();

        virtual ~CoreEngine() {}
    protected:

    private:
        bool m_isRunning;
        Scene* m_scene;
        RenderingEngine* m_renderingEngine;
};

#endif // COREENGINE_H
