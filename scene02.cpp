#include "scene02.h"

#include "scenegraph/meshrenderer.h"
#include "scenegraph/physicsenginecomponent.h"
#include "scenegraph/physicsobjectcomponent.h"

void Scene02::init()
{

    PhysicsEngine physicsEngine;
    PhysicsObject physicsObject1(glm::vec3(-3.0, -0.09, -5.0), glm::vec3(0.0f, 0.0f, 0.0f));
    PhysicsObject physicsObject2(glm::vec3(-5.0, -0.09, -5.0), glm::vec3(0.0f, 0.0f, 0.0f));
    PhysicsObject physicsObject3(glm::vec3(-7.0, -0.09, -5.0), glm::vec3(0.0f, 0.0f, 0.0f));
    physicsEngine.addObject(physicsObject1);
    physicsEngine.addObject(physicsObject2);
    physicsEngine.addObject(physicsObject3);

    PhysicsEngineComponent* physicsEngineComponent = new PhysicsEngineComponent(physicsEngine);
    Node* physicsEngineNode = new Node;
    physicsEngineNode->addComponent(physicsEngineComponent);
    addToScene(physicsEngineNode);

    IndexedMesh floorIndexedMesh("models/plane.obj");
    floorIndexedMesh.m_texCoords.push_back( glm::vec2(1.0, 1.0) );
    floorIndexedMesh.m_texCoords.push_back( glm::vec2(1.0, 0.0) );
    floorIndexedMesh.m_texCoords.push_back( glm::vec2(0.0, 0.0) );
    floorIndexedMesh.m_texCoords.push_back( glm::vec2(0.0, 1.0) );
    Mesh floorMesh;
    floorMesh.init(floorIndexedMesh);
    Material* floor = new Material( new Texture("textures/snow.jpg") , glm::vec3(1.0, 1.0, 1.0));

    Node* floorNode = new Node(glm::vec3(0.0, -0.10, 0.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(50.0f, 1.0f, 10.0f));
    floorNode->addComponent(new MeshRenderer(floorMesh, *floor));
    addToScene(floorNode);

    Mesh* cubeMesh = new Mesh;
    cubeMesh->initCube();
    Material* building = new Material( new Texture("textures/building1.jpg") , glm::vec3(1.0, 1.0, 1.0));

    Node* cubeNode1 = new Node(glm::vec3(0.0, 0.9, -5.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    cubeNode1->addComponent(new MeshRenderer(*cubeMesh, *building));
    addToScene(cubeNode1);

    Node* cubeNode2 = new Node(glm::vec3(20.0, 0.9, -5.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    cubeNode2->addComponent(new MeshRenderer(*cubeMesh, *building));
    addToScene(cubeNode2);

    Mesh* triMesh = new Mesh;
    triMesh->initTriangle();

    Material* yellowPaper = new Material( new Texture("textures/paper.jpg") , glm::vec3(1.0, 1.0, 0.0));
    Node* birdNode1 = new Node(glm::vec3(-3.0, -0.09, -5.0), glm::vec3(-90.0f, 0.0f, 0.0f), glm::vec3(0.25f, 0.25f, 0.25f));
    birdNode1->addComponent(new MeshRenderer(*triMesh, *yellowPaper));
    birdNode1->addComponent(new PhysicsObjectComponent(&physicsEngineComponent->getPhysicsEngine().getObject(0)));
    addToScene(birdNode1);

    Material* orangePaper = new Material( new Texture("textures/paper.jpg") , glm::vec3(1.0, 0.5, 0.0));
    Node* birdNode2 = new Node(glm::vec3(-5.0, -0.09, -5.0), glm::vec3(-90.0f, 0.0f, 0.0f), glm::vec3(0.25f, 0.25f, 0.25f));
    birdNode2->addComponent(new MeshRenderer(*triMesh, *orangePaper));
    birdNode2->addComponent(new PhysicsObjectComponent(&physicsEngineComponent->getPhysicsEngine().getObject(1)));
    addToScene(birdNode2);

    Material* redPaper = new Material( new Texture("textures/paper.jpg") , glm::vec3(1.0, 0.0, 0.0));
    Node* birdNode3 = new Node(glm::vec3(-7.0, -0.09, -5.0), glm::vec3(-90.0f, 0.0f, 0.0f), glm::vec3(0.25f, 0.25f, 0.25f));
    birdNode3->addComponent(new MeshRenderer(*triMesh, *redPaper));
    birdNode3->addComponent(new PhysicsObjectComponent(&physicsEngineComponent->getPhysicsEngine().getObject(2)));
    addToScene(birdNode3);
}

void Scene02::update(float delta)
{
    this->getRootNode().update(delta);
}
