#ifndef RENDERINGENGINE_H
#define RENDERINGENGINE_H

#include <GL/glew.h>
#include <GL/glut.h>
#include "window.h"

class RenderingEngine
{
    public:
        RenderingEngine(Window& window);

        void render();

        inline Window* getWindow() const { return m_window; }
        virtual ~RenderingEngine();

    protected:

    private:
        Window* m_window;
};

#endif // RENDERINGENGINE_H
