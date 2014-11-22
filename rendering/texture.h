#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <GL/glew.h>
using namespace std;

class Texture {
    public:
        Texture(const string& file_name);
        virtual ~Texture();
        void bind(unsigned int texture_id);

    protected:

    private:
        Texture(const Texture& other) {}
        void operator=(const Texture& other) {}
        GLuint texture;
};

#endif // TEXTURE_H
