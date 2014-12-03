#ifndef SCENE02_H
#define SCENE02_H

#include "core/scene.h"

class Scene02 : public Scene
{
    public:
        Scene02() {}

        void init();
        void update(float delta);

        virtual ~Scene02() {}
};

#endif // SCENE02_H
