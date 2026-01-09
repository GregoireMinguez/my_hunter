/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** texts
*/

#include "../include/my_hunter.h"

static char *append_digits(char *cursor, unsigned value)
{
    if (value >= 10)
        cursor = append_digits(cursor, value / 10);
    *cursor = '0' + (value % 10);
    return cursor + 1;
}

void update_score_text(hunter_t *game)
{
    char buffer[32] = "Hits: ";
    char *cursor = buffer + 6;

    if (game->score == 0) {
        *cursor = '0';
        cursor += 1;
    } else
        cursor = append_digits(cursor, game->score);
    *cursor = '\0';
    sfText_setString(game->score_text, buffer);
}

static void init_menu_text(hunter_t *game, const sfVector2u *win)
{
    sfFloatRect bounds;

    game->menu_text = sfText_create();
    sfText_setFont(game->menu_text, game->font);
    sfText_setString(game->menu_text, "PRESS ENTER TO PLAY");
    sfText_setCharacterSize(game->menu_text, 40);
    bounds = sfText_getLocalBounds(game->menu_text);
    sfText_setOrigin(game->menu_text,
        (sfVector2f){bounds.left + bounds.width / 2.f,
            bounds.top + bounds.height / 2.f});
    sfText_setPosition(game->menu_text,
        (sfVector2f){(float)win->x / 2.f, (float)win->y / 2.f});
    sfText_setFillColor(game->menu_text, sfWhite);
}

static void init_score_text(hunter_t *game)
{
    game->score_text = sfText_create();
    sfText_setFont(game->score_text, game->font);
    sfText_setCharacterSize(game->score_text, 28);
    sfText_setPosition(game->score_text, (sfVector2f){20.f, 20.f});
    sfText_setFillColor(game->score_text, sfColor_fromRGB(255, 215, 0));
    update_score_text(game);
}

static void init_game_over_text(hunter_t *game, const sfVector2u *win)
{
    sfFloatRect bounds;

    game->game_over_text = sfText_create();
    sfText_setFont(game->game_over_text, game->font);
    sfText_setString(game->game_over_text, "GAME OVER\nClick to retry");
    sfText_setCharacterSize(game->game_over_text, 48);
    sfText_setLetterSpacing(game->game_over_text, 1.2f);
    bounds = sfText_getLocalBounds(game->game_over_text);
    sfText_setOrigin(game->game_over_text,
        (sfVector2f){bounds.left + bounds.width / 2.f,
            bounds.top + bounds.height / 2.f});
    sfText_setPosition(game->game_over_text,
        (sfVector2f){(float)win->x / 2.f, (float)win->y / 2.f});
    sfText_setFillColor(game->game_over_text, sfColor_fromRGB(255, 80, 80));
}

void init_texts(hunter_t *game)
{
    sfVector2u win = sfRenderWindow_getSize(game->window);

    game->font = sfFont_createFromFile("assets/metal-slug.otf");
    init_menu_text(game, &win);
    init_score_text(game);
    init_game_over_text(game, &win);
}
