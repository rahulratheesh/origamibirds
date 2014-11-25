#include "timer.h"
#include <GL/glew.h>
#include <GL/glut.h>

double Timer::getElapsedTimeInMilliSeconds()
{
    return glutGet(GLUT_ELAPSED_TIME);
}

double Timer::getElapsedTimeInSeconds()
{
    return glutGet(GLUT_ELAPSED_TIME) / 1000.0;
}
