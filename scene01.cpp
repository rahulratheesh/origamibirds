#include "scene01.h"
#include "core/meshrenderer.h"
#include "physics/physicsenginecomponent.h"
#include "physics/physicsobjectcomponent.h"

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
    addToScene(plane1);

    PhysicsEngine physicsEngine;
    glm::vec3 pos = glm::vec3(-3.0, -1.0, -5.0);
    PhysicsObject physicsObject(pos, glm::vec3(0.0f, 0.1f, 0.0f));
    physicsEngine.addObject(physicsObject);

    PhysicsEngineComponent* physicsEngineComponent = new PhysicsEngineComponent(physicsEngine);

    Node* plane2 = new Node(pos, glm::vec3(0.0f, 45.0f, 0.0f), glm::vec3(0.25f, 0.25f, 0.25f));
    plane2->addComponent(new PhysicsObjectComponent(&physicsEngineComponent->getPhysicsEngine().getObject(0)));
    plane2->addComponent(new MeshRenderer(mesh, *texture));
    addToScene(plane2);

    Node* physicsEngineNode = new Node;
    physicsEngineNode->addComponent(physicsEngineComponent);
    addToScene(physicsEngineNode);

}



