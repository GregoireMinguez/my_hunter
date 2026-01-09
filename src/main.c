/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** main
*/

#include "../include/my_hunter.h"

static int has_help_flag(int argc, char **argv)
{
    if (argc != 2)
        return 0;
    return argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0';
}

int main(int argc, char **argv)
{
    hunter_t game;

    if (has_help_flag(argc, argv))
        return display_wiki();
    if (argc != 1)
        return 84;
    init_game(&game);
    while (sfRenderWindow_isOpen(game.window)) {
        handle_events(&game);
        update_duck_animation(&game);
        update_duck_motion(&game);
        render_game(&game);
    }
    destroy_game(&game);
    return 0;
}
