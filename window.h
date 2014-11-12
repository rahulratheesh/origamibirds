#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <glm/glm.hpp>
#include "input.h"

class Window
{
    public:
        Window(int argc, char* argv[], int width, int height, const std::string& title);

        void render();
        void update();
        void input();

        inline int getWidth() const { return m_width; }
        inline int getHeight() const { return m_height; }
        inline const std::string& getTitle() const { return m_title; }
        inline glm::vec2 getCenter() const { return glm::vec2((float) m_width/2.0f, (float) m_height/2.0f); }
        inline float getAspectRatio() const { return (float) m_width / (float) m_height; }
        inline const Input& getInput() const { return m_input; }

        virtual ~Window();

    private:

        int m_window_id;
        int m_width;
        int m_height;
        std::string m_title;
        Input m_input;
};

#endif // WINDOW_H
