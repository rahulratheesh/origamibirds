#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>
#include "rendering/window.h"
#include "core/coreengine.h"
#include "scene03.h"
#include "scene02.h"
#include "scene01.h"
#include "rendering/renderingengine.h"

int main(int argc, char* argv[])
{
    Window window(argc, argv, 1000, 500, "OpenGL window");
    RenderingEngine renderingEngine(window);

    Scene03 scene;
    CoreEngine coreEngine(&scene, &renderingEngine);
    coreEngine.start();

    glutMainLoop();
    return EXIT_SUCCESS;
}
