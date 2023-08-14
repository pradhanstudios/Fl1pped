#include "Player.h"

Player::Player(Vector2 position, Vector2 size, Color skin, int controls[3], int dir)
{
    this->velocity = (Vector2){0.0, 0.0};
    this->acceleration.x = 0;
    this->dir = dir;
    if (dir)
    {
        this->acceleration.y = GRAVITY;
    }
    else
    {
        this->acceleration.y = -GRAVITY;
    }
    this->rect = Rectangle{position.x, position.y, size.x, size.y};
    this->skin = skin;
    this->up = controls[0];
    this->left = controls[1];
    this->right = controls[2];

    this->update_collision_points();
}

void Player::update_collision_points()
{
    this->collision_points.clear();

    // left is less than right
    this->point_1 = (Vector2){this->rect.x, this->rect.y};                                                // top left
    this->point_2 = (Vector2){this->rect.x + this->rect.width / 2, this->rect.y};                         // top middle
    this->point_3 = (Vector2){this->rect.x + this->rect.width, this->rect.y};                             // top right
    this->point_4 = (Vector2){this->rect.x, this->rect.y + this->rect.height / 2};                        // middle left
    this->point_5 = (Vector2){this->rect.x + this->rect.width / 2, this->rect.y + this->rect.height / 2}; // middle middle
    this->point_6 = (Vector2){this->rect.x + this->rect.width, this->rect.y + this->rect.height / 2};     // middle right
    this->point_7 = (Vector2){this->rect.x, this->rect.y + this->rect.height};                            // bottom left
    this->point_8 = (Vector2){this->rect.x + this->rect.width / 2, this->rect.y + this->rect.height};     // bottom middle
    this->point_9 = (Vector2){this->rect.x + this->rect.width, this->rect.y + this->rect.height};         // bottom right
    this->thresh_point_1 = (Vector2){point_1.x + 0.05, point_1.y};
    this->thresh_point_2 = (Vector2){point_1.x, point_1.y + 0.05};
    this->thresh_point_3 = (Vector2){point_3.x - 0.05, point_3.y};
    this->thresh_point_4 = (Vector2){point_3.x, point_3.y + 0.05};
    this->thresh_point_5 = (Vector2){point_7.x + 0.05, point_7.y};
    this->thresh_point_6 = (Vector2){point_7.x, point_7.y - 0.05};
    this->thresh_point_7 = (Vector2){point_9.x - 0.05, point_9.y};
    this->thresh_point_8 = (Vector2){point_9.x, point_9.y - 0.05};

    this->collision_points.push_back(this->point_1);
    this->collision_points.push_back(this->point_2);
    this->collision_points.push_back(this->point_3);
    this->collision_points.push_back(this->point_4);
    this->collision_points.push_back(this->point_5);
    this->collision_points.push_back(this->point_6);
    this->collision_points.push_back(this->point_7);
    this->collision_points.push_back(this->point_8);
    this->collision_points.push_back(this->point_9);
    this->collision_points.push_back(this->thresh_point_1);
    this->collision_points.push_back(this->thresh_point_2);
    this->collision_points.push_back(this->thresh_point_3);
    this->collision_points.push_back(this->thresh_point_4);
    this->collision_points.push_back(this->thresh_point_5);
    this->collision_points.push_back(this->thresh_point_6);
    this->collision_points.push_back(this->thresh_point_7);
    this->collision_points.push_back(this->thresh_point_8);

    for (int i = 0; i < 17; i++)
    {
        this->collided_points[i] = 0;
    }
}

Vector2 Player::get_position()
{
    return (Vector2){this->rect.x, this->rect.y};
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
    return (Vector2){this->rect.width, this->rect.height};
}

// bool Player::get_jump()
// {
//     return this->can_jump;
// }

void Player::draw_player()
{
    // DrawTextureV(this->position, this->size, this->skin);
    DrawRectangleRec(this->rect, this->skin);
    // debug
    // for (Vector2 pos : this->collision_points)
    // {
    //     DrawPixelV(pos, RED);
    // }
}

void Player::update(std::vector<Platform> platforms, int num_platforms)
{
    this->move(platforms, num_platforms);
}

// void Player::update(Platform plat)
// {
//     this->move(plat);
// }

void Player::move(std::vector<Platform> platforms, int num_platforms)
{
    // set acceleration values
    this->acceleration.x = 0;
    if (this->dir)
    {
        this->acceleration.y = GRAVITY;
    }
    else
    {
        this->acceleration.y = -GRAVITY;
    }

    // player movement
    if (IsKeyDown(right))
    {
        this->acceleration.x = -ACCELERATION;
    }
    if (IsKeyDown(left))
    {
        this->acceleration.x = ACCELERATION;
    }

    // stand on platform
    // Platform collide_plat = this->collides_with_platform(platforms, num_platforms);
    this->collides_with_platform(platforms, num_platforms);

    bool collision = false;
    // fprintf(stderr, "c_arr: [");
    for (int i : this->collided_points)
    {
        // fprintf(stderr, " %d ", i);
        if (i == 1)
        {
            collision = true;
        }
    }
    // fprintf(stderr, "]\n");

    if (collision)
    {
        // left and right midpoints
        if ((this->collided_points[3]) || (this->collided_points[0] && this->collided_points[2 + 8]) || (this->collided_points[6] && this->collided_points[5 + 8]))
        {
            this->acceleration.x = ACCELERATION;
        }
        if ((this->collided_points[5]) || (this->collided_points[2] && this->collided_points[4 + 8]) || (this->collided_points[8] && this->collided_points[8 + 8]))
        {
            this->acceleration.x = -ACCELERATION;
        }

        // top and bot midpoints
        if ((this->collided_points[1]) || (this->collided_points[0] && this->collided_points[1 + 8]) || (this->collided_points[2] && this->collided_points[3 + 8]))
        {
            this->velocity.y = 1;
        }
        if ((this->collided_points[7]) || (this->collided_points[6] && this->collided_points[6 + 8]) || (this->collided_points[8] && this->collided_points[7 + 8]))
        {
            this->velocity.y = -1;
        }
    }
    // }

    // jump
    bool bot_col = (this->collided_points[7]) || (this->collided_points[6] && this->collided_points[6 + 8]) || (this->collided_points[8] && this->collided_points[7 + 8]);
    bool top_col = (this->collided_points[1]) || (this->collided_points[0] && this->collided_points[0 + 10]) || (this->collided_points[2] && this->collided_points[2 + 10]);
    if (IsKeyDown(up) && this->dir && bot_col)
    {
        this->jump();
    }
    if (IsKeyDown(up) && this->dir == 0 && top_col)
    {
        this->jump();
    }

    // 2D kinematics
    this->acceleration.x += this->velocity.x * FRICTION;
    this->velocity.x += this->acceleration.x;
    this->velocity.y += this->acceleration.y;
    this->rect.x += this->velocity.x + (0.5 * this->acceleration.x);
    this->rect.y += this->velocity.y + (0.5 * this->acceleration.y);

    if (this->rect.y > this->top_screen_warp)
    {
        this->rect.y = 0;
    }
    if (this->rect.y < this->bot_screen_warp)
    {
        this->rect.y = GetScreenHeight();
    }
}

void Player::jump()
{
    if (this->dir)
    {
        this->velocity.y = -JUMP;
    }
    else
    {
        this->velocity.y = JUMP;
    }
}

void Player::collides_with_platform(Platform plat)
{
    for (int i = 0; i < 9; i++)
    {
        Vector2 pos = this->collision_points[i];
        if (CheckCollisionPointRec(pos, (Rectangle){plat.get_position().x, plat.get_position().y, plat.get_size().x, plat.get_size().y}))
        {
            this->collided_points[i] = 1;
        }
    }
}

void Player::collides_with_platform(std::vector<Platform> platforms, int num_platforms)
{
    this->update_collision_points();

    // loop thru each platform and add each platform the player touches to collide_arr
    for (int i = 0; i < num_platforms; i++)
    {
        this->collides_with_platform(platforms[i]);
    }
}

void Player::set_position(Vector2 position)
{
    this->rect.x = position.x;
    this->rect.y = position.y;
}
void Player::set_bot_screen_warp(int arg)
{
    this->bot_screen_warp = arg;
}
void Player::set_top_screen_warp(int arg)
{
    this->top_screen_warp = arg;
}
void Player::set_dir(int direction)
{
    this->dir = direction;
    if (this->dir)
    {
        this->acceleration.y = GRAVITY;
    }
    else
    {
        this->acceleration.y = -GRAVITY;
    }
}