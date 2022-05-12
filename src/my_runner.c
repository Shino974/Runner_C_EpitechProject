/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_runner.c
*/

#include "../include/my_runner.h"

int main(int argc, char **argv)
{
    window_cre_t *window = malloc(sizeof(window_cre_t));
    texture_t *text = malloc(sizeof(texture_t));
    sprite_t *spr = malloc(sizeof(sprite_t));
    clck_t *temp = malloc(sizeof(clck_t));

    if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'h'
        && argv[1][2] == '\0') {
        credit(window, text, spr);
    } else {
        hub(window, text, spr, temp);
    }
    return 0;
}