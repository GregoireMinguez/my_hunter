/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** music
*/

#include "../include/my_hunter.h"

void init_music(hunter_t *game)
{
    game->menu_music = sfMusic_createFromFile("assets/menu_theme.ogg");
    game->game_music = sfMusic_createFromFile("assets/game_theme.ogg");
    game->death_sound_buffer = sfSoundBuffer_createFromFile("assets/death.ogg");
    game->death_sound = sfSound_create();
    if (game->death_sound && game->death_sound_buffer)
        sfSound_setBuffer(game->death_sound, game->death_sound_buffer);
    sfMusic_setLoop(game->menu_music, sfTrue);
    sfMusic_setLoop(game->game_music, sfTrue);
    sfMusic_play(game->menu_music);
}
