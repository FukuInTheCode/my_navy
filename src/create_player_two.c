/*
** EPITECH PROJECT, 2024
** create_player_one.c
** File description:
** create_player_one.c
*/

#include "my.h"

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
    player_t player = {WAITING_PLAYER, player_map, getpid(),
        handle_gid_s(pid_s), 0, 0};

    if (!fd || !player_map || !player.enemy_pid)
        return 84;
    if (handle_arg(fd, player_map))
        error |= 84;
    if (!error) {
        error |= game_loop(&player);
    }
    free(player_map);
    fclose(fd);
    return error;
}
