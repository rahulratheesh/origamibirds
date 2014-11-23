#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>
#include "rendering/window.h"
#include "core/coreengine.h"
#include "scene.h"
#include "rendering/renderingengine.h"

int main(int argc, char* argv[])
{
    Window window(argc, argv, 800, 600, "OpenGL window");
    RenderingEngine renderingEngine(window);

    Scene scene;
    scene.init();
    CoreEngine coreEngine(&scene, &renderingEngine);
    coreEngine.start();

    glutMainLoop();
    return EXIT_SUCCESS;
}
