/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** duck
*/

#include "../include/my_hunter.h"
#include <stdlib.h>
#include <math.h>

static const float DUCK_FRAME_DURATION = 0.1f;
static const float DUCK_SCALE = 1.0f;
static const float DUCK_MIN_SPEED = 200.f;
static const float DUCK_SPEED_MULTIPLIER = 1.04f;
static const float DUCK_MAX_SPEED = 2000.0f;

static const sfIntRect DUCK_FRAMES[] = {
    {1, 1, 150, 140},
    {180, 1, 150, 140},
    {350, 1, 150, 140},
    {500, 1, 170, 140},
    {700, 1, 180, 140},
    {1, 220, 150, 130},
    {180, 220, 150, 120},
    {370, 220, 150, 120},
    {550, 220, 150, 120},
    {700, 220, 150, 120},
    {1, 370, 150, 130},
    {180, 370, 150, 130},
    {340, 370, 170, 130},
    {520, 370, 180, 130},
};

static const unsigned DUCK_FRAME_COUNT =
    sizeof(DUCK_FRAMES) / sizeof(DUCK_FRAMES[0]);

void respawn_duck(hunter_t *game)
{
    const sfVector2u window = sfRenderWindow_getSize(game->window);
    const sfFloatRect bounds = sfSprite_getGlobalBounds(game->duck);
    const float max_y = (float)window.y - bounds.height;
    const float y = max_y > 0.f ? (float)(rand() % (int)(max_y + 1.f)) : 0.f;

    sfSprite_setPosition(game->duck, (sfVector2f){-bounds.width, y});
    if (game->duck_speed <= 0.f)
        game->duck_speed = DUCK_MIN_SPEED;
    sfClock_restart(game->duck_move_clock);
}

void update_duck_animation(hunter_t *game)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(game->duck_anim_clock)) <
        DUCK_FRAME_DURATION)
        return;
    game->duck_frame = (game->duck_frame + 1) % DUCK_FRAME_COUNT;
    sfSprite_setTextureRect(game->duck, DUCK_FRAMES[game->duck_frame]);
    sfClock_restart(game->duck_anim_clock);
}

void init_duck(hunter_t *game)
{
    game->duck_texture = sfTexture_createFromFile("assets/final.png", NULL);
    game->duck = sfSprite_create();
    sfSprite_setTexture(game->duck, game->duck_texture, sfTrue);
    game->duck_anim_clock = sfClock_create();
    game->duck_move_clock = sfClock_create();
    game->duck_frame = 0;
    sfSprite_setTextureRect(game->duck, DUCK_FRAMES[0]);
    sfSprite_scale(game->duck, (sfVector2f){DUCK_SCALE, DUCK_SCALE});
    respawn_duck(game);
}

void update_duck_motion(hunter_t *game)
{
    const sfVector2u window = sfRenderWindow_getSize(game->window);
    const float seconds =
        sfTime_asSeconds(sfClock_restart(game->duck_move_clock));
    sfFloatRect bounds;

    if (game->in_menu || game->game_over)
        return;
    sfSprite_move(game->duck, (sfVector2f){game->duck_speed * seconds, 0.f});
    game->duck_speed *= powf(DUCK_SPEED_MULTIPLIER, seconds);
    if (game->duck_speed > DUCK_MAX_SPEED)
        game->duck_speed = DUCK_MAX_SPEED;
    bounds = sfSprite_getGlobalBounds(game->duck);
    if (bounds.left + bounds.width >= (float)window.x)
        trigger_game_over(game);
}
