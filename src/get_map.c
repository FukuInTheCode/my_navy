/*
** EPITECH PROJECT, 2024
** set_map.c
** File description:
** set_map.c
*/

#include "my.h"

char get_map(int x, int y, char *player_map)
{
    int i = 38 + x * 2 + y * 18;

    if (i > my_strlen(player_map))
        return 0;
    return player_map[i];
}
