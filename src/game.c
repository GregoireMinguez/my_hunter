/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** game
*/

#include "../include/my_hunter.h"
#include <stdlib.h>
#include <time.h>

void init_window(hunter_t *game)
{
    sfVideoMode mode = {1280, 720, 32};

    game->window =
        sfRenderWindow_create(mode, "my_hunter", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    game->view = sfView_createFromRect(
        (sfFloatRect){0.f, 0.f, (float)mode.width, (float)mode.height});
    sfRenderWindow_setView(game->window, game->view);
}

void init_game(hunter_t *game)
{
    *game = (hunter_t){0};
    srand((unsigned)time(NULL));
    init_window(game);
    init_duck(game);
    init_backgrounds(game);
    init_texts(game);
    init_music(game);
    game->in_menu = sfTrue;
    game->game_over = sfFalse;
}

void stop_game(hunter_t *game)
{
    if (!game || !game->window)
        return;
    if (game->game_music)
        sfMusic_stop(game->game_music);
    if (game->menu_music)
        sfMusic_stop(game->menu_music);
    sfRenderWindow_close(game->window);
}

void reset_run(hunter_t *game)
{
    if (!game)
        return;
    game->score = 0;
    update_score_text(game);
    game->game_over = sfFalse;
    game->duck_speed = 0.f;
    respawn_duck(game);
    if (game->menu_music)
        sfMusic_stop(game->menu_music);
    if (game->game_music)
        sfMusic_play(game->game_music);
}

void trigger_game_over(hunter_t *game)
{
    if (!game || game->game_over)
        return;
    game->game_over = sfTrue;
    if (game->game_music)
        sfMusic_stop(game->game_music);
    if (game->menu_music)
        sfMusic_play(game->menu_music);
}
