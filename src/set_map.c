/*
** EPITECH PROJECT, 2024
** set_map.c
** File description:
** set_map.c
*/

#include "my.h"

int set_map(int x, int y, char *player_map, char c)
{
    int i = 38 + x * 2 + y * 18;

    if (i > my_strlen(player_map))
        return 84;
    printf("%c -> %c | %c\n", player_map[i], player_map[x * 2 + 2], player_map[y * 18 + 36]);
    player_map[i] = c;
    return 0;
}
