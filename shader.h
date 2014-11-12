#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>
#include "transform.h"
#include "camera.h"
#include <iostream>
#include <vector>
#include <map>

class Shader {

    public:
        Shader(const std::string& file_name = "basic");


        void bind();
        void update(const Transform& transform, const Camera& camera);

        void addUniform(std::string uniformName);
        void setUniformi(const std::string& uniformName, int value) const;
        void setUniformf(const std::string& uniformName, float value) const;
        void setUniformVector3f(const std::string& uniformName, const glm::vec3& value) const;
        void setUniformMatrix4f(const std::string& uniformName, const glm::mat4& value) const;

        virtual ~Shader();

    protected:

    private:
        enum {U_TRANSFORM, NUM_UNIFORMS};

        GLuint m_program;
        std::vector<int>  m_shaders;
        std::map<std::string, unsigned int> m_uniformMap;

        void addVertexShader(const std::string& text);
        void addGeometryShader(const std::string& text);
        void addFragmentShader(const std::string& text);
        void create(const std::string& shaderText, GLenum shaderType);
        std::string load(const std::string& file_name);
        void checkError(GLuint shader,GLuint flag, bool isProgram, const std::string& error_message);

};

#endif // SHADER_H
