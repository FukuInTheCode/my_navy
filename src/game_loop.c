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

static int print_boards(char *player_map, char *enemy_map)
{
    write(1, "my navy:\n", 9);
    write(1, player_map, my_strlen(player_map));
    write(1, "\nenemy navy:\n", 13);
    write(1, enemy_map, my_strlen(enemy_map));
    return 0;
}

static int get_usr_move(player_t *player, char *enemy_map)
{
    char resp_buf[1001] = {0};

    print_boards(player->player_map, enemy_map);
    read(0, resp_buf, 1000);
    printf("%s\n", resp_buf);
    return 0;
}

int get_enemy_move(player_t *player, char *enemy_map)
{
    player->bit_count = 0;
    for (player->response = 0; player->bit_count < 8;);
    printf("%d\n", player->response);
    return 0;
}

int game_loop(player_t *player)
{
    int error = print_pid(player->pid);
    char *enemy_map = my_strdup(map_template);

    if (!enemy_map)
        return 84;
    player_stock(SAVE, player);
    for (write(1, "waiting for enemy...\n\n", 22);
        player->wstatus == WAITING_PLAYER;);
    write(1, "enemy connected\n\n", 17);
    if (player->wstatus == WAITING_USER)
        error |= get_usr_move(player, enemy_map);
    for (; player->wstatus == WAITING_CONF;);
    if (player->wstatus == WAITING_MOVE) {
        write(1, "successfully connected to enemy\n", 32);
        error |= get_enemy_move(player, enemy_map);
    }
    free(enemy_map);
    return error;
}
