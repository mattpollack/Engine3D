#include "Display.h"
#include <memory>

namespace Display {
    std::unique_ptr<sf::Window> window;

    void init() {
        // Causes warnings but makes shaders work...
        sf::ContextSettings settings;
        settings.majorVersion = 4;
        settings.minorVersion = 3;
        settings.depthBits = 24;

        window = std::make_unique<sf::Window>(sf::VideoMode(WIDTH, HEIGHT), "Window", sf::Style::Close, settings);

        glewExperimental = GL_TRUE;
        glewInit();
        glViewport(0, 0, WIDTH, HEIGHT);
        glEnable(GL_DEPTH_TEST);
        glDepthMask(GL_TRUE);

        printf("%s\n", glGetString(GL_VERSION));
    }

    void clear() {
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void display() {
        window->display();
    }

    void checkWindowEvents() {
        sf::Event e;

        while (window->pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window->close();
            }
        }
    }

    bool isOpen() {
        return window->isOpen();
    }
}
