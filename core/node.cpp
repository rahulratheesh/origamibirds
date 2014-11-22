#include "node.h"

void Node::input()
{
    for (unsigned int i = 0; i < m_components.size(); i++)
    {
        m_components[i]->input();
    }
    for (unsigned int i = 0; i < m_children.size(); i++)
    {
        m_children[i]->input();
    }
}

void Node::update()
{
    for (unsigned int i = 0; i < m_components.size(); i++)
    {
        m_components[i]->update();
    }
    for (unsigned int i = 0; i < m_children.size(); i++)
    {
        m_children[i]->update();
    }
}

void Node::render()
{
    for (unsigned int i = 0; i < m_components.size(); i++)
    {
        m_components[i]->render();
    }
    for (unsigned int i = 0; i < m_children.size(); i++)
    {
        m_children[i]->render();
    }
}

void Node::addChild(Node* child)
{
    m_children.push_back(child);
}

void Node::addComponent(Component* component)
{
    m_components.push_back(component);
}
