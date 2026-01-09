/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** background
*/
#include "../include/my_hunter.h"

static void scale_background(sfSprite *sprite, sfTexture *texture,
    const sfVector2u *win_size)
{
    sfVector2u tex_size = sfTexture_getSize(texture);

    sfSprite_setScale(sprite, (sfVector2f){
            (float)win_size->x / (float)tex_size.x,
            (float)win_size->y / (float)tex_size.y});
}

void init_backgrounds(hunter_t *game)
{
    game->menu_texture =
        sfTexture_createFromFile("assets/menu_background.png", NULL);
    game->menu_background = sfSprite_create();
    sfSprite_setTexture(game->menu_background, game->menu_texture, sfTrue);
    game->game_texture =
        sfTexture_createFromFile("assets/game_background.png", NULL);
    game->game_background = sfSprite_create();
    sfSprite_setTexture(game->game_background, game->game_texture, sfTrue);
    update_background_scale(game);
}

void update_background_scale(hunter_t *game)
{
    sfVector2u win = sfRenderWindow_getSize(game->window);

    scale_background(game->menu_background, game->menu_texture, &win);
    scale_background(game->game_background, game->game_texture, &win);
}
