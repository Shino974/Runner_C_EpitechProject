/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** int_to_char.c
*/

#include "../include/my_runner.h"

char *itch(int nb, char *str)
{
    int i = 0;
    int temp = 0;
    int div = 10;
    int mall = 1;

    while (nb / div != 0) {
        div *= 10;
        mall++;
    }
    str = malloc(sizeof(char) * (mall + 1));
    div /= 10;
    while (div != 0) {
        temp = nb / div;
        nb = nb % div;
        div /= 10;
        str[i] = (temp) + 48;
        i++;
    }
    str[i] = '\0';
    return str;
}