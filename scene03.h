#ifndef SCENE03_H_INCLUDED
#define SCENE03_H_INCLUDED

#include "core/scene.h"

class Scene03 : public Scene
{
    public:
        Scene03() {}

        void init(const Window& window);
        void update(float delta);

        virtual ~Scene03() {}
};

#endif // SCENE03_H_INCLUDED
