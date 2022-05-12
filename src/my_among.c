/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_hub.c
*/

#include "../include/my_runner.h"

void line_among(window_cre_t *window, sprite_t *spr)
{
    sfVector2f enemis = sfSprite_getPosition(spr->enemis_spr);

    sfSprite_move(spr->enemis_spr, (sfVector2f){-10, 0});
    if (enemis.x < -40) {
        sfSprite_setPosition(spr->enemis_spr, (sfVector2f){1900, 900});
    }
}