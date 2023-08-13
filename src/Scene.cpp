#include "Scene.h"

Scene::Scene(char scene_id1, char scene_id2, Player *player1, Player *player2)
{
    this->scene_filename = (TextFormat("../assets/scenes/scene_%c%c.txt", scene_id1, scene_id2));
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
    Color plat_colors[2] = {GREEN, BLUE};

    while (std::getline(fh, text))
    {

        if (text[0] == '/')
        {
            continue;
        }

        // std::cout << text << std::endl;
        args = this->tokenizer(text, ',');
        if (args.size() > 2)
        {
            this->platforms.push_back(Platform((Vector2){std::stof(args[0]), std::stof(args[1])}, (Vector2){std::stof(args[2]), std::stof(args[3])}, plat_colors[(std::stoi(args[4]))]));
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
