#ifndef SCENE_H
#define SCENE_H

#include "../rendering/renderingengine.h"
#include "../scenegraph/node.h"

class Scene
{
    public:
        Scene() {}

        virtual void init(const Window& window);
        void input(const Input& input);
        virtual void update(float delta);
        void render(RenderingEngine* renderingEngine);

        inline Node getRootNode() const { return m_root; }

        inline void setEngine(CoreEngine* engine) {
            m_root.setEngine(engine); }
        virtual ~Scene() {}

    protected:
        void addToScene(Node* child) { m_root.addChild(child); }

    private:
        Node m_root;


};

#endif // SCENE_H
