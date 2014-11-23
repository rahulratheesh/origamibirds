#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>
#include "rendering/window.h"
#include "core/coreengine.h"
#include "scene01.h"
#include "rendering/renderingengine.h"

int main(int argc, char* argv[])
{
    Window window(argc, argv, 800, 600, "OpenGL window");
    RenderingEngine renderingEngine(window);

    Scene01 scene;
    CoreEngine coreEngine(&scene, &renderingEngine);
    coreEngine.start();

    glutMainLoop();
    return EXIT_SUCCESS;
}
