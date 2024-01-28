/*
** EPITECH PROJECT, 2024
** sig_hangler.c
** File description:
** sig_hangler.c
*/

#include "my.h"

static void connect_player_one(player_t *player, gid_t pid)
{
    if (player->enemy_pid == -1)
        player->enemy_pid = pid;
    player->wstatus = WAITING_USER;
    usleep(10000);
    kill(pid, SIGUSR2);
    return;
}

static void connect_player_two(player_t *player, gid_t pid)
{
    if (pid != player->enemy_pid)
        return;
    player->wstatus = WAITING_MOVE;
    return;
}

void sig_handler(int sig, siginfo_t *info, void *context)
{
    player_t *player = player_stock(GET, NULL);

    if (!player)
        return;
    if (player->wstatus == WAITING_PLAYER2)
        return connect_player_one(player, info->si_pid);
    if (player->wstatus == WAITING_PLAYER1)
        return connect_player_two(player, info->si_pid);
    if (player->wstatus != WAITING_USER && player->wstatus != WAITING_MOVE)
        return;
    player->response = player->response;
    player->response |= (sig == SIGUSR2) << player->bit_count;
    player->bit_count++;
}
