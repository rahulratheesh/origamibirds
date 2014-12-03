#include "window.h"
#include <GL/glew.h>
#include <GL/glut.h>
#include "../core/input.h"

void renderWrapper();
void keyboardDownWrapper(unsigned char key, int x, int y);
void keyboardUpWrapper(unsigned char key, int x, int y);
void runWrapper();
void mouseMotionWrapper(int x, int y);
void mouseClickedWrapper(int button, int state, int x, int y);
Input* inputWrapper = NULL;
Window* windowWrapper = NULL;

Window::Window(int argc, char* argv[], int width, int height, const std::string& title)
{

    this->m_width = width;
    this->m_height = height;
    this->m_title = title;

    glutInit(&argc, argv);
    glutInitWindowPosition(width/2, height/2);
    glutInitWindowSize(width, height);
    m_window_id = glutCreateWindow(title.c_str());
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

    // create OpenGL context
    GLenum glew_status = glewInit();
    if (glew_status != GLEW_OK) {
        std::cerr << "Error: " << glewGetErrorString(glew_status) << std::endl;
    }

    inputWrapper = &m_input;
    windowWrapper = this;

    glutDisplayFunc( renderWrapper );
    glutKeyboardFunc( keyboardDownWrapper );
    glutKeyboardUpFunc( keyboardUpWrapper );
    glutIgnoreKeyRepeat(1);
    glutMouseFunc( mouseClickedWrapper );
    //glutPassiveMotionFunc( mouseMotionWrapper );

}

void Window::render()
{
    glutSwapBuffers();
}

void Window::update()
{

}

void Window::input()
{

}

void renderWrapper()
{
    windowWrapper->render();
}

void keyboardDownWrapper(unsigned char key, int x, int y)
{
    inputWrapper->updateKeyDown(key, x, y);
}

void keyboardUpWrapper(unsigned char key, int x, int y)
{
    inputWrapper->updateKeyUp(key, x, y);
}

void mouseMotionWrapper(int x, int y)
{
    //inputWrapper->setMousePosition( x, y ) ;
}

void mouseClickedWrapper(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        inputWrapper->setMousePosition(x, y);
    }
}

Window::~Window()
{
    glutDestroyWindow(m_window_id);
}


