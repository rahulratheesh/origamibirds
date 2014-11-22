#include "mesh.h"
#include <iostream>
#include <fstream>
#include <sstream>

IndexedMesh::IndexedMesh(const std::string& fileName)
{
    std::ifstream reader(fileName.c_str(), std::ios::in);
    if (!reader)
    {
        std::cerr << "Cannot open " << fileName << std::endl;
        exit(1);
    }

    std::string line;
    while (getline(reader, line)) {
        if (line.length() == 0 || line.substr(0, 1) == "#")
            continue;
        else if (line.substr(0,2) == "v ")
        {
            std::istringstream s(line.substr(2));
            glm::vec3 posCoord;
            s >> posCoord.x;
            s >> posCoord.y;
            s >> posCoord.z;
            m_posCoords.push_back(posCoord);
        }
        else if (line.substr(0,2) == "f ")
        {
            std::istringstream s(line.substr(2));
            unsigned int a,b,c;
            s >> a;
            s >> b;
            s >> c;
            a--;
            b--;
            c--;
            m_indices.push_back(a);
            m_indices.push_back(b);
            m_indices.push_back(c);
        }
    }

    m_numVertices = m_posCoords.size();
    m_numIndices = m_indices.size();
}

void Mesh::init(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices)
{
    IndexedMesh indexedMesh;
    for (unsigned int i = 0; i < numVertices; i++)
    {
        indexedMesh.m_posCoords.push_back( vertices[i].getPosCoord() );

        indexedMesh.m_texCoords.push_back( vertices[i].getTexCoord() );
    }
    for (unsigned int i = 0; i < numIndices; i++)
    {
        indexedMesh.m_indices.push_back( indices[i] );
    }
    indexedMesh.m_numVertices = numVertices;
    indexedMesh.m_numIndices = numIndices;


    init(indexedMesh);
}

void Mesh::init(const IndexedMesh& indexedMesh)
{
    m_size = indexedMesh.m_numIndices;
    // generate vao
    glGenVertexArrays(1, &m_vertex_array_object);
    glBindVertexArray(m_vertex_array_object);
    // generate vbo
    glGenBuffers(NUM_BUFFERS, m_vertex_buffer_objects);
    // position buffer
    glBindBuffer(GL_ARRAY_BUFFER, m_vertex_buffer_objects[POSCOORD_VB]);
    glBufferData(GL_ARRAY_BUFFER, indexedMesh.m_numVertices  * sizeof(indexedMesh.m_posCoords[0]), &indexedMesh.m_posCoords[0], GL_STATIC_DRAW);
    // texture buffer
    glBindBuffer(GL_ARRAY_BUFFER, m_vertex_buffer_objects[TEXCOORD_VB]);
    glBufferData(GL_ARRAY_BUFFER, indexedMesh.m_numVertices  * sizeof(indexedMesh.m_texCoords[0]), &indexedMesh.m_texCoords[0], GL_STATIC_DRAW);
    // generate ibo
    glGenBuffers(1, &m_index_buffer_object);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_index_buffer_object);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexedMesh.m_numIndices * sizeof(indexedMesh.m_indices[0]), &indexedMesh.m_indices[0], GL_STATIC_DRAW);

}

void Mesh::draw()
{

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, m_vertex_buffer_objects[POSCOORD_VB]);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertex_buffer_objects[TEXCOORD_VB]);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_index_buffer_object);
    // tell OpenGL how to render the buffer
    glDrawElements(GL_TRIANGLES, m_size, GL_UNSIGNED_INT, 0);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &m_vertex_array_object);
}