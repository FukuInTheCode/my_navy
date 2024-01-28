/*
** EPITECH PROJECT, 2024
** create_player_one.c
** File description:
** create_player_one.c
*/

#include "my.h"

int create_creating_player(char *file_path)
{
    FILE *fd = fopen(file_path, "r");
    char *player_map = my_strdup(map_template);
    int error = 0;
    player_t player = {WAITING_PLAYER2, player_map, getpid(), -1, 0, 0};
    struct sigaction sa = {.sa_sigaction = sig_handler, .sa_flags = SIGIN};

    if (!fd || !player_map)
        return 84;
    if (handle_arg(fd, player_map))
        error |= 84;
    if (!error) {
        sigemptyset(&sa.sa_mask);
        run_sig(&sa);
        error |= game_loop(&player);
    }
    free(player_map);
    fclose(fd);
    return error;
}
