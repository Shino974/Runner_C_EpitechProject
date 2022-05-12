/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_credit.c
*/

#include "../include/my_runner.h"

void create_text_credit(texture_t *text, sprite_t *spr)
{
    text->rules_text = SFT_CFF("./ressources/Images/Rules.png", NULL);
    text->close_credit_text = SFT_CFF("./ressources/Images/close_cre.png",
        NULL);
    spr->rules_spr = SFS_C();
    spr->close_credit_spr = SFS_C();
    sfSprite_scale(spr->close_credit_spr, (sfVector2f){0.10,0.10});
    SFS_ST(spr->rules_spr, text->rules_text, sfTrue);
    SFS_ST(spr->close_credit_spr, text->close_credit_text, sfTrue);
}

void display_credit(window_cre_t *window, sprite_t *spr)
{
    SFRW_C(window->window_credit, sfBlack);
    SFRW_DS(window->window_credit, spr->rules_spr, NULL);
    SFRW_DS(window->window_credit, spr->close_credit_spr, NULL);
    sfSprite_setPosition(spr->close_credit_spr, pos_close_credit);
    SFRW_DIS(window->window_credit);
}

void destroy_credit(window_cre_t *window, sprite_t *spr)
{
    SFS_D(spr->rules_spr);
    SFS_D(spr->close_credit_spr);
    SFRW_DES(window->window_credit);
}