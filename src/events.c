/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** event
*/

#include "../include/my_hunter.h"

static void on_duck_hit(hunter_t *game)
{
    if (game->death_sound)
        sfSound_play(game->death_sound);
    game->score += 1;
    update_score_text(game);
    respawn_duck(game);
}

static void handle_mouse_event(hunter_t *game, const sfEvent *event)
{
    sfFloatRect bounds;
    sfVector2i mouse_pixels;
    sfVector2f mouse_world;

    if (event->type != sfEvtMouseButtonPressed ||
        event->mouseButton.button != sfMouseLeft || game->in_menu)
        return;
    if (game->game_over) {
        reset_run(game);
        return;
    }
    mouse_pixels = (sfVector2i){event->mouseButton.x, event->mouseButton.y};
    mouse_world = sfRenderWindow_mapPixelToCoords(
        game->window, mouse_pixels, game->view);
    bounds = sfSprite_getGlobalBounds(game->duck);
    if (sfFloatRect_contains(&bounds, mouse_world.x, mouse_world.y))
        on_duck_hit(game);
}

static void handle_resize_event(hunter_t *game, const sfEvent *event)
{
    sfVector2f new_size = {(float)event->size.width, (float)event->size.height};

    sfView_setSize(game->view, new_size);
    sfView_setCenter(game->view,
        (sfVector2f){new_size.x / 2.f, new_size.y / 2.f});
    sfRenderWindow_setView(game->window, game->view);
    update_background_scale(game);
}

static void handle_key_event(hunter_t *game, const sfEvent *event)
{
    if (event->type != sfEvtKeyPressed)
        return;
    if (event->key.code == sfKeyEscape) {
        sfRenderWindow_close(game->window);
        return;
    }
    if (game->in_menu &&
        (event->key.code == sfKeyEnter || event->key.code == sfKeySpace)) {
        game->in_menu = sfFalse;
        reset_run(game);
    }
}

void handle_events(hunter_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (event.type == sfEvtResized)
            handle_resize_event(game, &event);
        handle_key_event(game, &event);
        handle_mouse_event(game, &event);
    }
}
