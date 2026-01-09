/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** destroy
*/
#include "../include/my_hunter.h"

void destroy_game(hunter_t *game)
{
    sfView_destroy(game->view);
    sfMusic_destroy(game->menu_music);
    sfMusic_destroy(game->game_music);
    if (game->death_sound)
        sfSound_destroy(game->death_sound);
    if (game->death_sound_buffer)
        sfSoundBuffer_destroy(game->death_sound_buffer);
    sfText_destroy(game->score_text);
    sfText_destroy(game->menu_text);
    sfText_destroy(game->game_over_text);
    sfFont_destroy(game->font);
    sfSprite_destroy(game->duck);
    sfClock_destroy(game->duck_anim_clock);
    sfClock_destroy(game->duck_move_clock);
    sfTexture_destroy(game->duck_texture);
    sfSprite_destroy(game->game_background);
    sfTexture_destroy(game->game_texture);
    sfSprite_destroy(game->menu_background);
    sfTexture_destroy(game->menu_texture);
    sfRenderWindow_destroy(game->window);
}
