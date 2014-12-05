#include "input.h"

Input::Input()
{
    for (int i = 0; i < Input::NUM_KEYS; i++)
    {
        setKey(i, false);
        setDownKey(i, false);
        setUpKey(i, false);
    }
    m_click = false;
}

Input::~Input()
{
    //dtor
}

void Input::updateKeyDown(unsigned char keyCode, int x, int y)
{
    //std::cout << "You have pressed a key: " << (int)keyCode << std::endl;
    int key = (int) keyCode;
    setKey(key, true);
    setDownKey(key, true);
}

void Input::updateKeyUp(unsigned char keyCode, int x, int y)
{
    //std::cout << "You have released a key: " << (int)keyCode << std::endl;
    int key = (int) keyCode;
    setKey(key, false);
    setUpKey(key, true);
}
