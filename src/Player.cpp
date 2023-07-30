#include "Player.h"

Player::Player(Vector2 position, Vector2 size, Color skin)
{
    this->position = position;
    this->size = size;
    this->skin = skin;
}

void Player::draw_player()
{
    // DrawTextureV(this->position, this->size, this->skin);
    DrawRectangleV(this->position, this->size, this->skin);
}