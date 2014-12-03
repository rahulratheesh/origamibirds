#include "scene02.h"

#include "scenegraph/meshrenderer.h"
#include "scenegraph/physicsenginecomponent.h"
#include "scenegraph/physicsobjectcomponent.h"

void Scene02::init()
{
    IndexedMesh floorIndexedMesh("models/plane.obj");
    floorIndexedMesh.m_texCoords.push_back( glm::vec2(1.0, 1.0) );
    floorIndexedMesh.m_texCoords.push_back( glm::vec2(1.0, 0.0) );
    floorIndexedMesh.m_texCoords.push_back( glm::vec2(0.0, 0.0) );
    floorIndexedMesh.m_texCoords.push_back( glm::vec2(0.0, 1.0) );
    Mesh floorMesh;
    floorMesh.init(floorIndexedMesh);
    Material* floor = new Material( new Texture("textures/grass.jpg") , glm::vec3(1.0, 1.0, 1.0));

    Node* floorNode = new Node(glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    floorNode->addComponent(new MeshRenderer(floorMesh, *floor));
    addToScene(floorNode);

    Mesh* cubeMesh = new Mesh;
    cubeMesh->initCube();
    Material* building = new Material( new Texture("textures/building1.jpg") , glm::vec3(1.0, 1.0, 1.0));

    Node* cubeNode = new Node(glm::vec3(0.0, 1.0, -5.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    cubeNode->addComponent(new MeshRenderer(*cubeMesh, *building));
    addToScene(cubeNode);


//    Mesh* triMesh = new Mesh;
//    triMesh->initTriangle();
//
//    Material* yellowPaper = new Material( new Texture("textures/paper.jpg") , glm::vec3(1.0, 1.0, 0.0));
//    Node* birdNode1 = new Node(glm::vec3(0.0, 0.2, -1.0), glm::vec3(-90.0f, 0.0f, 0.0f), glm::vec3(0.25f, 0.25f, 0.25f));
//    birdNode1->addComponent(new MeshRenderer(*triMesh, *yellowPaper));
//    addToScene(birdNode1);
//
//    Material* orangePaper = new Material( new Texture("textures/paper.jpg") , glm::vec3(1.0, 0.5, 0.0));
//    Node* birdNode2 = new Node(glm::vec3(1.0, 0.2, -1.0), glm::vec3(-90.0f, 0.0f, 0.0f), glm::vec3(0.25f, 0.25f, 0.25f));
//    birdNode2->addComponent(new MeshRenderer(*triMesh, *orangePaper));
//    addToScene(birdNode2);
//
//    Material* redPaper = new Material( new Texture("textures/paper.jpg") , glm::vec3(1.0, 0.0, 0.0));
//    Node* birdNode3 = new Node(glm::vec3(-1.0, 0.2, -1.0), glm::vec3(-90.0f, 0.0f, 0.0f), glm::vec3(0.25f, 0.25f, 0.25f));
//    birdNode3->addComponent(new MeshRenderer(*triMesh, *redPaper));
//    addToScene(birdNode3);

}

void Scene02::update(float delta)
{
}
