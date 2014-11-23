#include "shader.h"
#include <iostream>
#include <fstream>

Shader::Shader(const std::string& file_name) {

    m_program = glCreateProgram();
	if (m_program == 0)
	{
        std::cerr << "Error creating shader program" << std::endl;
        exit(1);
    }

    std::string vertexShaderText = load("shaders/" + file_name + ".vs.glsl");
    std::string fragmentShaderText = load("shaders/" + file_name + ".fs.glsl");

    addVertexShader(vertexShaderText);
	addFragmentShader(fragmentShaderText);

    glBindAttribLocation(m_program, 0, "a_posCoord");
    glBindAttribLocation(m_program, 1, "a_texCoord");

    glLinkProgram(m_program);
    checkError(m_program, GL_LINK_STATUS, true, "Program Linking failed");

    glValidateProgram(m_program);
    checkError(m_program, GL_VALIDATE_STATUS, true, "Program Validation failed");

}

void Shader::addUniform(std::string uniformName)
{
    GLint location = glGetUniformLocation(m_program, uniformName.c_str());
    if (location == -1)
    {
        std::cerr << "Error: Could not find uniform " << uniformName << std::endl;
        exit(1);
    }
    m_uniformMap.insert(std::pair<std::string, unsigned int>(uniformName, location));
}

void Shader::setUniformi(const std::string& uniformName, int value) const
{
	glUniform1i(m_uniformMap.at(uniformName), value);
}

void Shader::setUniformf(const std::string& uniformName, float value) const
{
	glUniform1f(m_uniformMap.at(uniformName), value);
}

void Shader::setUniformVector3f(const std::string& uniformName, const glm::vec3& value) const
{
	glUniform3f(m_uniformMap.at(uniformName), value.x, value.y, value.z);
}

void Shader::setUniformMatrix4f(const std::string& uniformName, const glm::mat4& value) const
{
	glUniformMatrix4fv(m_uniformMap.at(uniformName), 1, GL_FALSE, &value[0][0]);
}

void Shader::addVertexShader(const std::string& text)
{
    create(text, GL_VERTEX_SHADER);
}

void Shader::addGeometryShader(const std::string& text)
{
    create(text, GL_GEOMETRY_SHADER);
}

void Shader::addFragmentShader(const std::string& text)
{
    create(text, GL_FRAGMENT_SHADER);
}

void Shader::create(const std::string& shaderText, GLenum shaderType) {
    GLuint shader = glCreateShader(shaderType);
    if (shader == 0)
        std::cerr << "Shader Creation failed" << std::endl;

    const GLchar* shaderSourceText[1];
    GLint shaderSourceTextLength[1];
    shaderSourceText[0] = shaderText.c_str();
    shaderSourceTextLength[0] = shaderText.length();
    glShaderSource(shader, 1, shaderSourceText, shaderSourceTextLength);
    glCompileShader(shader);
    checkError(shader, GL_COMPILE_STATUS, false, "Shader Compilation failed");

	glAttachShader(m_program, shader);
	m_shaders.push_back(shader);
}

void Shader::bind() const {
    glUseProgram(m_program);
}

Shader::~Shader() {
    for (unsigned int i = 0; i < m_shaders.size(); i++) {
        glDetachShader(m_program, m_shaders.at(i));
        glDeleteShader(m_shaders.at(i));
    }
    glDeleteProgram(m_program);
}


std::string Shader::load(const std::string& file_name) {
    std::ifstream file;
    std::string output;
    std::string line;
    file.open(file_name.c_str());
    if (file.fail()) {
        std::cerr << "Unable to load shader: " << file_name << std::endl;
    }
    while(true) {
        getline(file, line);
        if (file.fail()) break;
        output.append(line + "\n");
    }
    return output;
}

void Shader::checkError(GLuint shader,GLuint flag, bool isProgram, const std::string& error_message) {
    GLint success = GL_FALSE;
    GLchar error[1024] = {0};
    if (isProgram)
        glGetProgramiv(shader, flag, &success);
    else
        glGetShaderiv(shader, flag, &success);
    if (success == GL_FALSE) {
        if (isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);

        std::cerr << error_message << ": " << error << std::endl;
    }
}


