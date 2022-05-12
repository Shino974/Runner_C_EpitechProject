/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_parallax.c
*/

#include "../include/my_runner.h"

void anime_background(sprite_t *spr, texture_t *text)
{
    sfIntRect rect2;

    rect2 = sfSprite_getTextureRect(spr->background_spr);
    rect2.left += 2;
    sfSprite_setTextureRect(spr->background_spr, rect2);
}

void anime_preground(sprite_t *spr, texture_t *text)
{
    sfIntRect rect2;

    rect2 = sfSprite_getTextureRect(spr->pregroud_spr);
    rect2.left += 3;
    sfSprite_setTextureRect(spr->pregroud_spr, rect2);
}

void anime_ground(sprite_t *spr, texture_t *text)
{
    sfIntRect rect2;

    rect2 = sfSprite_getTextureRect(spr->ground_spr);
    rect2.left += 3;
    sfSprite_setTextureRect(spr->ground_spr, rect2);
}

void anime_sky(sprite_t *spr, texture_t *text)
{
    sfIntRect rect2;

    rect2 = sfSprite_getTextureRect(spr->sky_spr);
    rect2.left += 1;
    sfSprite_setTextureRect(spr->sky_spr, rect2);
}

void anim_all(sprite_t *spr, texture_t *text)
{
    anime_background(spr, text);
    anime_preground(spr, text);
    anime_ground(spr, text);
    anime_sky(spr, text);
}