#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <glm/glm.hpp>

class Input
{
    public:

        Input();

        void updateKeyDown(unsigned char keyCode, int x, int y);
        void updateKeyUp(unsigned char keyCode, int x, int y);

        inline bool getKey(int keyCode) const { return m_keys[keyCode]; }
        inline bool getDownKey(int keyCode) const { return m_downKeys[keyCode]; }
        inline bool getUpKey(int keyCode) const { return m_upKeys[keyCode]; }
        inline glm::vec2 getMousePosition() const { return m_mousePosition; }

        inline void setKey(int keyCode, bool value)  { m_keys[keyCode] = value; }
        inline void setDownKey(int keyCode, bool value) { m_downKeys[keyCode] = value; }
        inline void setUpKey(int keyCode, bool value) { m_upKeys[keyCode] = value; }
        inline void setMousePosition(int x, int y) { m_mousePosition = glm::vec2(x, y); }


        virtual ~Input();

        static const int NUM_KEYS = 256;

    protected:

    private:

        bool m_keys[NUM_KEYS];
        bool m_downKeys[NUM_KEYS];
        bool m_upKeys[NUM_KEYS];
        glm::vec2 m_mousePosition;
};

#endif // INPUT_H
