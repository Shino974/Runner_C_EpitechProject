/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_window->c
*/

#include "../include/my_runner.h"

void game(window_cre_t *window, texture_t *text, sprite_t *spr, clck_t *temp)
{
    sfEvent event;
    score_t score = score_inti();
    spr->unicorn_rect = (sfIntRect){0, 0, 173, 97};
    spr->among_rect = (sfIntRect){0, 0, 32, 33};
    window->collision = 0;

    window->window_game = SFRW_CRE(mode, "myrunner", sfResize | sfClose, NULL);
    create_text_game(text, spr, temp);
    sfRenderWindow_setFramerateLimit(window->window_game, 60);
    while (sfRenderWindow_isOpen(window->window_game)) {
        while (sfRenderWindow_pollEvent(window->window_game, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window->window_game);
        if (window->collision == 0) {
            display_game(window, spr, text, temp);
            ani(*temp, spr, window);
            collision(spr, window);
            calculator(temp, &score, text);
        } else
            game_stop(window, spr, text);
    }
    destroy_game(window, spr, text, temp);
}

void hub(window_cre_t *window, texture_t *text, sprite_t *spr, clck_t *temp)
{
    sfEvent event;

    window->window_hub = SFRW_CRE(mode, "hub", sfResize | sfClose, NULL);
    create_text_hub(text, spr);
    sfRenderWindow_setFramerateLimit(window->window_hub, 60);
    while (sfRenderWindow_isOpen(window->window_hub)) {
        while (sfRenderWindow_pollEvent(window->window_hub, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window->window_hub);
        }
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            credit_pos(window, spr, text);
            play_b_pos(window, spr, text, temp);
        }
        display_hub(window, spr);
    }
    destroy_hub(window, spr);
}

void credit(window_cre_t *window, texture_t *text, sprite_t *spr)
{
    sfEvent event;

    window->window_credit = SFRW_CRE(mode, "Crédit", sfResize | sfClose, NULL);
    create_text_credit(text, spr);
    sfRenderWindow_setFramerateLimit(window->window_credit, 60);
    while (sfRenderWindow_isOpen(window->window_credit)) {
        while (sfRenderWindow_pollEvent(window->window_credit, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window->window_credit);
            }
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            close_credit_pos(window, spr, text);
        }
        display_credit(window, spr);
    }
    destroy_credit(window, spr);
}