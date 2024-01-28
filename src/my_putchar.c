/*
** EPITECH PROJECT, 2024
** my_putchar.c
** File description:
** my_putchar.c
*/

#include "my.h"

int my_putchar(char c)
{
    return write(1, &c, 1);
}
