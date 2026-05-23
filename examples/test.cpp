#include <iostream>
#include <raylib.h>
#include <memory>
#include "../include/scene.h"

class Game : public SCENE {
    private:
        int score;
        Rectangle player;
    public:
        Game(SCENE_MANAGER *m,int a) : SCENE(m), score(a) {
            std::cout<<"Game \n"<< score << std::endl;
            player = {100, 100, 200, 50};
        }

        void draw() override {
            DrawRectangle(player.x, player.y, player.width, player.height, BLUE);
            DrawText("Game Scene", 110, 110, 20, WHITE);
        }

        void update() override{
            if(IsKeyDown(KEY_RIGHT)) player.x += 2;
            if(IsKeyDown(KEY_LEFT)) player.x -= 2; 
        }
};

class Menu : public SCENE {
    private:
        int level;
    public:
        Menu(SCENE_MANAGER *m,int a) : SCENE(m), level(a) {
            std::cout<<"Menu \n"<< level << std::endl;
        }

        void draw() override {
            DrawRectangle(100, 100, 200, 50, RED);
            DrawText("Menu Scene", 110, 110, 20, WHITE);
        }

        void update() override{
            if(IsKeyPressed(KEY_ENTER)){
                manager->set_scene(std::make_unique<Game>(manager, 42));
            }
        }
};

int main()
{   
    SCENE_MANAGER manager;
    manager.set_scene(std::make_unique<Menu>(&manager, 19));

    InitWindow(800, 600, "Scene Manager Example");
    SetTargetFPS(60);
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        manager.draw();
        manager.update();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

/*
g++ examples/main.cpp src/*.cpp -o sim $(pkg-config --cflags --libs raylib)
*/