/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_jump.c
*/

#include "../include/my_runner.h"

void game_stop(window_cre_t *window, sprite_t *spr, texture_t *text)
{
    draw_stop(window, spr, text);
    sfMusic_stop(spr->music2);
}

void draw_stop(window_cre_t *window, sprite_t *spr, texture_t *text)
{
    sfRenderWindow_clear(window->window_game, sfBlack);
    sfRenderWindow_drawText(window->window_game, text->text, NULL);
    sfRenderWindow_drawText(window->window_game, text->text2, NULL);
    sfText_setColor(text->text2, sfRed);
    sfText_setPosition(text->text, pos_score_end);
    sfText_setPosition(text->text2, pos_defeat);
    sfText_setScale(text->text, (sfVector2f){2,2});
    sfText_setScale(text->text2, (sfVector2f){5,5});
    sfRenderWindow_display(window->window_game);
}