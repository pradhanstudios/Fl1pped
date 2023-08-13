#include "PlayerCamera.h"

PlayerCamera::PlayerCamera(Player *player)
{
    this->player = player;
    // this->camera = camera;
    this->camera.target = (Vector2){player->get_position().x + 20.0f, player->get_position().y + 20.0f};
    this->camera.offset = (Vector2){GetScreenWidth() / 4.0f, GetScreenHeight() / 2.0f};
    if (player->get_dir())
    {
        this->camera.rotation = 0.0f;
    }
    else
    {
        this->camera.rotation = 180.0f;
    }
    this->camera.zoom = 1.0f;
}
void PlayerCamera::start_camera()
{
    BeginMode2D(this->camera);
}
void PlayerCamera::target_player()
{
    this->camera.target = (Vector2){player->get_position().x + 15.0f, player->get_position().y + 40.0f};
}
void PlayerCamera::stop_camera()
{
    EndMode2D();
}
void PlayerCamera::zoom_in()
{
    camera.zoom -= 0.1;
}
void PlayerCamera::zoom_out()
{
    camera.zoom += 0.1;
}