#include "scene.h"

Scene::Scene()
{
//    Vertex vertices[] = { Vertex( glm::vec3(+0.5, +0.5, 0.0), glm::vec2(1.0, 1.0) ),
//                          Vertex( glm::vec3(-0.5, +0.5, 0.0), glm::vec2(0.0, 1.0) ),
//                          Vertex( glm::vec3(-0.5, -0.5, 0.0), glm::vec2(0.0, 0.0) ),
//                          Vertex( glm::vec3(+0.5, -0.5, 0.0), glm::vec2(1.0, 0.0) )
//                         };
//    unsigned int indices[] = {0, 3, 2,
//                                2, 1, 0};

    IndexedMesh indexedMesh("models/plane.obj");
    indexedMesh.m_texCoords.push_back( glm::vec2(1.0, 1.0) );
    indexedMesh.m_texCoords.push_back( glm::vec2(1.0, 0.0) );
    indexedMesh.m_texCoords.push_back( glm::vec2(0.0, 0.0) );
    indexedMesh.m_texCoords.push_back( glm::vec2(0.0, 1.0) );
    m_mesh = new Mesh();
    //m_mesh->init(vertices, sizeof(vertices)/sizeof(vertices[0]), indices, sizeof(indices)/sizeof(indices[0]));
    m_mesh->init(indexedMesh);

    m_shader = new Shader();
    m_shader->addUniform("u_transform");

    m_texture = new Texture("textures/grass.jpg");

    m_transform = new Transform();

    m_camera = new  Camera(glm::vec3(0.0, 0.0, 0.0), 70.0, 800.0/600.0, 0.1f, 100.0f);
}

void Scene::processInput(const Input& input)
{
    //std::cout << "Mouse moved " << std::endl;
    //float rotatef = sinf(Timer::getElapsedTimeInMilliSeconds() / 1000.0 *2*3.14 / 5);
    //glm::vec3 rotate = glm::mat3(glm::rotate(rotatef, m_camera.getUp())) * m_camera.getDirection();
    //m_camera.setDirection(rotate);

//    glm::vec2 mouseDelta = newMousePosition - oldMousePosition;
//    glm::vec3 newDirection = glm::mat3(glm::rotate(mouseDelta.x * 0.1f, m_camera.getUp())) * m_camera.getDirection();
//    m_camera.setDirection(newDirection);

    //std::cout << input.getMousePosition().x << std::endl;
    m_camera->input(input);

}

void Scene::update()
{
    //float move = sinf(Timer::getElapsedTimeInMilliSeconds() / 1000.0 * (2*3.14) / 5); // -1<->+1 every 5 seconds
    m_transform->setTranslateVector(0.0, -1.0, -5.0);
    //float rotate = Timer::getElapsedTimeInMilliSeconds() / 1000.0 * 180;
    //m_transform->setRotateVector(glm::vec3(0.0, rotate, 0.0));
    //m_transform.setScaleVector(glm::vec3(move, move, move));

}

void Scene::render()
{
    m_shader->bind();
    //m_texture->bind(0);
    glm::mat4 mvp = m_camera->getViewProjection() * m_transform->getModel();
    m_shader->setUniformMatrix4f("u_transform", mvp);
    m_mesh->draw();
}

Scene::~Scene()
{
    //dtor
}
