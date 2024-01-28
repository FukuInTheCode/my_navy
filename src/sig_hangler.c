/*
** EPITECH PROJECT, 2024
** sig_hangler.c
** File description:
** sig_hangler.c
*/

#include "my.h"

static int connect_players(player_t *player, gid_t pid)
{
    if (player->enemy_pid == -1) {
        player->enemy_pid = pid;
        player->wstatus = WAITING_USER;
        kill(pid, SIGUSR2);
        return 0;
    }
    if (pid == player->enemy_pid)
        player->wstatus = WAITING_MOVE;
    return 0;
}

void sig_handler(int sig, siginfo_t *info, void *context)
{
    player_t *player = player_stock(GET, NULL);

    if (!player)
        return 0;
    if (player->wstatus == WAITING_PLAYER)
        return connect_players(player, info->si_pid);
    return 0;
}
