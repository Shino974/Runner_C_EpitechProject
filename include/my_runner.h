/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_runner.h
*/

#ifndef MY_RUNNER_H_
#define MY_RUNNER_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Network.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <time.h>

//Create
#define SFRW_CRE sfRenderWindow_create
#define SFT_CFF sfTexture_createFromFile
#define SFS_C sfSprite_create
#define SFS_ST sfSprite_setTexture
#define SFT_SR sfTexture_setRepeated

//Display
#define SFRW_C sfRenderWindow_clear
#define SFRW_DS sfRenderWindow_drawSprite
#define SFRW_DIS sfRenderWindow_display

//Destroy
#define SFS_D sfSprite_destroy
#define SFRW_DES sfRenderWindow_destroy

//Utils
#define SFS_GGB sfSprite_getGlobalBounds
#define SFM_GPRW sfMouse_getPositionRenderWindow
#define mode (sfVideoMode){1920, 1080, 32}
#define pos_unicorn (sfVector2f){1, 860}
#define pos_enemis (sfVector2f){1900, 900}
#define pos_credit (sfVector2f){1390, 810}
#define pos_score_end (sfVector2f){900, 1}
#define pos_defeat (sfVector2f){800, 400}
#define pos_play (sfVector2f){150, 600}
#define pos_score (sfVector2f){1800, 1}
#define pos_close_credit (sfVector2f){1220, 10}

typedef struct clck {
    sfTime time;
    sfClock *clock;
} clck_t;

typedef struct score {
    unsigned int stock;
    float last_second;
} score_t;

typedef struct window_cre {
    sfRenderWindow *window_game;
    sfRenderWindow *window_credit;
    sfRenderWindow *window_hub;
    int collision;
} window_cre_t;

typedef struct texture {
    sfTexture *unicorn_text;
    sfTexture *enemis_text;
    sfTexture *back_hub_text;
    sfTexture *title_game_text;
    sfTexture *credit_text;
    sfTexture *rules_text;
    sfTexture *close_credit_text;
    sfTexture *preground_text;
    sfTexture *ground_text;
    sfTexture *background_text;
    sfTexture *sky_text;
    sfTexture *sky2_text;
    sfTexture *play_text;
    sfFont *font;
    sfFont *font2;
    sfText *text;
    sfText *text2;
} texture_t;

typedef struct sprite {
    sfSprite *unicorn_spr;
    sfSprite *enemis_spr;
    sfSprite *back_hub_spr;
    sfSprite *title_game_spr;
    sfSprite *credit_spr;
    sfSprite *rules_spr;
    sfSprite *close_credit_spr;
    sfSprite *pregroud_spr;
    sfSprite *ground_spr;
    sfSprite *background_spr;
    sfSprite *sky_spr;
    sfSprite *sky2_spr;
    sfSprite *play_spr;
    sfMusic *music2;
    sfIntRect unicorn_rect;
    sfIntRect among_rect;
} sprite_t;

//Menu
void hache(void);
void hub(window_cre_t *window, texture_t *text, sprite_t *spr, clck_t *temp);
void create_text_hub(texture_t *text, sprite_t *spr);
void display_hub(window_cre_t *window, sprite_t *spr);
void destroy_hub(window_cre_t *window, sprite_t *spr);
void play_b_pos(window_cre_t *window, sprite_t *spr, texture_t *text,
    clck_t *temp);

//Crédit
void credit(window_cre_t *window, texture_t *text, sprite_t *spr);
void credit_pos(window_cre_t *window, sprite_t *spr, texture_t *text);
void close_credit_pos(window_cre_t *window, sprite_t *spr, texture_t *text);
void create_text_credit(texture_t *text, sprite_t *spr);
void display_credit(window_cre_t *window, sprite_t *spr);
void destroy_credit(window_cre_t *window, sprite_t *spr);

//Game
void game(window_cre_t *window, texture_t *text, sprite_t *spr, clck_t *temp);
void create_text_game(texture_t *text, sprite_t *spr, clck_t *temp);
void display_game(window_cre_t *window, sprite_t *spr, texture_t *text,
    clck_t *temp);
void destroy_game(window_cre_t *window, sprite_t *spr, texture_t *text,
    clck_t *temp);
void game_music(sprite_t *spr);
void anim_unicorn(sfClock **temp, sprite_t *spr, sfIntRect *rect);
void anime_sky(sprite_t *spr, texture_t *text);
void anime_background(sprite_t *spr, texture_t *text);
void anime_ground(sprite_t *spr, texture_t *text);
void anime_preground(sprite_t *spr, texture_t *text);
void gravity(sprite_t *spr);
void anim_all(sprite_t *spr, texture_t *text);
void create_font(texture_t *text);
void display_font(window_cre_t *window, texture_t *text);
void destroy_font(texture_t *text);
void jump(texture_t *text, sprite_t *spr);
void calculator(clck_t *temp, score_t *score, texture_t *text);
char *itch(int nb, char *str);
void victory(score_t *score, texture_t *text, sprite_t *spr,
    window_cre_t *window);
void ani(clck_t temp, sprite_t *spr, window_cre_t *window);
void eni(clck_t temp, sprite_t *spr, sfIntRect *rect2);
void line_among(window_cre_t *window, sprite_t *spr);
void collision(sprite_t *spr, window_cre_t *window);
void game_stop(window_cre_t *window, sprite_t *spr, texture_t *text);
void draw_stop(window_cre_t *window, sprite_t *spr, texture_t *text);
score_t score_inti(void);

#endif