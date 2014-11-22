#include "texture.h"
#include <iostream>
#include <SOIL/SOIL.h>
#include <cassert>

Texture::Texture(const string& file_name) {
    int width, height, channels;
    unsigned char* image_data = SOIL_load_image(file_name.c_str(), &width, &height, &channels, SOIL_LOAD_AUTO);

    if (image_data == NULL) {
        cerr << "Failed to load texture: " << file_name << endl;
    }

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_data);
    SOIL_free_image_data(image_data);
}

Texture::~Texture() {
    glDeleteTextures(1, &texture);
}

void Texture::bind(unsigned int texture_id) {
    assert(texture_id >= 0 && texture_id <= 31);
    glActiveTexture(GL_TEXTURE0 + texture_id);
    glBindTexture(GL_TEXTURE_2D, texture);
}


