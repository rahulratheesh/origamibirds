#ifndef RENDERINGENGINE_H
#define RENDERINGENGINE_H

#include <GL/glew.h>
#include <GL/glut.h>
#include "window.h"
#include "camera.h"
#include "shader.h"
#include "../core/node.h"
#include "../core/input.h"

class RenderingEngine
{
    public:
        RenderingEngine(Window& window);

        void render(Node& node);
        void input(const Input& input);

        inline Window* getWindow() const { return m_window; }
        virtual ~RenderingEngine() {}

    protected:

    private:
        Window* m_window;
        Camera* m_mainCamera;
        Shader* m_basicShader;
};

#endif // RENDERINGENGINE_H
