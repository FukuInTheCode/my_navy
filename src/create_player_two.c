/*
** EPITECH PROJECT, 2024
** create_player_one.c
** File description:
** create_player_one.c
*/

#include "my.h"
#include <signal.h>

static gid_t handle_gid_s(char *pid_s)
{
    for (int i = 0; pid_s[i]; i++)
        if (!('0' <= pid_s[i] && pid_s[i] <= '9'))
            return 0;
    return my_getnbr(pid_s);
}

int create_joining_player(char *pid_s, char *file_path)
{
    FILE *fd = fopen(file_path, "r");
    char *player_map = my_strdup(map_template);
    int error = 0;
    player_t player = {WAITING_PLAYER1, player_map, getpid(),
        handle_gid_s(pid_s), 0, 0};
    struct sigaction sa = {.sa_sigaction = sig_handler, .sa_flags = SIGIN};

    if (!fd || !player_map || !player.enemy_pid)
        return 84;
    if (handle_arg(fd, player_map))
        error |= 84;
    if (!error) {
        sigemptyset(&sa.sa_mask);
        run_sig(&sa) | 1 && kill(player.enemy_pid, SIGUSR1);
        error |= game_loop(&player);
    }
    free(player_map);
    fclose(fd);
    return error;
}
