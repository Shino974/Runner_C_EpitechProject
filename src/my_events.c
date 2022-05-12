/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_utils.c
*/

#include "../include/my_runner.h"

void credit_pos(window_cre_t *window, sprite_t *spr, texture_t *text)
{
    sfFloatRect cre_pos = SFS_GGB(spr->credit_spr);
    if (SFM_GPRW(window->window_hub).x >= cre_pos.left &&
        SFM_GPRW(window->window_hub).x <= cre_pos.left + 213
        && SFM_GPRW(window->window_hub).y >= cre_pos.top &&
        SFM_GPRW(window->window_hub).y <= cre_pos.top + 165)
        {
            credit(window, text, spr);
        }
}

void close_credit_pos(window_cre_t *window, sprite_t *spr, texture_t *text)
{
    sfFloatRect close_cre_pos = SFS_GGB(spr->close_credit_spr);
    if (SFM_GPRW(window->window_credit).x >= close_cre_pos.left &&
        SFM_GPRW(window->window_credit).x <= close_cre_pos.left + 51
        && SFM_GPRW(window->window_credit).y >= close_cre_pos.top &&
        SFM_GPRW(window->window_credit).y <= close_cre_pos.top + 51)
        {
            sfRenderWindow_close(window->window_credit);
        }
}

void play_b_pos(window_cre_t *window, sprite_t *spr, texture_t *text,
    clck_t *temp)
{
    sfFloatRect play_pos = SFS_GGB(spr->play_spr);
    if (SFM_GPRW(window->window_hub).x >= play_pos.left &&
        SFM_GPRW(window->window_hub).x <= play_pos.left + 249
        && SFM_GPRW(window->window_hub).y >= play_pos.top &&
        SFM_GPRW(window->window_hub).y <= play_pos.top + 136)
        {
            sfRenderWindow_close(window->window_hub);
            game(window, text, spr, temp);
        }
}