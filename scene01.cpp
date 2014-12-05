#include "scene01.h"
#include "scenegraph/meshrenderer.h"
#include "scenegraph/physicsenginecomponent.h"
#include "scenegraph/physicsobjectcomponent.h"
#include "core/timer.h"

Node* cubeNode2;

void Scene01::init(const Window& window)
{
    PhysicsEngine physicsEngine;

    PhysicsObject physicsObject1(glm::vec3(5.0, 0.0, 0.0), glm::vec3(-0.05f, 0.05f, 0.0f));
    PhysicsObject physicsObject2(glm::vec3(-5.0, 0.0, 0.0), glm::vec3(0.05f, 0.05f, 0.0f));

    physicsEngine.addObject(physicsObject1);
    physicsEngine.addObject(physicsObject2);

    PhysicsEngineComponent* physicsEngineComponent = new PhysicsEngineComponent(physicsEngine);

    Node* physicsEngineNode = new Node;
    physicsEngineNode->addComponent(physicsEngineComponent);
    addToScene(physicsEngineNode);

    IndexedMesh cubeIndexedMesh("models/cube.obj");
    Mesh cubeMesh;
    cubeMesh.init(cubeIndexedMesh);
    Material* paper1 = new Material( new Texture("textures/paper.jpg") , glm::vec3(0.7, 0.2, 0.2));

    Node* cubeNode1 = new Node(glm::vec3(0.0, 0.0, -5.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    cubeNode1->addComponent(new MeshRenderer(cubeMesh, *paper1));
    addToScene(cubeNode1);

    Material* paper2 = new Material( new Texture("textures/paper.jpg") , glm::vec3(0.35, 0.6, 0.9));
    cubeNode2 = new Node(glm::vec3(5.0, 0.0, -5.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    cubeNode2->addComponent(new MeshRenderer(cubeMesh, *paper2));
    cubeNode2->addComponent(new PhysicsObjectComponent(&physicsEngineComponent->getPhysicsEngine().getObject(0)));
    addToScene(cubeNode2);

    Material* paper3 = new Material( new Texture("textures/paper.jpg") , glm::vec3(0.9, 0.5, 0.1));
    Node* cubeNode3 = new Node(glm::vec3(-5.0, 0.0, -5.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    cubeNode3->addComponent(new MeshRenderer(cubeMesh, *paper3));
    cubeNode3->addComponent(new PhysicsObjectComponent(&physicsEngineComponent->getPhysicsEngine().getObject(1)));
    addToScene(cubeNode3);

    IndexedMesh floorIndexedMesh("models/plane.obj");
    floorIndexedMesh.m_texCoords.push_back( glm::vec2(1.0, 1.0) );
    floorIndexedMesh.m_texCoords.push_back( glm::vec2(1.0, 0.0) );
    floorIndexedMesh.m_texCoords.push_back( glm::vec2(0.0, 0.0) );
    floorIndexedMesh.m_texCoords.push_back( glm::vec2(0.0, 1.0) );
    Mesh floorMesh;
    floorMesh.init(floorIndexedMesh);
    Material* grass = new Material( new Texture("textures/grass.jpg") , glm::vec3(0.1, 0.6, 0.2));

    Node* floorNode = new Node(glm::vec3(0.0, -1.0, 0.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    floorNode->addComponent(new MeshRenderer(floorMesh, *grass));
    addToScene(floorNode);
}

void Scene01::update(float delta)
{
    float rotate = Timer::getElapsedTimeInSeconds() * 180;
    cubeNode2->getTransform()->setRotate(glm::vec3(0.0, rotate, 0.0));
    this->getRootNode().update(delta);
}



