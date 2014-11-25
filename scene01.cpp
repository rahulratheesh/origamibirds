#include "scene01.h"
#include "scenegraph/meshrenderer.h"
#include "scenegraph/physicsenginecomponent.h"
#include "scenegraph/physicsobjectcomponent.h"

void Scene01::init()
{
    IndexedMesh indexedMesh("models/plane.obj");
    indexedMesh.m_texCoords.push_back( glm::vec2(1.0, 1.0) );
    indexedMesh.m_texCoords.push_back( glm::vec2(1.0, 0.0) );
    indexedMesh.m_texCoords.push_back( glm::vec2(0.0, 0.0) );
    indexedMesh.m_texCoords.push_back( glm::vec2(0.0, 1.0) );

    Mesh mesh;
    mesh.init(indexedMesh);

    Texture* texture = new Texture("textures/crate.jpg");

    Node* plane1 = new Node(glm::vec3(0.0, -3.0, -5.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    plane1->addComponent(new MeshRenderer(mesh, *texture));
    //addToScene(plane1);

    PhysicsEngine physicsEngine;

    PhysicsObject physicsObject1(glm::vec3(-3.0, -1.0, -5.0), glm::vec3(0.0f, 0.1f, 0.0f));
    PhysicsObject physicsObject2(glm::vec3(-3.0, 5.0, -5.0), glm::vec3(0.0f, -0.1f, 0.0f));
    physicsEngine.addObject(physicsObject1);
    physicsEngine.addObject(physicsObject2);

    PhysicsEngineComponent* physicsEngineComponent = new PhysicsEngineComponent(physicsEngine);

    Node* plane2 = new Node(glm::vec3(0.0, -1.0, -5.0), glm::vec3(0.0f, 45.0f, 0.0f), glm::vec3(0.25f, 0.25f, 0.25f));
    plane2->addComponent(new PhysicsObjectComponent(&physicsEngineComponent->getPhysicsEngine().getObject(0)));
    plane2->addComponent(new MeshRenderer(mesh, *texture));
    addToScene(plane2);

    Node* plane3 = new Node(glm::vec3(0.0, 5.0, -5.0), glm::vec3(0.0f, 30.0f, 0.0f), glm::vec3(0.25f, 0.25f, 0.25f));
    plane3->addComponent(new PhysicsObjectComponent(&physicsEngineComponent->getPhysicsEngine().getObject(1)));
    plane3->addComponent(new MeshRenderer(mesh, *texture));
    addToScene(plane3);

    Node* physicsEngineNode = new Node;
    physicsEngineNode->addComponent(physicsEngineComponent);
    addToScene(physicsEngineNode);

}



