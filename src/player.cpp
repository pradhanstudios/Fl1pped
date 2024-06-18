#include "player.hpp"

void Player::update(const std::vector<Object> &objects) {

    this->acceleration_y = this->gravity_direction * GRAVITY;

    if (IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_UP)) {
        // printf("I jumped\n");
        this->jump();
    }

    this->acceleration_x += this->velocity_x * FRICTION;
    this->velocity_x += this->acceleration_x;
    this->velocity_y += this->acceleration_y;
    this->rect.x += this->velocity_x + (0.5f * this->acceleration_x);
    this->rect.y += this->velocity_y + (0.5f * this->acceleration_y);
};