#ifndef SCENE_H
#define SCENE_H

#include "../rendering/renderingengine.h"
#include "node.h"

class Scene
{
    public:
        Scene() {}

        virtual void init();
        void input();
        void update();
        void render(RenderingEngine* renderingEngine);

        inline Node getRootNode() const { return m_root; }
        Camera* m_camera;

        virtual ~Scene() {}

    protected:
        void addToScene(Node* child) { m_root.addChild(child); }

    private:
        Node m_root;


};

#endif // SCENE_H
