/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_hub.c
*/

#include "../include/my_runner.h"

void create_text_hub(texture_t *text, sprite_t *spr)
{
    text->back_hub_text = SFT_CFF("./ressources/Images/unicorn.png", NULL);
    text->title_game_text = SFT_CFF("./ressources/Images/Title.png", NULL);
    text->play_text = SFT_CFF("./ressources/Images/play_b.png", NULL);
    text->credit_text = SFT_CFF("./ressources/Images/credit.png", NULL);
    spr->back_hub_spr = SFS_C();
    spr->title_game_spr = SFS_C();
    spr->play_spr = SFS_C();
    spr->credit_spr = SFS_C();
    SFS_ST(spr->back_hub_spr, text->back_hub_text, sfTrue);
    SFS_ST(spr->title_game_spr, text->title_game_text, sfTrue);
    SFS_ST(spr->play_spr, text->play_text, sfTrue);
    SFS_ST(spr->credit_spr, text->credit_text, sfTrue);
}

void display_hub(window_cre_t *window, sprite_t *spr)
{
    SFRW_C(window->window_hub, sfBlack);
    SFRW_DS(window->window_hub, spr->back_hub_spr, NULL);
    SFRW_DS(window->window_hub, spr->title_game_spr, NULL);
    SFRW_DS(window->window_hub, spr->play_spr, NULL);
    SFRW_DS(window->window_hub, spr->credit_spr, NULL);
    sfSprite_setPosition(spr->play_spr, pos_play);
    sfSprite_setPosition(spr->credit_spr, pos_credit);
    SFRW_DIS(window->window_hub);
}

void destroy_hub(window_cre_t *window, sprite_t *spr)
{
    SFS_D(spr->back_hub_spr);
    SFS_D(spr->title_game_spr);
    SFS_D(spr->play_spr);
    SFS_D(spr->credit_spr);
    SFRW_DES(window->window_hub);
}