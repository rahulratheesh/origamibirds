#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>
#include "window.h"
#include "coreengine.h"
#include "scene.h"
#include "renderingengine.h"

#include "boundingsphere.h"
#include "boundingbox.h"
#include "intersect.h"

int main(int argc, char* argv[])
{

//    BoundingSphere s1( glm::vec3(0.0f, 0.0f, 0.0f), 1.0f );
//    BoundingSphere s2( glm::vec3(1.0f, 0.0f, 0.0f), 1.0f );

    BoundingBox s1( glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(5.0f, 2.0f, 0.0f) );
    BoundingBox s2( glm::vec3(4.0f, 1.0f, 0.0f), glm::vec3(10.0f, 7.0f, 0.0f) );

    Intersect info1 = s1.getIntersection(s2);

    std::cout << "Interesect = "  << info1.getDoesIntersect() << " Distance = " << info1.getDistance() << std::endl;


    /**
    Window window(argc, argv, 800, 600, "OpenGL window");
    RenderingEngine renderingEngine(window);

    Scene scene;
    CoreEngine coreEngine(&window, &scene, &renderingEngine);
    coreEngine.start();

    glutMainLoop();
    return EXIT_SUCCESS;
    **/
}
