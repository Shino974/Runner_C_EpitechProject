/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_move.c
*/

#include "../include/my_runner.h"

void ani(clck_t temp, sprite_t *spr, window_cre_t *window)
{
    sfTime time = sfClock_getElapsedTime(temp.clock);

    gravity(spr);
    line_among(window, spr);
    if (sfTime_asMilliseconds(time) >= 50) {
        spr->among_rect.left += 33;
        spr->unicorn_rect.left -= spr->unicorn_rect.width;
        if (spr->unicorn_rect.left <= 0)
            spr->unicorn_rect.left = 1557 - 173;
        if (spr->among_rect.left > 129)
            spr->among_rect.left = 0;
        sfSprite_setTextureRect(spr->unicorn_spr, spr->unicorn_rect);
        sfSprite_setTextureRect(spr->enemis_spr, spr->among_rect);
        sfClock_restart(temp.clock);
    }
}