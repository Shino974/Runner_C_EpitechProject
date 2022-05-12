/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_game.c
*/

#include "../include/my_runner.h"

void create_text_2(texture_t *text, sprite_t *spr)
{
    text->unicorn_text = SFT_CFF("./ressources/Images/First.png", NULL);
    text->enemis_text = SFT_CFF("./ressources/Images/among_us.png", NULL);
    text->preground_text = SFT_CFF("./ressources/Images/1.png", NULL);
    text->ground_text = SFT_CFF("./ressources/Images/2.png", NULL);
    text->background_text = SFT_CFF("./ressources/Images/3.png", NULL);
    text->sky_text = SFT_CFF("./ressources/Images/4.png", NULL);
    text->sky2_text = SFT_CFF("./ressources/Images/5.png", NULL);
    spr->unicorn_spr = SFS_C();
    spr->enemis_spr = SFS_C();
    spr->pregroud_spr = SFS_C();
    spr->ground_spr = SFS_C();
    spr->background_spr = SFS_C();
    spr->sky_spr = SFS_C();
    spr->sky2_spr = SFS_C();
}

void create_text_3(texture_t *text, sprite_t *spr)
{
    SFS_ST(spr->unicorn_spr, text->unicorn_text, sfTrue);
    SFS_ST(spr->enemis_spr, text->enemis_text, sfTrue);
    SFS_ST(spr->pregroud_spr, text->preground_text, sfTrue);
    SFS_ST(spr->ground_spr, text->ground_text, sfTrue);
    SFS_ST(spr->background_spr, text->background_text, sfTrue);
    SFS_ST(spr->sky_spr, text->sky_text, sfTrue);
    SFS_ST(spr->sky2_spr, text->sky2_text, sfTrue);
}

void create_text_game(texture_t *text, sprite_t *spr, clck_t *temp)
{
    sfIntRect rect = {1557 - 173, 0, 173, 97};

    temp->clock = sfClock_create();
    temp->time = sfClock_getElapsedTime(temp->clock);
    create_text_2(text, spr);
    create_text_3(text, spr);
    SFT_SR(text->sky_text, sfTrue);
    SFT_SR(text->ground_text, sfTrue);
    SFT_SR(text->background_text, sfTrue);
    SFT_SR(text->preground_text, sfTrue);
    sfSprite_scale(spr->unicorn_spr, (sfVector2f){1.5,1.5});
    sfSprite_scale(spr->enemis_spr, (sfVector2f){3,3});
    sfSprite_setPosition(spr->enemis_spr, pos_enemis);
    sfSprite_setPosition(spr->unicorn_spr, pos_unicorn);
    create_font(text);
    game_music(spr);
}

void display_game(window_cre_t *window, sprite_t *spr, texture_t *text,
    clck_t *temp)
{
    SFRW_C(window->window_game, sfBlack);
    SFRW_DS(window->window_game, spr->sky2_spr, NULL);
    SFRW_DS(window->window_game, spr->sky_spr, NULL);
    SFRW_DS(window->window_game, spr->background_spr, NULL);
    SFRW_DS(window->window_game, spr->ground_spr, NULL);
    SFRW_DS(window->window_game, spr->pregroud_spr, NULL);
    SFRW_DS(window->window_game, spr->unicorn_spr, NULL);
    SFRW_DS(window->window_game, spr->enemis_spr, NULL);
    display_font(window, text);
    jump(text, spr);
    anim_all(spr, text);
    SFRW_DIS(window->window_game);
}

void destroy_game(window_cre_t *window, sprite_t *spr, texture_t *text,
    clck_t *temp)
{
    SFS_D(spr->unicorn_spr);
    SFS_D(spr->enemis_spr);
    SFS_D(spr->ground_spr);
    SFS_D(spr->background_spr);
    SFS_D(spr->sky_spr);
    SFS_D(spr->pregroud_spr);
    SFS_D(spr->sky2_spr);
    sfMusic_destroy(spr->music2);
    destroy_font(text);
    SFRW_DES(window->window_game);
    sfClock_destroy(temp->clock);
}