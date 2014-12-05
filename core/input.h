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
        inline glm::vec2 getMouseCoord() const { return m_mouseCoord; }
        inline glm::vec3 getObjCoord() const { return m_objCoord; }
        inline bool getClick() const { return m_click; }

        inline void setKey(int keyCode, bool value)  { m_keys[keyCode] = value; }
        inline void setDownKey(int keyCode, bool value) { m_downKeys[keyCode] = value; }
        inline void setUpKey(int keyCode, bool value) { m_upKeys[keyCode] = value; }
        inline void setMouseCoord(int x, int y) { m_mouseCoord = glm::vec2(x, y); m_click = true; }
        inline void setObjCoord(const glm::vec3& objCoord) { m_objCoord = objCoord; m_click = true; }
        inline void setClick(bool click) { m_click = click; }

        virtual ~Input();

        static const int NUM_KEYS = 256;

    protected:

    private:

        bool m_keys[NUM_KEYS];
        bool m_downKeys[NUM_KEYS];
        bool m_upKeys[NUM_KEYS];
        glm::vec2 m_mouseCoord;
        glm::vec3 m_objCoord;
        bool m_click;
};

#endif // INPUT_H
