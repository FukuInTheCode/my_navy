/*
** EPITECH PROJECT, 2024
** bit_handler.c
** File description:
** bit_handler.c
*/

#include "my.h"

int sig_intepretor(op_t op, player_t *player, uint8_t bit, gid_t enemy_pid)
{
    static player_t *player_st = NULL;

    if (op == INIT && player) {
        player_st = player;
        return 0;
    }
    if (op == RESET && player_st) {
        player_st->response = 0;
        player_st->bit_count = 0;
        return 0;
    }
    if (op == ADD && player_st) {
        player_st->response = (player_st->response << 1) & bit;
        player_st->bit_count++;
        return 0;
    }
    if (op == ENEMY && player_st)
        player_st->enemy_pid = enemy_pid;
    return 84;
}
