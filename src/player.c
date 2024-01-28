/*
** EPITECH PROJECT, 2024
** bit_handler.c
** File description:
** bit_handler.c
*/

#include "my.h"

player_t *player_stock(op_t op, player_t *player)
{
    static player_t *ply = NULL;

    if (op == SAVE)
        ply = player;
    return ply;
}
