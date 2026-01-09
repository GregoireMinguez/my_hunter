/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** render
*/

#include "../include/my_hunter.h"

void render_game(hunter_t *game)
{
    sfRenderWindow_clear(game->window, sfColor_fromRGB(25, 25, 25));
    if (game->in_menu) {
        sfRenderWindow_drawSprite(game->window, game->menu_background, NULL);
        sfRenderWindow_drawText(game->window, game->menu_text, NULL);
    } else {
        sfRenderWindow_drawSprite(game->window, game->game_background, NULL);
        sfRenderWindow_drawSprite(game->window, game->duck, NULL);
        sfRenderWindow_drawText(game->window, game->score_text, NULL);
        if (game->game_over)
            sfRenderWindow_drawText(game->window, game->game_over_text, NULL);
    }
    sfRenderWindow_display(game->window);
}
