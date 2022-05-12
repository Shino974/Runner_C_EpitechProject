/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_music.c
*/

#include "../include/my_runner.h"

void game_music(sprite_t *spr)
{
    spr->music2 = sfMusic_createFromFile("./ressources/Audio/music2.ogg");
    sfMusic_setVolume(spr->music2, 100);
    sfMusic_play(spr->music2);
    sfMusic_setLoop(spr->music2, sfTrue);
}