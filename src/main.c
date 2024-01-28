/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main.c
*/

#include "my.h"

int main(int argc, char **argv, char **envp)
{
    if (argc == 2)
        return init_creating_player(argv[1]);
    if (argc == 3)
        return init_joining_player(argv[1], argv[2]);
    return 84;
}
