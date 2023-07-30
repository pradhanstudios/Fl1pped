#include "Player.h"

Player::Player(Vector2 position, Vector2 size, Color skin)
{
    this->position = position;
    this->size = size;
    this->skin = skin;
    this->can_jump = false;
}

Vector2 Player::get_position()
{
    return this->position;
}

Vector2 Player::get_velocity()
{
    return this->velocity;
}

Vector2 Player::get_acceleration()
{
    return this->acceleration;
}

Vector2 Player::get_size()
{
    return this->size;
}

bool Player::get_jump()
{
    return this->can_jump;
}

void Player::draw_player()
{
    // DrawTextureV(this->position, this->size, this->skin);
    DrawRectangleV(this->position, this->size, this->skin);
}

void Player::update(Platform plat)
{
    this->move(plat);
}

void Player::move(Platform plat)
{
    // set acceleration values
    this->acceleration.x = 0;
    this->acceleration.y = GRAVITY;

    if (IsKeyDown(KEY_A))
    {
        this->acceleration.x = -ACCELERATION;
    }
    if (IsKeyDown(KEY_D))
    {
        this->acceleration.x = ACCELERATION;
    }

    // stand on platform
    bool collides = this->collides_with_platform(plat);
    if (this->velocity.y > 0)
    {
        if (collides)
        {
            this->position.y = plat.get_position().y - this->size.y;
            this->velocity.y = 0;
        }
    }

    // jump
    if (IsKeyDown(KEY_W) && this->collides_with_platform(plat))
    {
        this->jump();
    }

    // 2D kinematics
    this->acceleration.x += this->velocity.x * FRICTION;
    this->velocity.x += this->acceleration.x;
    this->velocity.y += this->acceleration.y;
    this->position.x += this->velocity.x + (0.5 * this->acceleration.x);
    this->position.y += this->velocity.y + (0.5 * this->acceleration.y);

    // horizontal screen warp
    if (this->position.x > GetScreenWidth())
    {
        this->position.x = 0;
    }
    if (this->position.x < 0)
    {
        this->position.x = GetScreenWidth();
    }
}

void Player::jump()
{
    this->velocity.y = -10;
}

// input: list of platforms
bool Player::collides_with_platform(Platform plat)
{
    float plat_right = plat.get_position().x + plat.get_size().x;
    float play_right = this->position.x + this->size.x;

    float plat_bot = plat.get_position().y + plat.get_size().y;
    float play_bot = this->position.y + this->size.y;

    bool in_x = ((this->position.x <= plat_right) && (play_right >= plat.get_position().x));
    bool in_y = ((play_bot >= plat.get_position().y) && (this->position.y <= plat_bot));

    // simple collision
    return in_x && in_y;
}