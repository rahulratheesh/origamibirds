#include "scene01.h"
#include "core/meshrenderer.h"

void Scene01::init()
{
    IndexedMesh indexedMesh("models/plane.obj");
    indexedMesh.m_texCoords.push_back( glm::vec2(1.0, 1.0) );
    indexedMesh.m_texCoords.push_back( glm::vec2(1.0, 0.0) );
    indexedMesh.m_texCoords.push_back( glm::vec2(0.0, 0.0) );
    indexedMesh.m_texCoords.push_back( glm::vec2(0.0, 1.0) );

    Mesh mesh;
    mesh.init(indexedMesh);
    Texture* texture = new Texture("textures/grass.jpg");
    Node* plane = new Node(glm::vec3(0.0, -1.0, -5.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));

    addToScene(plane);
    plane->addComponent(new MeshRenderer(mesh, *texture));

}



