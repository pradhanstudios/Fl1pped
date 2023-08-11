#include "Scene.h"

Scene::Scene(std::string scene_id, Player *player1, Player *player2)
{
    this->scene_id = scene_id;
    this->scene_filename = ("../assets/scenes/%s.txt", scene_id);
    // fprintf(stderr, "../assets/scenes/scene_%c.txt \n", this->scene_id);
    this->player1 = player1;
    this->player2 = player2;
}
std::vector<std::string> Scene::tokenizer(std::string word, char del)
{
    std::vector<std::string> output;
    std::stringstream ss(word);
    std::string text;
    while (!ss.eof())
    {
        std::getline(ss, text, del);
        output.push_back(text);
    }
    return output;
}

void Scene::load_scene()
{
    std::string text;
    std::ifstream fh(this->scene_filename);
    std::vector<std::string> args;
    int line = 1;

    while (std::getline(fh, text))
    {
        // std::cout << text << std::endl;
        args = this->tokenizer(text, ',');
        if (args.size() > 2)
        {
            this->platforms.push_back(Platform((Vector2){std::stof(args[0]), std::stof(args[1])}, (Vector2){std::stof(args[2]), std::stof(args[3])}, (std::stof(args[4]) ? MAROON : GREEN)));
        }
        else
        {
            switch (line)
            {
            case 1:
                player1->set_position((Vector2){std::stof(args[0]), std::stof(args[1])});
            case 2:
                player2->set_position((Vector2){std::stof(args[0]), std::stof(args[1])});
            }
            line++;
        }
    }
    fh.close();
}
std::vector<Platform> Scene::get_platforms()
{
    return this->platforms;
}
