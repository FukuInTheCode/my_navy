/*
** EPITECH PROJECT, 2024
** game_loop.c
** File description:
** game_loop.c
*/

#include "my.h"

static int print_pid(gid_t pid)
{
    int error = 0;

    error |= 84 * (0 > write(1, "my_pid: ", 8));
    error |= my_put_nbr(pid);
    error |= 84 * (0 > write(1, "\n\n", 2));
    return error;
}

int game_loop(player_t *player)
{
    int error = print_pid(player->pid);

    sig_interpretor(INIT, player, 0);
    return error;
}
