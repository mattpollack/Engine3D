#ifndef _DISPLAY_H
#define _DISPLAY_H

#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

namespace Display {
    void init();
    void clear();
    void display();
    void checkWindowEvents();
    bool isOpen();

    const int HEIGHT = 480;
    const int WIDTH = 640;
}

#endif
