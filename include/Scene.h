#pragma once
#include "raylib.h"
#include "Platform.h"
#include "Player.h"
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
#include <string>

class Scene
{
private:
    char scene_id;
    std::string scene_filename;
    std::vector<Platform> platforms;
    Player *player1;
    Player *player2;

public:
    Scene(char scene_id, Player *player1, Player *player2);
    std::vector<std::string> tokenizer(std::string word, char del);
    void load_scene();
    std::vector<Platform> get_platforms();
};