#include "node.h"
#include "component.h"
#include <iostream>

void Node::input(const Input& input)
{
    for (unsigned int i = 0; i < m_components.size(); i++)
    {
        m_components[i]->input(input);
    }
    for (unsigned int i = 0; i < m_children.size(); i++)
    {
        m_children[i]->input(input);
    }
}

void Node::update(float delta)
{
    for (unsigned int i = 0; i < m_components.size(); i++)
    {
        m_components[i]->update(delta);
    }
    for (unsigned int i = 0; i < m_children.size(); i++)
    {
        m_children[i]->update(delta);
    }
}

void Node::render(const Shader& shader, const Camera& camera)
{
    for (unsigned int i = 0; i < m_components.size(); i++)
    {
        m_components[i]->render(shader, camera);
    }
    for (unsigned int i = 0; i < m_children.size(); i++)
    {
        m_children[i]->render(shader, camera);
    }
}

void Node::addChild(Node* child)
{
    m_children.push_back(child);
    child->getTransform()->setParent(&m_transform);
    child->setEngine(m_coreEngine);
}

void Node::addComponent(Component* component)
{
    m_components.push_back(component);
    component->setParent(this);
}

void Node::setEngine(CoreEngine* engine)
{
	if(m_coreEngine != engine)
	{
		m_coreEngine = engine;

		for(unsigned int i = 0; i < m_components.size(); i++)
		{
			m_components[i]->addToEngine(engine);
		}

		for(unsigned int i = 0; i < m_children.size(); i++)
		{
			m_children[i]->setEngine(engine);
		}
	}
}
