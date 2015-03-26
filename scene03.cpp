#include "scene03.h"

#include "scenegraph/meshrenderer.h"
#include "scenegraph/physicsenginecomponent.h"
#include "scenegraph/physicsobjectcomponent.h"
#include "scenegraph/cameracomponent.h"
#include "physics/boundingsphere.h"

void Scene03::init(const Window& window)
{
    Camera camera(60.0f, window.getAspectRatio(), 0.1f, 100.0f);
    CameraComponent* cameraComponent = new CameraComponent(camera);

    PhysicsEngine physicsEngine;
    PhysicsObject physicsObject1(new BoundingSphere(glm::vec3(-1.0, 1.0, -5.0), 0.2f), glm::vec3(0.1f, -0.5f, 0.0f), true);
//    PhysicsObject physicsObject2(new BoundingSphere(glm::vec3(-2.0, 0.5, -5.0), 0.2f), glm::vec3(0.1f, -0.1f, 0.0f), true);
//    PhysicsObject physicsObject3(new BoundingSphere(glm::vec3(-3.0, 0.5, -5.0), 0.2f), glm::vec3(0.1f, 0.1f, 0.0f), true);
//    PhysicsObject physicsObject4(new BoundingSphere(glm::vec3(-4.0, 0.5, -5.0), 0.2f), glm::vec3(0.1f, 0.1f, 0.0f), true);
//    PhysicsObject physicsObject5(new BoundingSphere(glm::vec3(-5.0, 0.5, -5.0), 0.2f), glm::vec3(0.1f, 0.1f, 0.0f), true);

    physicsEngine.addObject(physicsObject1);
//    physicsEngine.addObject(physicsObject2);
//    physicsEngine.addObject(physicsObject3);
//    physicsEngine.addObject(physicsObject4);
//    physicsEngine.addObject(physicsObject5);

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

    Node* floorNode = new Node(glm::vec3(0.0, -1.0, 0.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(50.0f, 1.0f, 10.0f));
    floorNode->addComponent(new MeshRenderer(floorMesh, *floor));
    addToScene(floorNode);

    Mesh* cubeMesh = new Mesh;
    cubeMesh->initCube();
    Material* building = new Material( new Texture("textures/igloo.jpg") , glm::vec3(1.0, 1.0, 1.0));

    Node* cubeNode1_down = new Node(glm::vec3(3.0, 0.0, -5.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    cubeNode1_down->addComponent(new MeshRenderer(*cubeMesh, *building));
    addToScene(cubeNode1_down);

    Node* cubeNode1_up = new Node(glm::vec3(3.0, 4.0, -5.0), glm::vec3(0.0f, 0.0f, 180.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    cubeNode1_up->addComponent(new MeshRenderer(*cubeMesh, *building));
    addToScene(cubeNode1_up);

    Node* cubeNode2_down = new Node(glm::vec3(10.0, 0.0, -5.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    cubeNode2_down->addComponent(new MeshRenderer(*cubeMesh, *building));
    addToScene(cubeNode2_down);

    Node* cubeNode2_up = new Node(glm::vec3(13.0, 4.0, -5.0), glm::vec3(0.0f, 0.0f, 180.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    cubeNode2_up->addComponent(new MeshRenderer(*cubeMesh, *building));
    addToScene(cubeNode2_up);

    Node* cubeNode3_down = new Node(glm::vec3(16.0, 0.0, -5.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    cubeNode3_down->addComponent(new MeshRenderer(*cubeMesh, *building));
    addToScene(cubeNode3_down);

    Node* cubeNode3_up = new Node(glm::vec3(23.0, 4.0, -5.0), glm::vec3(0.0f, 0.0f, 180.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    cubeNode3_up->addComponent(new MeshRenderer(*cubeMesh, *building));
    addToScene(cubeNode3_up);


    IndexedMesh paperPlaneIndexedMesh("models/paperbird.obj");
    Mesh paperPlaneMesh;
    paperPlaneMesh.init(paperPlaneIndexedMesh);

    Material* yellowPaper = new Material( new Texture("textures/paper.jpg") , glm::vec3(0.94, 0.89, 0.0));
    Node* birdNode1 = new Node(glm::vec3(-1.0, 0.5, -5.0), glm::vec3(0.0f, 90.0f, 0.0f), glm::vec3(0.6f, 0.60f, 0.60f));
    birdNode1->addComponent(new MeshRenderer(paperPlaneMesh, *yellowPaper));
    birdNode1->addComponent(new PhysicsObjectComponent(&physicsEngineComponent->getPhysicsEngine().getObject(0)));
    birdNode1->addComponent(cameraComponent);
    addToScene(birdNode1);

//    Material* orangePaper = new Material( new Texture("textures/paper.jpg") , glm::vec3(0.93, 0.67, 0.09));
//    Node* birdNode2 = new Node(glm::vec3(-2.0, 0.5, -5.0), glm::vec3(0.0f, 90.0f, 0.0f), glm::vec3(0.5f, 0.5f, 0.5f));
//    birdNode2->addComponent(new MeshRenderer(paperPlaneMesh, *orangePaper));
//    birdNode2->addComponent(new PhysicsObjectComponent(&physicsEngineComponent->getPhysicsEngine().getObject(1)));
//    addToScene(birdNode2);

//    Material* redPaper = new Material( new Texture("textures/paper.jpg") , glm::vec3(0.9, 0.28, 0.28));
//    Node* birdNode3 = new Node(glm::vec3(-3.0, 0.5, -5.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.5f, 0.5f, 0.5f));
//    birdNode3->addComponent(new MeshRenderer(paperPlaneMesh, *redPaper));
//    birdNode3->addComponent(new PhysicsObjectComponent(&physicsEngineComponent->getPhysicsEngine().getObject(2)));
//    addToScene(birdNode3);
//
//    Material* greenPaper = new Material( new Texture("textures/paper.jpg") , glm::vec3(0.43, 0.79, 0.43));
//    Node* birdNode4 = new Node(glm::vec3(-4.0, 0.5, -5.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.5f, 0.5f, 0.5f));
//    birdNode4->addComponent(new MeshRenderer(paperPlaneMesh, *greenPaper));
//    birdNode4->addComponent(new PhysicsObjectComponent(&physicsEngineComponent->getPhysicsEngine().getObject(3)));
//    addToScene(birdNode4);
//
//    Material* bluePaper = new Material( new Texture("textures/paper.jpg") , glm::vec3(0.27, 0.51, 0.78));
//    Node* birdNode5 = new Node(glm::vec3(-5.0, 0.5, -5.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.5f, 0.5f, 0.5f));
//    birdNode5->addComponent(new MeshRenderer(paperPlaneMesh, *bluePaper));
//    birdNode5->addComponent(new PhysicsObjectComponent(&physicsEngineComponent->getPhysicsEngine().getObject(4)));
//    addToScene(birdNode5);

}

void Scene03::update(float delta)
{
    this->getRootNode().update(delta);
}
