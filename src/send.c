/*
** EPITECH PROJECT, 2024
** send.c
** File description:
** send.c
*/

#include "my.h"
#include <unistd.h>

int send_resp(gid_t pid, int response)
{
    uint8_t bit = 0;

    usleep(1e4);
    for (int i = 0; i < 32; i++) {
        bit = response & (1 << i);
        kill(pid, bit != 0 ? SIGUSR2 : SIGUSR1);
        usleep(1000);
    }
    return 0;
}
