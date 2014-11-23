#include "scene.h"
#include "core/meshrenderer.h"

void Scene::init()
{
    IndexedMesh indexedMesh("models/plane.obj");
    indexedMesh.m_texCoords.push_back( glm::vec2(1.0, 1.0) );
    indexedMesh.m_texCoords.push_back( glm::vec2(1.0, 0.0) );
    indexedMesh.m_texCoords.push_back( glm::vec2(0.0, 0.0) );
    indexedMesh.m_texCoords.push_back( glm::vec2(0.0, 1.0) );

    m_mesh = new Mesh();
    m_mesh->init(indexedMesh);

//    Mesh mesh;
//    mesh.init(indexedMesh);

    m_shader = new Shader();
    m_shader->addUniform("u_transform");

    m_texture = new Texture("textures/grass.jpg");
    //Texture texture("textures/grass.jpg");

    //MeshRenderer* meshRenderer = new MeshRenderer(mesh, texture);
    //m_root.addComponent(meshRenderer);


    m_transform = new Transform();

    m_camera = new  Camera(glm::vec3(0.0, 0.0, 0.0), 70.0, 800.0/600.0, 0.1f, 100.0f);

}

void Scene::processInput(const Input& input)
{
    m_camera->input(input);
    m_root.input();
}

void Scene::update()
{
    m_transform->setTranslateVector(0.0, -1.0, -5.0);
    m_root.update();
}

void Scene::render()
{
    m_shader->bind();
    //m_texture->bind(0);
    glm::mat4 mvp = m_camera->getViewProjection() * m_transform->getModel();
    m_shader->setUniformMatrix4f("u_transform", mvp);
    m_mesh->draw();

//    Shader shader;
//    shader.addUniform("u_transform");
//    Camera camera(glm::vec3(0.0, 0.0, 0.0), 70.0, 800.0/600.0, 0.1f, 100.0f);
//    m_root.render(shader, camera);
}

Scene::~Scene()
{
    //dtor
}
