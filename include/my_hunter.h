/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** hunter.h
*/
#ifndef MY_HUNTER
    #define MY_HUNTER

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>

typedef struct hunter_s {
    sfRenderWindow *window;
    sfView *view;
    sfTexture *duck_texture;
    sfSprite *duck;
    sfClock *duck_anim_clock;
    sfClock *duck_move_clock;
    unsigned duck_frame;
    float duck_speed;
    sfFont *font;
    sfTexture *menu_texture;
    sfSprite *menu_background;
    sfTexture *game_texture;
    sfSprite *game_background;
    sfText *menu_text;
    sfText *score_text;
    sfText *game_over_text;
    sfMusic *menu_music;
    sfMusic *game_music;
    sfSoundBuffer *death_sound_buffer;
    sfSound *death_sound;
    unsigned score;
    sfBool in_menu;
    sfBool game_over;
} hunter_t;

void init_game(hunter_t *game);
void init_window(hunter_t *game);
void init_duck(hunter_t *game);
void update_duck_animation(hunter_t *game);
void update_duck_motion(hunter_t *game);
void respawn_duck(hunter_t *game);
void init_backgrounds(hunter_t *game);
void update_background_scale(hunter_t *game);
void init_texts(hunter_t *game);
void init_music(hunter_t *game);
void destroy_game(hunter_t *game);
void stop_game(hunter_t *game);
void reset_run(hunter_t *game);
void trigger_game_over(hunter_t *game);
void handle_events(hunter_t *game);
void render_game(hunter_t *game);
void update_score_text(hunter_t *game);
int display_wiki(void);

#endif /* MY_HUNTER*/
