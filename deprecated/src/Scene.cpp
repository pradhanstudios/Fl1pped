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
        if (args.size() > 3)
        {
            for (std::string s : args)
            {
                std::cerr << s << std::endl;
            }
            // fprintf(stderr, "%s", args); //%f, %f, %f \n", std::stoi(args[4]), std::stoi(args[5]), std::stoi(args[6]), std::stoi(args[7]));
            this->platforms.push_back(Platform((Vector2){std::stof(args[0]), std::stof(args[1])}, (Vector2){std::stof(args[2]) - std::stof(args[0]), std::stof(args[3]) - std::stof(args[1])}, (Color){std::stoi(args[4]), std::stoi(args[5]), std::stoi(args[6]), std::stoi(args[7])}));
        }
        else if (args.size() == 1)
        {
            switch (line)
            {
            case 1:
                player1->set_bot_screen_warp(std::stoi(args[0]));
                player2->set_bot_screen_warp(std::stoi(args[0]));
                line++;
            case 2:
                player2->set_top_screen_warp(std::stoi(args[0]));
                player1->set_top_screen_warp(std::stoi(args[0]));
            };
        }
        else
        {
            switch (line)
            {
            case 1:
                player1->set_position((Vector2){std::stof(args[0]), std::stof(args[1])});
                // player1->set_dir(std::stoi(args[2]));
            case 2:
                player2->set_position((Vector2){std::stof(args[0]), std::stof(args[1])});
                // player2->set_dir(std::stoi(args[2]));
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
