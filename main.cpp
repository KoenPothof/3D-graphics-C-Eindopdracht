#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include "FpsCam.h"
#include "tigl.h"
#include "ObjModel.h"
#include "Texture.h"
#include "GameManager.h"
#include "DrawComponent.h"
#include "TextComponent.h"
#include "RectangleComponent.h"
#include "ModelComponent.h"
#include "MovingObjectComponent.h"
#include "GameObject.h"
using tigl::Vertex;

#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")

Texture* texture;
Texture* textureWall;
Texture* textureFloor;
Texture* textureCeiling;


std::shared_ptr<GameManager> gameManager;
std::shared_ptr<GameObject> car;


GLFWwindow* window;
FpsCam* camera;

int frontWallsWidth, sideWallsWidth = 10;

int height = 5;
int x = 0;
int y = -2;
int z = 0;
float deltaTime = 0.0f; 
bool runningPaused = false;

void init();
void update();
void draw();
void initObjects();
void drawRoom();
void initLight();

int main(void)
{
    
    if (!glfwInit())
        throw "Could not initialize glwf";
    window = glfwCreateWindow(1400, 800, "Eindopdracht-3DC", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        throw "Could not initialize glwf";
    }
    glfwMakeContextCurrent(window);

    tigl::init();

    init();

	while (!glfwWindowShouldClose(window))
	{
		update();
		draw();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();


    return 0;
}

std::list<std::shared_ptr<GameObject>> gameObjects;

void init()
{
    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (key == GLFW_KEY_ESCAPE) {
            glfwSetWindowShouldClose(window, true);
        }
        
        if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
        {
            car->getComponent<MovingObjectComponent>()->movementToggle();
        }
           
    });

    camera = new FpsCam(window);
    textureFloor = new Texture("assets/floorTexture.png", 128, 128, NULL);
    textureWall = new Texture("assets/wallTexture.png", 128, 128, NULL);
    textureCeiling = new Texture("assets/ceilingTexture.png", 128, 128, NULL);

    initObjects();
    initLight();
    
}


void update()
{
    camera->update(window);
    double currentTime = glfwGetTime();
    static double lastTime = currentTime;
    deltaTime = float(currentTime - lastTime);
    lastTime = currentTime;
    gameManager->update(deltaTime);

    glEnable(GL_DEPTH_TEST);

    for (auto& go : gameObjects)
		go->update(deltaTime);
  
}

void draw()
{
    glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    glm::mat4 projection = glm::perspective(glm::radians(75.0f), viewport[2] / (float)viewport[3], 0.01f, 500.0f);

    tigl::shader->setProjectionMatrix(projection);
    tigl::shader->setViewMatrix(camera->getMatrix());
    tigl::shader->setModelMatrix(glm::mat4(1.0f));

    tigl::shader->enableColor(true);
    tigl::shader->enableTexture(true);

    glEnable(GL_DEPTH_TEST);

    drawRoom();

    glPointSize(10.0f);

    for (auto& go : gameObjects)
        go->draw();
}

void initObjects() {
    auto tafel = std::make_shared<GameObject>();
    tafel->position = glm::vec3(3, y, -15);
    tafel->addComponent(std::make_shared<ModelComponent>("assets/models/pikniekTafel/picnicTafel.obj"));
    tafel->scale = glm::vec3(1.5, 1.5, 1.5);
    gameObjects.push_back(tafel);

    car = std::make_shared<GameObject>();
    car->addComponent(std::make_shared<ModelComponent>("assets/models/car/honda_jazz.obj"));
    car->addComponent(std::make_shared<MovingObjectComponent>());
    car->getComponent<MovingObjectComponent>()->init();
    car->scale = glm::vec3(0.01f, 0.01f, 0.01f);
    gameObjects.push_back(car);
}

void drawRoom() {
    auto wall1 = std::make_shared<GameObject>();
    wall1->addComponent(std::make_shared<RectangleComponent>(0, 0, 0, 1, false, 20, height, textureWall));
    wall1->position = glm::vec3(x, y, z);
    wall1->rotation = glm::vec3(0, 0, 0);
    gameObjects.push_back(wall1);

    auto wall2 = std::make_shared<GameObject>();
    wall2->addComponent(std::make_shared<RectangleComponent>(0, 0, 0, 1, false, 20, height, textureWall));
    wall2->position = glm::vec3(20, y, 0);
    wall2->rotation = glm::vec3(0, 0, 0);
    gameObjects.push_back(wall2);

    auto wall3 = std::make_shared<GameObject>();
    wall3->addComponent(std::make_shared<RectangleComponent>(0, 0, 0, 0, false, 20, height, textureWall));
    wall3->position = glm::vec3(x, y, 0);
    wall3->rotation = glm::vec3(0, 0, 0);
    gameObjects.push_back(wall3);

    auto wall4 = std::make_shared<GameObject>();
    wall4->addComponent(std::make_shared<RectangleComponent>(0, 0, 0, 0, false, 20, height, textureWall));
    wall4->position = glm::vec3(x, y, -20);
    wall4->rotation = glm::vec3(0, 0, 0);
    gameObjects.push_back(wall4);

    auto floor1 = std::make_shared<GameObject>();
    floor1->addComponent(std::make_shared<RectangleComponent>(0, 0, 0, 1, true, -20, -20, textureFloor));
    floor1->position = glm::vec3(x, y, z);
    gameObjects.push_back(floor1);

    auto ceiling1 = std::make_shared<GameObject>();
    ceiling1->addComponent(std::make_shared<RectangleComponent>(0, height, 0, 1, true, -20, -20, textureCeiling));
    ceiling1->position = glm::vec3(x, y, z);
    gameObjects.push_back(ceiling1);
}

void initLight() {
    tigl::shader->enableLighting(true);
    tigl::shader->setLightCount(1);
    tigl::shader->setLightDirectional(0, false);
    tigl::shader->setLightPosition(0, glm::vec3(10, 7.5, -10));
    tigl::shader->setLightAmbient(0, glm::vec3(0.5f, 0.5f, 0.5f));
    tigl::shader->setLightDiffuse(0, glm::vec3(1.0f, 1.0f, 1.0f));
    tigl::shader->setLightSpecular(0, glm::vec3(0, 0, 0));
}