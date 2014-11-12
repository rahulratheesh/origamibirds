#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>
#include "window.h"
#include "coreengine.h"
#include "scene.h"
#include "renderingengine.h"

int main(int argc, char* argv[])
{
    Window window(argc, argv, 800, 600, "OpenGL window");
    RenderingEngine renderingEngine(window);

    Scene scene;
    CoreEngine coreEngine(&window, &scene, &renderingEngine);
    coreEngine.start();

    glutMainLoop();
    return EXIT_SUCCESS;
}
