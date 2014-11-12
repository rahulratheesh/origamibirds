#ifndef RENDERINGENGINE_H
#define RENDERINGENGINE_H

#include <GL/glew.h>
#include <GL/glut.h>
#include "window.h"

class RenderingEngine
{
    public:
        RenderingEngine(const Window& window);

        void render();

        virtual ~RenderingEngine();

    protected:

    private:
        const Window* m_window;
};

#endif // RENDERINGENGINE_H
