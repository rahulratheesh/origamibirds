#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <iostream>
#include <vector>

class Vertex
{
    public:
        Vertex(const glm::vec3 posCoord, const glm::vec2 texCoord)
        {
            m_posCoord = posCoord;
            m_texCoord = texCoord;
        }

        inline glm::vec3 getPosCoord() { return m_posCoord; }
        inline glm::vec2 getTexCoord() { return m_texCoord; }

    protected:

    private:
        glm::vec3 m_posCoord;
        glm::vec2 m_texCoord;
};

class IndexedMesh
{
    public:
        IndexedMesh() {}
        IndexedMesh(const std::string& fileName);
        void calcNormals();

        std::vector<glm::vec3> m_posCoords;
        std::vector<glm::vec2> m_texCoords;
        std::vector<glm::vec3> m_norCoords;
        std::vector<unsigned int> m_indices;
        unsigned int m_numVertices;
        unsigned int m_numIndices;
};

class Mesh
{
    public:
        Mesh() {}
        void init(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices);
        void init(const IndexedMesh &indexedMesh);

        void initTriangle();
        void initSquare();
        void initCube();
        void draw();

        virtual ~Mesh();
    protected:

    private:

       enum {POSCOORD_VB, TEXCOORD_VB, NORCOORD_VB, NUM_BUFFERS};
        GLuint m_vertex_array_object;
        GLuint m_vertex_buffer_objects[NUM_BUFFERS];
        GLuint m_index_buffer_object;
        unsigned int m_size;


};

#endif // MESH_H
