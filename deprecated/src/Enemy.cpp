#include "Enemy.h"

Enemy::Enemy()
{
    // this->velocity = (Vector2){0.0, 0.0};
    // this->acceleration.x = 0;
    // this->dir = dir;
    // if (dir)
    // {
    //     this->acceleration.y = GRAVITY;
    // }
    // else
    // {
    //     this->acceleration.y = -GRAVITY;
    // }
    // this->rect = Rectangle{position.x, position.y, size.x, size.y};
    // this->skin = skin;

    // this->update_collision_points();
    ;
}

void Enemy::update_collision_points()
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

void Enemy::collides_with_platform(Platform plat)
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

void Enemy::collides_with_platform(std::vector<Platform> platforms, int num_platforms)
{
    this->update_collision_points();

    // loop thru each platform and add each platform the player touches to collide_arr
    for (int i = 0; i < num_platforms; i++)
    {
        this->collides_with_platform(platforms[i]);
    }
}
void Enemy::jump()
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
void Enemy::set_position(Vector2 position)
{
    this->rect.x = position.x;
    this->rect.y = position.y;
}
void Enemy::set_dir(int direction)
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

// blob time
Blob::Blob(Vector2 position, Vector2 size, Color skin, int dir)
{
    this->velocity = (Vector2){0.0, 0.0};
    this->acceleration.x = 0;
    this->dir = dir;
    this->movement_direction = 1;
    fprintf(stderr, "%i", movement_direction);
    if (dir)
    {
        this->acceleration.y = GRAVITY;
    }
    else
    {
        this->acceleration.y = -GRAVITY;
    }
    this->rect = Rectangle{position.x, position.y, size.x, size.y};
    rect.x = position.x;
    rect.y = position.y;
    this->skin = skin;

    this->update_collision_points();
}

void Blob::move(std::vector<Platform> platforms, int num_platforms)
{
    this->collides_with_platform(platforms, num_platforms);
    this->acceleration.x = 0;
    if (this->movement_direction)
    {
        this->acceleration.x = -ACCELERATION;
    }
    else
    {
        this->acceleration.x = ACCELERATION;
    }
    if (this->dir)
    {
        this->acceleration.y = GRAVITY;
    }
    else
    {
        this->acceleration.y = -GRAVITY;
    }
    if (!this->collided_points[6] && !this->collided_points[7] && !this->collided_points[8])
    {
        this->acceleration.x = 0;
        this->velocity.x = 0;
    }
    if (!this->collided_points[8])
    {
        this->acceleration.x = -ACCELERATION;
        this->movement_direction = 1;
    }
    if (!this->collided_points[6])
    {
        this->acceleration.x = ACCELERATION;
        this->movement_direction = 0;
    }
    if (collided_points[7])
    {
        this->velocity.y = -1;
    }
    this->acceleration.x += this->velocity.x * FRICTION;
    this->velocity.x += this->acceleration.x;
    this->velocity.y += this->acceleration.y;
    this->rect.x += this->velocity.x + (0.5 * this->acceleration.x);
    this->rect.y += this->velocity.y + (0.5 * this->acceleration.y);
}