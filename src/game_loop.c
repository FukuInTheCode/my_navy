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
    write(1, "\n", 1);
    return 0;
}

static int get_response(player_t *player, char *enemy_map, char *resp_buf)
{
    return 0;
}

static int get_usr_move(player_t *player, char *enemy_map, uint32_t turn_count)
{
    char resp_buf[100001] = {0};

    write(1, "attack: ", 8) && read(0, resp_buf, 1000) && write(1, "\n", 1);
    write(1, "result: ", 8);
    if (my_strlen(resp_buf) != 3 &&
        !get_map(*resp_buf - 'A', resp_buf[1] - '1', enemy_map)){
        memset((void *)resp_buf, 0, my_strlen(resp_buf));
        write(1, "wrong position\n\n", 16);
        return get_usr_move(player, enemy_map, turn_count);
    }
    resp_buf[2] = ':';
    write(1, resp_buf, 3);
    get_response(player, enemy_map, resp_buf);
    write(1, "\n\n", 2);
    turn_count++;
    !(turn_count % 2) && print_boards(player->player_map, enemy_map);
    player->wstatus = WAITING_MOVE;
    return get_enemy_move(player, enemy_map, turn_count);
}

int get_enemy_move(player_t *player, char *enemy_map, uint32_t turn_count)
{
    write(1, "waiting for enemy's attack...\n\n", 31);
    player->bit_count = 0;
    for (player->response = 0; player->bit_count < 8;);
    write(1, "result: ", 8);
    my_put_nbr(player->response);
    write(1, "\n\n", 2);
    turn_count++;
    !(turn_count % 2) && print_boards(player->player_map, enemy_map);
    player->wstatus = WAITING_USER;
    return get_usr_move(player, enemy_map, turn_count);
}

static int handle_player_one(player_t *player, char *enemy_map)
{
    if (player->wstatus != WAITING_PLAYER2)
        return 0;
    for (write(1, "waiting for enemy...\n\n", 23)
        ; player->wstatus == WAITING_PLAYER2;);
    write(1, "enemy connected\n\n", 17);
    print_boards(player->player_map, enemy_map);
    return 0;
}

int game_loop(player_t *player)
{
    int error = print_pid(player->pid);
    char *enemy_map = my_strdup(map_template);
    uint32_t turn_count = 0;

    if (!enemy_map)
        return 84;
    player_stock(SAVE, player);
    handle_player_one(player, enemy_map);
    for (; player->wstatus == WAITING_PLAYER1;);
    if (player->wstatus == WAITING_USER)
        error |= get_usr_move(player, enemy_map, turn_count);
    if (player->wstatus == WAITING_MOVE) {
        write(1, "successfully connected to enemy\n\n", 33);
        print_boards(player->player_map, enemy_map);
        error |= get_enemy_move(player, enemy_map, turn_count);
    }
    free(enemy_map);
    return error;
}
