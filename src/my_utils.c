/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_jump.c
*/

#include "../include/my_runner.h"

void jump(texture_t *text, sprite_t *spr)
{
    sfVector2f gravity_limit = sfSprite_getPosition(spr->unicorn_spr);
    static int jump = 0;

    if (gravity_limit.y == 860 && jump == 0 &&
        sfKeyboard_isKeyPressed(sfKeySpace))
        jump = 30;
    if (jump >= 1)
        sfSprite_move(spr->unicorn_spr, (sfVector2f){0, (-1) * jump--});
    else
        jump = 0;
}

void gravity(sprite_t *spr)
{
    sfVector2f gravity_unicorn = sfSprite_getPosition(spr->unicorn_spr);

    if (gravity_unicorn.y < 860)
        sfSprite_move(spr->unicorn_spr, (sfVector2f){0, 8});
    else {
        sfSprite_setPosition(spr->unicorn_spr, (sfVector2f){0, 860});
    }
}

void collision(sprite_t *spr, window_cre_t *window)
{
    sfFloatRect zbeub = sfSprite_getGlobalBounds(spr->enemis_spr);
    sfFloatRect zbeub2 = sfSprite_getGlobalBounds(spr->unicorn_spr);

    if (sfFloatRect_intersects(&zbeub, &zbeub2, NULL)) {
        window->collision = 1;
    }
}