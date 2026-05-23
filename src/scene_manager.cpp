#include "../include/scene_manager.h"
#include "../include/scene.h"


void SCENE_MANAGER::set_scene(std::unique_ptr<SCENE> newScene){
    current_scene = std::move(newScene);
}

void SCENE_MANAGER::draw(){
    if(current_scene) {
        current_scene->draw();
    }
}

void SCENE_MANAGER::update(){
    if(current_scene) {
        current_scene->update();
    }
}