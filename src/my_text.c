/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_text.c
*/

#include "../include/my_runner.h"

void create_font(texture_t *text)
{
    text->font = sfFont_createFromFile("./ressources/timer.ttf");
    text->font2 = sfFont_createFromFile("./ressources/timer2.ttf");
    text->text = sfText_create();
    text->text2 = sfText_create();
    sfText_setString(text->text, "0");
    sfText_setString(text->text2, "Defeat");
    sfText_setFont(text->text, text->font);
    sfText_setFont(text->text2, text->font2);
    sfText_setCharacterSize(text->text, 50);
    sfText_setPosition(text->text, pos_score);
}

void display_font(window_cre_t *window, texture_t *text)
{
    sfRenderWindow_drawText(window->window_game, text->text, NULL);
}

void destroy_font(texture_t *text)
{
    sfText_destroy(text->text);
    sfFont_destroy(text->font);
    sfText_destroy(text->text2);
    sfFont_destroy(text->font2);
}

void calculator(clck_t *temp, score_t *score, texture_t *text)
{
    sfTime time = sfClock_getElapsedTime(temp->clock);
    float second = sfTime_asSeconds(time);

    if (score->last_second + 0.55 > second) {
        score->stock += 1;
        score->last_second = second;
        sfText_setString(text->text, itch(score->stock, ""));
    }
}

score_t score_inti(void)
{
    score_t test;
    test.last_second = 0;
    test.stock = 0;

    return(test);
}